RED=\033[0;31m
GREEN=\033[0;32m
RESET=\033[0m

NAME = push_swap

SRCS = init_stack.c main.c movements.c utils_stack.c utils.c errors.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

LIB = push_swap.h

all: ${NAME}

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "$(NAME): $(GREEN)$(OBJS) was created $(RESET)"

clean:
		rm -f $(OBJS)
		@echo "$(RED)$(OBJS) was deleted $(RESET)"

fclean: clean
		rm -f $(NAME)
		@echo "$(RED)$(NAME) was deleted $(RESET)"

re: fclean all

.PHONY: all clean fclean re