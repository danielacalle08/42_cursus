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

CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

SRCS1 = main.c
SRCS2 = list_utils.c nbr_utils.c stack_init.c swap.c error.c push.c reverse_rotate.c rotate.c
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
HEADER = push_swap.h

LIBS = libft/libft.a 

all: libs $(NAME)

libs:
	@make -C libft

$(NAME): $(OBJS1) $(OBJS2)
	gcc $(CFLAGS) $(OBJS1) $(OBJS2) $(LIBS) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	@make clean -C libft
	rm -f $(OBJS1) $(OBJS2)

fclean: clean
	rm -f $(NAME) $(LIBS)

re: fclean all