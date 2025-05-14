#include <gtest/gtest.h>
#include "../srcs/Model/Model.hpp"
#include "macro.hpp"

// Test fixture for Model tests
class ModelTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        model = new Model();
    }

    void TearDown() override
    {
        delete model;
    }

    Model *model;
};

// Client management tests
TEST_F(ModelTest, AddClient_Success)
{
    model->addClient(1);
    const Client *client = model->getClient(1);
    ASSERT_NE(client, nullptr);
    EXPECT_EQ(client->getFd(), 1);
    EXPECT_EQ(model->getClientSize(), 1);
}

TEST_F(ModelTest, RemoveClient_Success)
{
    model->addClient(1);
    model->removeClient(1);
    const Client *client = model->getClient(1);
    EXPECT_EQ(client, nullptr);
    EXPECT_EQ(model->getClientSize(), 0);
}

TEST_F(ModelTest, GetClient_NonExistent)
{
    const Client *client = model->getClient(999);
    EXPECT_EQ(client, nullptr);
    EXPECT_EQ(model->getClientSize(), 0);
}

TEST_F(ModelTest, AddMultipleClients)
{
    model->addClient(1);
    model->addClient(2);
    model->addClient(3);
    EXPECT_EQ(model->getClientSize(), 3);
}

// Channel management tests
TEST_F(ModelTest, AddChannel_Success)
{
    model->addChannel("test_channel");
    const Channel *channel = model->getChannel(id_hash("test_channel"));
    ASSERT_NE(channel, nullptr);
    EXPECT_EQ(channel->getName(), "test_channel");
    EXPECT_EQ(model->getChannelSize(), 1);
    EXPECT_EQ(model->countClientsInChannel("test_channel"), 0);
}

TEST_F(ModelTest, GetChannel_NonExistent)
{
    const Channel *channel = model->getChannel(999);
    EXPECT_EQ(channel, nullptr);
    EXPECT_EQ(model->getChannelSize(), 0);
}

TEST_F(ModelTest, GetChannelSize_NonExistent)
{
    EXPECT_EQ(model->countClientsInChannel("non_existent_channel"), 0);
}

TEST_F(ModelTest, AddMultipleChannels)
{
    model->addChannel("channel1");
    model->addChannel("channel2");
    model->addChannel("channel3");
    EXPECT_EQ(model->getChannelSize(), 3);
}

// Hub management tests
TEST_F(ModelTest, AddHub_Success)
{
    model->addClient(1);
    model->addChannel("test_channel");
    model->addHub(1, id_hash("test_channel"), ADMIN);
    EXPECT_EQ(model->countClientsInChannel("test_channel"), 1);
}

TEST_F(ModelTest, AddHub_MultipleClients)
{
    model->addClient(1);
    model->addClient(2);
    model->addChannel("test_channel");

    model->addHub(1, id_hash("test_channel"), ADMIN);
    model->addHub(2, id_hash("test_channel"), MEMBER);

    EXPECT_EQ(model->countClientsInChannel("test_channel"), 2);
    // EXPECT_EQ(model->getH
}

TEST_F(ModelTest, AddHub_NonExistentClient)
{
    model->addChannel("test_channel");
    model->addHub(999, id_hash("test_channel"), ADMIN);
    EXPECT_EQ(model->countClientsInChannel("test_channel"), 1);
}

TEST_F(ModelTest, AddHub_NonExistentChannel)
{
    model->addClient(1);
    model->addHub(1, 999, ADMIN);
    EXPECT_EQ(model->countClientsInChannel("non_existent"), 0);
}

// Pollfd tests
TEST_F(ModelTest, GetPollfds_Empty)
{
    std::vector<pollfd> pollfds = model->getPollfds();
    EXPECT_EQ(pollfds.size(), size_t(0));
}

