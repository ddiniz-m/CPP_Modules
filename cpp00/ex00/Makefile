#! Makefile

NAME = Megaphone
CXX = @c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
RM = rm -rf

SRC = Megaphone.cpp
OBJ = $(SRC:%.c=%.o)

NC = "\033[0m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)
	@echo $(GREEN)"Compiled!"$(NC)

%$(OBJ): %$(SRC)
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re