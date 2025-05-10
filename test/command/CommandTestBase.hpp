#ifndef COMMAND_TEST_BASE_HPP
#define COMMAND_TEST_BASE_HPP

#include <gtest/gtest.h>
#include "../../srcs/Model/Model.hpp"
#include "../../srcs/DTO/RequestBody.hpp"
#include "../../srcs/DTO/ResponseBody.hpp"

class CommandTestBase : public ::testing::Test
{
protected:
    Model *model;

    void SetUp() override
    {
        model = new Model();
        model->setPassword("correct_password"); // 仮のパスワード設定
    }

    void TearDown() override
    {
        delete model;
    }

    RequestBody createRequest(const std::string &content)
    {
        RequestBody request;
        request.m_content = content;
        return request;
    }
};

#endif // COMMAND_TEST_BASE_HPP