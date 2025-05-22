CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -Isrcs --pedantic
TEST_CXXFLAGS = -std=c++17 -Wall -Wextra -Isrcs -I/opt/homebrew/include -pthread
TEST_LDFLAGS = -L/opt/homebrew/lib -lgtest -lgtest_main -pthread

NAME = ircserv
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

$(OBJ_DIR) $(TEST_OBJ_DIR):
	mkdir -p $@

# 通常テスト実行
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

# ----------------------------
# テストの個別ターゲット
# ----------------------------
test-command:
	./$(TEST_NAME) --gtest_filter=CommandTestBase.*

test-kick:
	./$(TEST_NAME) --gtest_filter=KickTest.*

test-part:
	./$(TEST_NAME) --gtest_filter=PartTest.*

test-model:
	./$(TEST_NAME) --gtest_filter=ModelTest.*

test-model-client:
	./$(TEST_NAME) --gtest_filter=ModelClientTests.*

test-model-add:
	./$(TEST_NAME) --gtest_filter=ModelTest.AddClient_Success

.PHONY: all clean fclean re test debug \
        test-command test-kick test-part \
        test-model test-model-client test-model-add
