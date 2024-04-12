NAME = push_swap

HDR = srcs/push_swap.h

SRCS = big_stack.c check_parameters.c free.c main.c rules_big.c rules_push_small.c \
rules_reverse_rotate_small.c rules_rotate_small.c rules_swap_small.c \
simplify_big_stack.c small_stack_size_five.c small_stack_size_four.c \
small_stack.c stack_sorted.c separate_parameters.c

OBJS = ${addprefix srcs/,${SRCS:.c=.o}}

LIBFT_AR = ./libft/libft.a 

INCLUDE = -I libft/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c ${HDR} ${LIBFT_AR} Makefile
	${CC} ${CFLAGS} -c $< -o $@ ${INCLUDE}

all: libft ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -Llibft -lft

libft:
	make -C libft

clean:
	rm -f ${OBJS}
	make clean -C libft

fclean: clean
	rm -f ${NAME}
	make fclean -C libft

re: fclean all

.PHONY: all libft clean fclean re
