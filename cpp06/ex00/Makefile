#! Makefile

NAME = Converter
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
RM = rm -rf

OBJ_DIR = obj

SRC_CPP = main.cpp ScaleConverter.cpp prints.cpp toType.cpp
SRCS = $(addprefix src/, $(SRC_CPP))
OBJS = $(SRCS:src/%.cpp=$(OBJ_DIR)/%.o)

NC = "\033[0m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"

all : $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo $(GREEN)"Compiled!"$(NC)

$(OBJ_DIR)/%.o:src/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CPP) $(CPPFLAGS) -o $@ -c $<

test: 	all
		./$(NAME) 0
		./$(NAME) 42
		./$(NAME) 42.0f
		./$(NAME) 42.0
		./$(NAME) nan
		./$(NAME) nanf
		./$(NAME) inf
		./$(NAME) inff
		./$(NAME) -inf
		./$(NAME) -inff
		./$(NAME) -0
		./$(NAME) -0.0
		./$(NAME) -0.0f
		./$(NAME) 0.0
		./$(NAME) 0.0f
		./$(NAME) 0.f
		./$(NAME) 33.4321d
		./$(NAME) 33.4321f
		./$(NAME) 33.4321
		./$(NAME) 21212121
		./$(NAME) 2147483647
		./$(NAME) 2147483648
		./$(NAME) 2147483648.0
		./$(NAME) 2147483648.0f

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re