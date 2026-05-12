# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thattal <thattal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/12 15:01:17 by thattal           #+#    #+#              #
#    Updated: 2026/05/12 15:07:26 by thattal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

FTPRINTF = ./printf/libftprintf.a

SRCS	= $(wildcard *.c)

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