# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thattal <thattal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/12 15:01:17 by thattal           #+#    #+#              #
#    Updated: 2026/05/14 15:01:46 by thattal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -f
FTPRINTF = ./printf/libftprintf.a
SRCS	= srcs/main.c \
		  srcs/parse.c \
		  srcs/parse2.c \
		  srcs/utils.c \
		  srcs/utils_1.c \
		  srcs/ft_benchmark.c \
		  srcs/ft_benchmark2.c \
		  srcs/operations/push.c \
		  srcs/operations/rotate.c \
		  srcs/operations/switch.c \
		  srcs/chunk_sort/chunk_sort.c \
		  srcs/chunk_sort/normalize_chunk.c \
		  srcs/chunk_sort/normalize_operations.c \
		  srcs/bubble_sort/bubble_sort.c \
		  srcs/adaptive_algo/adaptive_algo.c \
		  srcs/radix_sort.c
OBJS	= $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(FTPRINTF) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(FTPRINTF)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(FTPRINTF):
	make -C ./printf
clean:
	make clean -C ./printf
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(FTPRINTF)
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re