TEST_F(ModelTest, GetPollfds_WithClients)
{
    model->addClient(1);
    model->addClient(2);

    std::vector<pollfd> pollfds = model->getPollfds();
    ASSERT_EQ(pollfds.size(), size_t(2));

    EXPECT_EQ(pollfds[0].fd, 1);
    EXPECT_EQ(pollfds[1].fd, 2);
    EXPECT_EQ(pollfds[0].events, POLLIN);
    EXPECT_EQ(pollfds[1].events, POLLIN);
}

// Remove operations tests
TEST_F(ModelTest, RemoveClient_ClearsHubs)
{
    model->addClient(1);
    model->addChannel("test_channel");
    model->addHub(1, id_hash("test_channel"), ADMIN);

    model->removeClient(1);
    EXPECT_EQ(model->countClientsInChannel("test_channel"), 0);
    EXPECT_EQ(model->getClientSize(), 0);
}

TEST_F(ModelTest, RemoveChannel_ClearsHubs)
{
    model->addClient(1);
    model->addChannel("test_channel");
    model->addHub(1, id_hash("test_channel"), ADMIN);

    model->removeChannel(id_hash("test_channel"));
    EXPECT_EQ(model->countClientsInChannel("test_channel"), 0);
    EXPECT_EQ(model->getChannelSize(), 0);
}

// Complex scenario tests
TEST_F(ModelTest, ComplexScenario_MultipleChannelsAndClients)
{
    // Add clients
    model->addClient(1);
    model->addClient(2);
    model->addClient(3);

    // Add channels
    model->addChannel("channel1");
    model->addChannel("channel2");

    // Add clients to channels
    model->addHub(1, id_hash("channel1"), ADMIN);
    model->addHub(2, id_hash("channel1"), MEMBER);
    model->addHub(3, id_hash("channel1"), MEMBER);

    model->addHub(1, id_hash("channel2"), ADMIN);
    model->addHub(2, id_hash("channel2"), MEMBER);

    // Verify sizes
    EXPECT_EQ(model->getClientSize(), 3);
    EXPECT_EQ(model->getChannelSize(), 2);
    EXPECT_EQ(model->countClientsInChannel("channel1"), 3);
    EXPECT_EQ(model->countClientsInChannel("channel2"), 2);

    // Verify pollfds
    std::vector<pollfd> pollfds = model->getPollfds();
    EXPECT_EQ(pollfds.size(), size_t(3));

    // Remove a client and verify cleanup
    model->removeClient(1);
    EXPECT_EQ(model->getClientSize(), 2);
    EXPECT_EQ(model->countClientsInChannel("channel1"), 2);
    EXPECT_EQ(model->countClientsInChannel("channel2"), 1);

    // Remove a channel and verify cleanup
    model->removeChannel(id_hash("channel1"));
    EXPECT_EQ(model->getChannelSize(), 1);
    EXPECT_EQ(model->countClientsInChannel("channel1"), 0);
}

// テストをグループ化するための名前空間
namespace ModelClientTests
{
    TEST_F(ModelTest, RemoveClient_Success)
    {
        model->addClient(1);
        model->removeClient(1);
        const Client *client = model->getClient(1);
        EXPECT_EQ(client, nullptr);
        EXPECT_EQ(model->getClientSize(), 0);
    }

    TEST_F(ModelTest, GetClient_NonExistent)
    {
        const Client *client = model->getClient(999);
        EXPECT_EQ(client, nullptr);
        EXPECT_EQ(model->getClientSize(), 0);
    }
}

namespace ModelChannelTests
{
    TEST_F(ModelTest, AddChannel_Success)
    {
        model->addChannel("test_channel");
        const Channel *channel = model->getChannel(id_hash("test_channel"));
        ASSERT_NE(channel, nullptr);
        EXPECT_EQ(channel->getName(), "test_channel");
        EXPECT_EQ(model->getChannelSize(), 1);
        EXPECT_EQ(model->countClientsInChannel("test_channel"), 0);
    }

    TEST_F(ModelTest, GetChannel_NonExistent)
    {
        const Channel *channel = model->getChannel(999);
        EXPECT_EQ(channel, nullptr);
        EXPECT_EQ(model->getChannelSize(), 0);
    }
}
