#! Makefile

NAME = SedBad
CXX = @c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
RM = rm -rf

OBJ_DIR = obj

SRC_CPP = main.cpp utils.cpp
SRCS = $(addprefix src/, $(SRC_CPP))
OBJS = $(addprefix, $(OBJ_DIR)/, $(SRC_CPP:%.c=%.o))

GREEN = "\033[0;32m"
NC = "\033[0m"

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	@echo $(GREEN)"Compiled!"$(NC)

$(OBJ_DIR)/%.o: $(SRCS)
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJS) $(OBJ_DIR) *.replace

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re