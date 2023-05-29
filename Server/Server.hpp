#pragma once
#include <Network/Common.hpp>
#include <Network/Connection.hpp>
#include <Network/Message.hpp>
#include <Network/SafeQueue.hpp>
#include <boost/asio.hpp>
#include <memory>

#include "UserRequestHandlers.hpp"

class Server
{
public:
    Server(uint16_t port) : acceptor(service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {}

    virtual ~Server() { stop(); }

    bool start()
    {
        try
        {
            asyncWaitForClientConnection();
            static std::size_t threadsCount = std::thread::hardware_concurrency();
            threadsCount > 1 ? --threadsCount : threadsCount = 1;

            for (size_t i = 0; i < threadsCount; ++i)
            {
                workers.emplace_back(std::thread([this]() { service.run(); }));
            }

            requestHandlers = std::make_shared<RegistrationRequestHandler>();
            requestHandlers->setNextHandler(std::make_shared<LoginRequestHandler>())
                ->setNextHandler(std::make_shared<MessageStoreRequestHandler>());

            std::cout << "[Server] started!\n";
            return true;
        }
        catch (const std::exception& e)
        {
            std::cerr << "[Server] exception: " << e.what() << '\n';
            return false;
        }
    }

    void stop()
    {
        service.stop();

        for (std::thread& worker : workers)
        {
            if (worker.joinable())
            {
                worker.join();
            }
        }
        workers.clear();

        std::cout << "[SERVER] Stopped!\n";
    }

    void asyncWaitForClientConnection()
    {
        acceptor.async_accept([this](std::error_code ec, boost::asio::ip::tcp::socket socket) {
            if (!ec)
            {
                std::cout << "[Server] New Connaction:" << socket.remote_endpoint() << '\n';
                auto newConnection =
                    std::make_shared<Network::Connection>(Network::Connection::OwnerType::SERVER, service, std::move(socket), qMessagesIn);

                if (onClientConnect(newConnection))
                {
                    deqConnections.push_back(std::move(newConnection));

                    deqConnections.back()->connectToClient(nIDClient++);

                    std::cout << "[" << deqConnections.back()->getID() << "] Connection Approved\n";
                }
                else
                {
                    std::cout << "[-----] Connection Denied\n";
                }
            }
            else
            {
                std::cerr << "[Server] New Connaction Error:" << ec.message() << '\n';
            }
        });

        asyncWaitForClientConnection();
    }

    void messageClient(std::shared_ptr<Network::Connection> client, const Network::Message& msg)
    {
        if (client && client->isConnected())
        {
            client->send(msg);
        }
        else
        {
            onClientDisconnect(client);
            client.reset();
            deqConnections.erase(std::remove(deqConnections.begin(), deqConnections.end(), client), deqConnections.end());
        }
    }

    void messageAllClients(const Network::Message& msg, std::shared_ptr<Network::Connection> pIgnoreClient = nullptr)
    {
        bool isInvalidClientExist = false;

        for (auto& client : deqConnections)
        {
            if (client && client->isConnected())
            {
                if (client != pIgnoreClient)
                {
                    client->send(msg);
                }
            }
            else
            {
                onClientDisconnect(client);
                client.reset();
                isInvalidClientExist = true;
            }
        }

        if (isInvalidClientExist)
        {
            deqConnections.erase(std::remove(deqConnections.begin(), deqConnections.end(), nullptr), deqConnections.end());
        }
    }

    void update()
    {
        while (!qMessagesIn.empty())
        {
            auto& msg = qMessagesIn.front();
            onMessage(msg.remote, msg);
        }
    }

    void update(bool wait)
    {
        static constexpr std::size_t criticalMessagesAmount = 200;
        if (wait)
        {
            qMessagesIn.wait();
        }

        if (qMessagesIn.size() > criticalMessagesAmount)
        {
            for (size_t i = 0; i < std::thread::hardware_concurrency(); ++i)
            {
                workers.emplace_back(std::thread([this]() { service.run(); }));
            }
        }

        while (!qMessagesIn.empty())
        {
            auto& msg = qMessagesIn.front();
            onMessage(msg.remote, msg);
        }
    }

protected:
    virtual bool onClientConnect(std::shared_ptr<Network::Connection> client)
    {
        Network::Message message;
        message.header.id = Network::MessageType::ServerAcceptAnswer;
        client->send(message);
        return true;
    }

    virtual void onClientDisconnect(const std::shared_ptr<Network::Connection> client)
    {
        std::cout << "Removing client [" << client->getID() << "]\n";
    }

    virtual void onMessage(std::shared_ptr<Network::Connection> client, const Network::Message& msg)
    {
        auto optMessage = requestHandlers->handle(msg);
        if (optMessage.has_value())
        {
            client->send(optMessage.value());
        }
        else
        {
            std::cerr << "RequestHandler is not found. Add it in Server::start\n";
        }
    }

    // Incoming messages from client
    Network::SafeQueue<Network::Message> qMessagesIn;

    std::deque<std::shared_ptr<Network::Connection>> deqConnections;
    std::deque<std::thread> workers;

    boost::asio::io_service service;

    boost::asio::ip::tcp::acceptor acceptor;

    // All clients have unique ID in a wide system
    uint32_t nIDClient = 10000;

    std::shared_ptr<IRequestHandler> requestHandlers;
};
