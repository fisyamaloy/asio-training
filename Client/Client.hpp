#include <Network/Common.hpp>

#include "Network/Connection.hpp"
#include "Network/Message.hpp"
#include "Network/SafeQueue.hpp"

using SafeQueue = Network::SafeQueue<Network::Message>;

class Client
{
public:
    Client() : socket(service) {}

    virtual ~Client() { disconnect(); }

    bool connect(const std::string& host, const uint16_t port)
    {
        try
        {
            boost::asio::ip::tcp::resolver resolver(service);
            boost::asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(host, std::to_string(port));

            connection = std::make_unique<Network::Connection>(Network::Connection::OwnerType::CLIENT, service,
                                                               boost::asio::ip::tcp::socket(service), _qMessagesIn);
            connection->connectToServer(endpoints);
            serviceThread = std::thread([this]() { service.run(); });

            return true;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Client exception: " << e.what() << std::endl;
            return false;
        }
    }

    void disconnect()
    {
        if (isConnected())
        {
            connection->disconnect();
        }

        service.stop();
        if (serviceThread.joinable())
        {
            serviceThread.join();
        }

        connection.release();
    }

    bool isConnected() const
    {
        if (connection)
        {
            return connection->isConnected();
        }

        return false;
    }

    inline SafeQueue& getIncomingMessages() { return _qMessagesIn; }

    void send(const Network::Message& msg) { connection->send(msg); }

protected:
    boost::asio::io_service service;
    std::thread serviceThread;

    // Socket which is connected to a server.
    boost::asio::ip::tcp::socket socket;

    // It handles data transfer
    std::unique_ptr<Network::Connection> connection;

private:
    // Queue of incoming messages from server
    SafeQueue _qMessagesIn;
};

class CustomClient : public Client
{
public:
    void registerUser(const std::string& email, const std::string& userName, const std::string& password)
    {
        Network::Message msg;
        msg.header.id = Network::MessageType::LoginRequest;
        msg << email << userName << password;
        send(msg);
    }
};
