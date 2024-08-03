# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 16:37:41 by dcalle-m          #+#    #+#              #
#    Updated: 2024/08/03 17:06:11 by dcalle-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CFLAGS = -Wall -Wextra -Werror 
INCLUDE  = philo.h
SRC  = init.c main.c routine.c set.c utils.c


all:$(NAME)

$(NAME): $(SRC) $(INCLUDE)
	mkdir -p obj
	cc  $(CFLAGS)  -lpthread   $(SRC) -o $(NAME) 

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)
	
re: clean all

.PHONY: all clean fclean re