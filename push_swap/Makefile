# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 18:33:11 by dcalle-m          #+#    #+#              #
#    Updated: 2024/05/27 18:33:07 by dcalle-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g3

NAME = push_swap

SRCS = 	algorithm_utils.c \
		algorithm_utils2.c \
		error_utils.c \
		list_utils.c \
		main.c \
		nbr_utils.c \
		pile_utils.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		sorting_pile.c \
		stack_init.c \
		swap.c \


OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h

LIBS = libft/libft.a 

all: libs $(NAME)

libs:
	@make -C libft

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	@make clean -C libft
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(LIBS)

re: fclean all