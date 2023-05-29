#pragma once
#include "Common.hpp"
#include "Message.hpp"
#include "SafeQueue.hpp"

namespace Network
{

class Connection : public std::enable_shared_from_this<Connection>
{
public:
    enum class OwnerType : uint8_t
    {
        SERVER,
        CLIENT,
    };

public:
    Connection(OwnerType parent, boost::asio::io_service& service, boost::asio::ip::tcp::socket socket, SafeQueue<Message>& qIn)
        : service(service), socket(std::move(socket)), qMessagesIn(qIn)
    {
        owner = parent;
    }

    virtual ~Connection() {}

    void connectToClient(uint32_t uid = 0)
    {
        if (owner == OwnerType::SERVER)
        {
            if (socket.is_open())
            {
                id = uid;
                asyncReadHeader();
            }
        }
    }
    void connectToServer(const boost::asio::ip::tcp::resolver::results_type& endpoints)
    {
        if (owner == OwnerType::CLIENT)
        {
            boost::asio::async_connect(socket, endpoints, [this](std::error_code ec, [[maybe_unused]] boost::asio::ip::tcp::endpoint ep) {
                if (!ec)
                {
                    asyncWriteHeader();
                }
            });
        }
    }

    void disconnect()
    {
        if (isConnected())
        {
            boost::asio::post([this]() { socket.close(); });
        }
    }
    
    bool isConnected() const { return socket.is_open(); }

    void send(const Message& msg)
    {
        boost::asio::post(service, [this, &msg] {
            bool writingMessage = !qMessagesOut.empty();
            qMessagesOut.push_back(msg);
            if (!writingMessage)
            {
                asyncWriteHeader();
            }
        });
    }

    inline uint32_t getID() const { return id; }

private:
    void asyncReadHeader()
    {
        boost::asio::async_read(socket, boost::asio::buffer(&tempMsg.header, sizeof(MessageHeader)),
                                [this](std::error_code ec, [[maybe_unused]] std::size_t length) {
                                    if (!ec)
                                    {
                                        if (tempMsg.header.size > 0)
                                        {
                                            tempMsg.body.resize(tempMsg.header.size);
                                            asyncReadBody();
                                        }
                                        else
                                        {
                                            addToIncomingMessageQueue();
                                        }
                                    }
                                    else
                                    {
                                        std::cerr << "[" << id << "]"
                                                  << " Read Header Fail\n";
                                        socket.close();
                                    }
                                });
    }

    void asyncReadBody()
    {
        boost::asio::async_read(socket, boost::asio::buffer(tempMsg.body.data(), tempMsg.body.size()),
                                [this](std::error_code ec, [[maybe_unused]] std::size_t length) {
                                    if (!ec)
                                    {
                                        addToIncomingMessageQueue();
                                    }
                                    else
                                    {
                                        std::cerr << "[" << id << "]"
                                                  << " Read Body Fail\n";
                                        socket.close();
                                    }
                                });
    }

    void asyncWriteHeader()
    {
        boost::asio::async_write(socket, boost::asio::buffer(&qMessagesOut.front().header, sizeof(MessageHeader)),
                                 [this](std::error_code ec, [[maybe_unused]] std::size_t length) {
                                     if (!ec)
                                     {
                                         if (qMessagesOut.front().body.size() > 0)
                                         {
                                             asyncWriteBody();
                                         }
                                         else
                                         {
                                             qMessagesOut.pop_front();

                                             if (!qMessagesOut.empty())
                                             {
                                                 asyncWriteHeader();
                                             }
                                         }
                                     }
                                     else
                                     {
                                         std::cerr << "[" << id << "]"
                                                   << " Write Header Fail\n";
                                         socket.close();
                                     }
                                 });
    }

    void asyncWriteBody()
    {
        boost::asio::async_write(socket, boost::asio::buffer(qMessagesOut.front().body.data(), qMessagesOut.front().body.size()),
                                 [this](std::error_code ec, [[maybe_unused]] std::size_t length) {
                                     if (!ec)
                                     {
                                         qMessagesOut.pop_front();
                                         if (!qMessagesOut.empty())
                                         {
                                             asyncWriteHeader();
                                         }
                                     }
                                     else
                                     {
                                         std::cerr << "[" << id << "]"
                                                   << " Write Body Fail\n";
                                         socket.close();
                                     }
                                 });
    }

    void addToIncomingMessageQueue()
    {
        if (owner == OwnerType::SERVER)
        {
            tempMsg.remote = this->shared_from_this();
            qMessagesIn.push_back(tempMsg);
        }
        else
        {
            qMessagesIn.push_back(tempMsg);
        }

        asyncReadHeader();
    }

protected:
    boost::asio::io_service& service;
    boost::asio::ip::tcp::socket socket;

    // It holds all messages to be sentto the remote side of this connection
    SafeQueue<Message> qMessagesOut;

    // It holds all messages that have been recieved from the remote side of this connection.
    // This queue is owned by server or a client and expected to be provided by the server either client.
    SafeQueue<Message>& qMessagesIn;

    // Buffer to store the part of incoming message while it is read
    Message tempMsg;

    OwnerType owner = OwnerType::SERVER;
    uint32_t id     = 0;
};

}  // namespace Network
