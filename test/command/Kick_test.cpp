#include "CommandTestBase.hpp"
#include "../../srcs/Command/Kick.hpp"

class KickTest : public CommandTestBase
{
protected:
    Kick *kickCommand;

    void SetUp() override
    {
        CommandTestBase::SetUp();
        kickCommand = new Kick();
        kickCommand->setModel(model); // Model を注入
    }

    void TearDown() override
    {
        delete kickCommand;
        CommandTestBase::TearDown();
    }
};

TEST_F(KickTest, Run_ValidUser)
{
    RequestBody request = createRequest("user123");

    ResponseBody response = kickCommand->start(request);

    EXPECT_EQ(response.m_status, 200);
    EXPECT_EQ(response.m_content, "User user123 has been kicked");
}

TEST_F(KickTest, Run_InvalidUser)
{
    RequestBody request = createRequest("nonexistent_user");

    ResponseBody response = kickCommand->start(request);

    EXPECT_EQ(response.m_status, 404);
    EXPECT_EQ(response.m_content, "User not found");
}