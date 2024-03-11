#! Makefile

NAME = References
CPP = @c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
RM = rm -rf

OBJ_DIR = obj

SRC_CPP = main.cpp
SRCS = $(SRC_CPP)
OBJS = $(addprefix, $(OBJ_DIR)/, $(SRC_CPP:%.cpp=%.o))

NC = "\033[0m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"

all : $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(SRCS) -o $(NAME)
	@echo $(GREEN)"Compiled!"$(NC)

$(OBJ_DIR)/%.o: $(SRCS)
	@mkdir -p $(OBJ_DIR)
	@$(CPP) $(CPPFLAGS) -c $@ -o $<

clean:
	@$(RM) $(OBJS) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re