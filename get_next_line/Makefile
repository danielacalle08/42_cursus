# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 10:46:25 by dcalle-m          #+#    #+#              #
#    Updated: 2023/12/05 13:49:44 by dcalle-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: get_next_line

get_next_line: src/get_next_line.c src/get_next_line_utils.c src/get_next_line.h main.c
	gcc -Wall -Werror -Wextra -o get_next_line src/get_next_line.c src/get_next_line_utils.c main.c -Isrc/ -D BUFFER_SIZE=1

bonus: src/get_next_line_bonus.c src/get_next_line_utils_bonus.c src/get_next_line_bonus.h main_bonus.c
	gcc -Wall -Werror -Wextra -o get_next_line src/get_next_line_bonus.c src/get_next_line_utils_bonus.c main_bonus.c -Isrc/ -D BUFFER_SIZE=1

clean:

fclean: clean
	rm -f get_next_line

re: fclean all

.PHONY: all clean fclean re bonus