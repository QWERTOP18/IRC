// #include "CommandTestBase.hpp"
// #include "../../srcs/Command/Part.hpp"

// class PartTest : public CommandTestBase
// {
// protected:
//     Part *partCommand;

//     void SetUp() override
//     {
//         CommandTestBase::SetUp();
//         partCommand = new Part();
//         partCommand->setModel(model); // Model を注入
//     }

//     void TearDown() override
//     {
//         delete partCommand;
//         CommandTestBase::TearDown();
//     }
// };

// TEST_F(PartTest, Run_ValidChannel)
// {
//     RequestBody request = createRequest("#general");

//     ResponseBody response = partCommand->start(request);

//     EXPECT_EQ(response.m_status, 200);
//     EXPECT_EQ(response.m_content, "Left channel #general");
// }

// TEST_F(PartTest, Run_InvalidChannel)
// {
//     RequestBody request = createRequest("invalid_channel");

//     ResponseBody response = partCommand->start(request);

//     EXPECT_EQ(response.m_status, 404);
//     EXPECT_EQ(response.m_content, "Channel not found");
// }