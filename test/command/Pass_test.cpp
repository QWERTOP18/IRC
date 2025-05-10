#include <gtest/gtest.h>
#include "../../srcs/Command/Pass.hpp"
#include "../../srcs/Model/Model.hpp"
#include "../../srcs/DTO/RequestBody.hpp"
#include "../../srcs/DTO/ResponseBody.hpp"

class PassTest : public ::testing::Test
{
protected:
    Model *model;
    Pass *passCommand;

    void SetUp() override
    {
        model = new Model();
        model->setPassword("Password"); // 仮のパスワード設定
        passCommand = new Pass();
        passCommand->setModel(model); // Model を注入
    }

    void TearDown() override
    {
        delete passCommand;
        delete model;
    }
};

TEST_F(PassTest, Run_ValidPassword)
{
    RequestBody request;
    request.m_content = "Password";
    ResponseBody response = passCommand->run(request);

    // EXPECT_EQ(response.m_status, ERR_PASSWDMISMATCH);
    // EXPECT_EQ(response.m_content, "");
}

TEST_F(PassTest, Run_InvalidPassword)
{
    RequestBody request;
    request.m_content = "wrong_password";

    ResponseBody response = passCommand->run(request);

    EXPECT_EQ(response.m_status, ERR_PASSWDMISMATCH);
    // EXPECT_EQ(response.m_content, "Invalid password");
}