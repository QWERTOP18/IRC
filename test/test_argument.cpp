#include "Server.hpp"
#include <gtest/gtest.h>

// テスト用のServerクラスのインスタンス作成を支援するヘルパー関数
Server createServer(const std::string &port, const std::string &password)
{
    return Server(port, password);
}

TEST(ServerTest, SetPortValid)
{
    // 有効なポート
    ASSERT_NO_THROW({
        Server server("6660", "ValidPassword123");
    });

    // 無効なポート（範囲外）
    ASSERT_THROW({ Server server("6670", "ValidPassword123"); }, std::invalid_argument);

    // 数字でないポート番号
    ASSERT_THROW({ Server server("abcd", "ValidPassword123"); }, std::invalid_argument);
}

TEST(ServerTest, SetPasswordValid)
{
    // 有効なパスワード
    ASSERT_NO_THROW({
        Server server("6660", "ValidPassword123");
    });

    // パスワードが短すぎる
    ASSERT_THROW({ Server server("6660", "abc"); }, std::invalid_argument);

    // 小文字がないパスワード
    ASSERT_THROW({ Server server("6660", "PASSWORD123"); }, std::invalid_argument);

    // 大文字がないパスワード
    ASSERT_THROW({ Server server("6660", "password123"); }, std::invalid_argument);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
