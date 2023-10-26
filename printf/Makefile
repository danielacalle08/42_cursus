# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 18:00:02 by dcalle-m          #+#    #+#              #
#    Updated: 2023/10/26 12:00:25 by dcalle-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_putchar.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_printf.c \
			ft_puthex.c \

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I./
	ar rcs $(NAME) $(OBJS)
all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus re fclean clean