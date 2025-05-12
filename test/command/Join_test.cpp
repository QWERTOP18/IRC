#include "CommandTestBase.hpp"
#include "../../srcs/Command/Join.hpp"

class JoinTest : public CommandTestBase
{
protected:
    Join *joinCommand;

    void SetUp() override
    {
        CommandTestBase::SetUp();
        joinCommand = new Join();
        joinCommand->setModel(model); // Model を注入
    }

    void TearDown() override
    {
        delete joinCommand;
        CommandTestBase::TearDown();
    }
};

TEST_F(JoinTest, Run_ValidChannel)
{
    RequestBody request = createRequest("#general");

    ResponseBody response = joinCommand->start(request);

    EXPECT_EQ(response.m_status, 200);
    EXPECT_EQ(response.m_content, "Joined channel #general");
}

TEST_F(JoinTest, Run_InvalidChannel)
{
    RequestBody request = createRequest("invalid_channel");

    ResponseBody response = joinCommand->start(request);

    EXPECT_EQ(response.m_status, 400);
    EXPECT_EQ(response.m_content, "Invalid channel name");
}