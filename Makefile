CXX=c++
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror

NAME = IRC

SRC = $(shell find . -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
OBJ_DIR = $(OBJ:.o=.d)
INCLUDE = $(shell find . -name "*.hpp")


all: $(NAME)
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^


%.o: %.cpp $(INCLUDE)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.d: %.cpp
	@$(CXX) $(CXXFLAGS) -MM $< -MF $@


clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re