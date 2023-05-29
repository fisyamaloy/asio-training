#include <Network/Message.hpp>
#include <optional>

struct IRequestHandler
{
    virtual std::shared_ptr<IRequestHandler> setNextHandler(std::shared_ptr<IRequestHandler> next) = 0;
    virtual std::optional<Network::Message> handle(const Network::Message& msg)                    = 0;
};

class AbstractRequestHandler : public IRequestHandler
{
public:
    AbstractRequestHandler() : nextHandler(nullptr) {}

    std::shared_ptr<IRequestHandler> setNextHandler(std::shared_ptr<IRequestHandler> handler) override
    {
        nextHandler = handler;
        return nextHandler;
    }

    std::optional<Network::Message> handle(const Network::Message& msg) override
    {
        if (nextHandler)
        {
            return nextHandler->handle(msg);
        }

        return std::nullopt;
    }

private:
    std::shared_ptr<IRequestHandler> nextHandler;
};

class RegistrationRequestHandler : public AbstractRequestHandler
{
    std::optional<Network::Message> handle(const Network::Message& msg) override
    {
        if (msg.header.id == Network::MessageType::RegistrationRequest)
        {
            Network::Message msgAnswer;
            msgAnswer.header.id = Network::MessageType::RegistrationAnswer;
            // logic ...
            return msgAnswer;
        }
        else
        {
            return AbstractRequestHandler::handle(msg);
        }
    }
};

class LoginRequestHandler : public AbstractRequestHandler
{
    std::optional<Network::Message> handle(const Network::Message& msg) override
    {
        if (msg.header.id == Network::MessageType::LoginRequest)
        {
            Network::Message msgAnswer;
            msgAnswer.header.id = Network::MessageType::LoginAnswer;
            // logic ...
            return msgAnswer;
        }
        else
        {
            return AbstractRequestHandler::handle(msg);
        }
    }
};

class MessageStoreRequestHandler : public AbstractRequestHandler
{
    std::optional<Network::Message> handle(const Network::Message& msg) override
    {
        if (msg.header.id == Network::MessageType::MessageStoreRequest)
        {
            Network::Message msgAnswer;
            msgAnswer.header.id = Network::MessageType::MessageStoreAnswer;
            // logic ...
            return msgAnswer;
        }
        else
        {
            return AbstractRequestHandler::handle(msg);
        }
    }
};
