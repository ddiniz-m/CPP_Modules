#! Makefile

NAME = Bsq
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
INC = -I /usr/includes/c++/11/iostream
RM = rm -rf

OBJ_DIR = obj

SRC_CPP = main.cpp Fixed.cpp Point.cpp bsq.cpp
SRCS = $(addprefix src/, $(SRC_CPP))
OBJS = $(SRCS:src/%.cpp=$(OBJ_DIR)/%.o)

NC = "\033[0m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"

all : $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(INC) $(OBJS) -o $(NAME)
	@echo $(GREEN)"Compiled!"$(NC)

$(OBJ_DIR)/%.o:src/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) $(INC)  -o $@ -c $<

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re