#! Makefile

NAME = megaphone
CXX = @c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
RM = rm -rf

SRC = megaphone.cpp
OBJ = $(SRC:%.c=%.o)

GREEN = "\033[0;32m"
NC = "\033[0m"

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