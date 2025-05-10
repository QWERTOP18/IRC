CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -Isrcs --pedantic
TEST_CXXFLAGS = -std=c++17 -Wall -Wextra -Isrcs -I/opt/homebrew/include -pthread
TEST_LDFLAGS = -L/opt/homebrew/lib -lgtest -lgtest_main -pthread

NAME = IRC
TEST_NAME = test_irc

SRC = $(shell find srcs -name "*.cpp")
TEST_SRC = $(shell find test -name "*.cpp")
INCLUDE = $(shell find srcs -name "*.hpp")
OBJ_DIR = obj
TEST_OBJ_DIR = test_obj

OBJ = $(patsubst srcs/%.cpp, $(OBJ_DIR)/%.o, $(SRC))
OBJ_NO_MAIN = $(filter-out $(OBJ_DIR)/main.o, $(OBJ))
TEST_OBJ = $(patsubst test/%.cpp, $(TEST_OBJ_DIR)/%.o, $(TEST_SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: srcs/%.cpp $(INCLUDE) | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST_OBJ_DIR)/%.o: test/%.cpp $(INCLUDE) | $(TEST_OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(TEST_CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TEST_OBJ_DIR):
	mkdir -p $(TEST_OBJ_DIR)

test: $(TEST_NAME)
	@./$(TEST_NAME)
	

$(TEST_NAME): $(OBJ_NO_MAIN) $(TEST_OBJ)
	$(CXX) $(TEST_CXXFLAGS) -o $@ $^ $(TEST_LDFLAGS)

clean:
	rm -rf $(OBJ_DIR) $(TEST_OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

debug: CXXFLAGS = -std=c++98 -Wall -Wextra -g -Isrcs -DDEBUG
debug: re

re: fclean all

# 特定のテストファイルを実行
test-model:
	./test_irc --gtest_filter=ModelTest.*

# 特定のテストケースを実行
test-model-client:
	./test_irc --gtest_filter=ModelClientTests.*

# 特定のテストを実行
test-model-add:
	./test_irc --gtest_filter=ModelTest.AddClient_Success

.PHONY: all clean fclean re test test-model test-model-client test-model-add
