CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -Isrcs

NAME = IRC

SRC = $(shell find srcs -name "*.cpp")
INCLUDE = $(shell find srcs -name "*.hpp")
OBJ_DIR = obj
OBJ = $(patsubst srcs/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: srcs/%.cpp $(INCLUDE) | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
