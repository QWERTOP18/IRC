#include <gtest/gtest.h>
#include "Server/Server.hpp"
#include "Model/Model.hpp"
#include "Controller/Controller.hpp"
#include "macro.hpp"

// Mock Server class that skips socket operations
class MockServer : public Server {
public:
    MockServer(const std::string &port, const std::string &password, Model *model, Controller *controller)
        : Server() {
        m_Model = model;
        m_Controller = controller;
        setPort(port);
        setPassword(password);
        m_sokcet = -1;
    }

};

// Test fixture for Server tests
class ServerTest : public ::testing::Test {
protected:
    void SetUp() override {
        model = new Model();
        controller = new Controller(model);
    }

    void TearDown() override {
        delete controller;
        delete model;
    }

    Model *model;
    Controller *controller;
};


// Server initialization tests
TEST_F(ServerTest, Initialization_ValidParameters) {
    EXPECT_NO_THROW({
        MockServer server("6666", "Abcd", model, controller);
    });
}

TEST_F(ServerTest, Initialization_InvalidPort) {
    EXPECT_THROW({
        MockServer server("invalid", "Abcd", model, controller);
    }, std::invalid_argument);
}

TEST_F(ServerTest, Initialization_InvalidPort_TooSmall) {
    EXPECT_THROW({
        MockServer server("-1", "Abcd", model, controller);
    }, std::invalid_argument);
}
TEST_F(ServerTest, Initialization_InvalidPort_TooLarge) {
    EXPECT_THROW({
        MockServer server("70000", "Abcd", model, controller);
    }, std::invalid_argument);
}


TEST_F(ServerTest, Initialization_EmptyPassword) {
    EXPECT_THROW({
        MockServer server("6666", "", model, controller);
    }, std::invalid_argument);
}
TEST_F(ServerTest, Initialization_InvalidPassword_TooShort) {
    EXPECT_THROW({
        MockServer server("6666", "abc", model, controller);
    }, std::invalid_argument);
}

TEST_F(ServerTest, Initialization_InvalidPassword_NoUppercase) {
    EXPECT_THROW({
        MockServer server("6666", "abc", model, controller);
    }, std::invalid_argument);
}

TEST_F(ServerTest, Initialization_InvalidPassword_NoLowercase) {
    EXPECT_THROW({
        MockServer server("6666", "ABCD", model, controller);
    }, std::invalid_argument);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 