cmake_minimum_required(VERSION 3.10)
project(IRC)

# GoogleTestのインクルードパスとリンクを追加
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
link_directories(${GTEST_LIBRARIES})

# コンパイルオプション
set(CMAKE_CXX_STANDARD 98)

# ソースファイル
add_executable(test_argument test_argument.cpp)

# GoogleTestとリンク
target_link_libraries(test_argument ${GTEST_LIBRARIES} pthread)
