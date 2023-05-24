#include <ostream>

#include "Common.hpp"

namespace Network
{
enum class MessageType : std::uint8_t
{
    ServerAcceptRequst,
    ServerAcceptAnswer,

    LoginRequest,
    LoginAnswer,

};

struct MessageHeader
{
    MessageType id;
    uint32_t size = 0u;  // std::size_t size = 0u; // TODO: Investigate if std::size_t is the same on x32 and x64 systems
};

class Message
{
public:
    MessageHeader header;
    std::vector<uint8_t> body;

    // returns size of the whole message packet in bytes
    size_t getSize() const { return sizeof(MessageHeader) + body.size(); }

    friend std::ostream& operator<<(std::ostream& os, const Message& msg)
    {
        os << "ID:" << (static_cast<int>(msg.header.id)) << " Size: " << msg.getSize() << " bytes";
        return os;
    }

    // Pushes any POD-like data into the message object
    template <class DataType>
    friend Message& operator<<(Message& msg, const DataType& data)
    {
        static_assert(std::is_standard_layout<DataType>::value,
                      "Data is not trivially copyable to be pushed into the Message. Use POD-type of data");

        const size_t offset = msg.body.size();
        msg.body.resize(offset + sizeof(DataType));
        memcpy(msg.body.data() + offset, &data, sizeof(DataType));
        msg.header.size = msg.getSize();

        return msg;
    }

    // Retrieves the data from Message in the back order of pushing
    template <class DataType>
    friend Message& operator>>(Message& msg, DataType& data)
    {
        static_assert(std::is_standard_layout<DataType>::value,
                      "Data is not trivially copyable to be retrieved from the Message. Use POD-type of data");

        const size_t offset = msg.body.size() - sizeof(DataType);
        msg.body.resize(offset + sizeof(DataType));
        memcpy(&data, msg.body.data() + offset, sizeof(DataType));
        msg.body.resize(offset);
        msg.header.size = msg.getSize();

        return msg;
    }
};
}  // namespace Network
