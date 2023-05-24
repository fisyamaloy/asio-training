#define CATCH_CONFIG_MAIN
#include <gtest/gtest.h>

#include <Network/Message.hpp>

TEST(MessageSerializationTest, PtimitiveTypes)
{
    Network::Message msg;
    msg.header.id = Network::MessageType::LoginRequest;

    int a         = 1;
    bool b        = false;
    short c       = 3;
    msg << a << b << c;

    int a_1;
    bool b_1;
    short c_1;
    msg >> c_1 >> b_1 >> a_1;

    EXPECT_EQ(a, a_1);
    EXPECT_EQ(b, b_1);
    EXPECT_EQ(c, c_1);
}
