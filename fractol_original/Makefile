# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 15:30:21 by dcalle-m          #+#    #+#              #
#    Updated: 2024/03/19 15:56:01 by dcalle-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        := fractol
CC        := gcc
FLAGS    := -Wall -Wextra -Werror

SRCS        :=      src/events.c \
                          src/fractal_init.c \
                          src/fractal_render.c \
                          src/main.c \
                          utils/math_utils.c \
                          utils/string_utils.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}
	

$(NAME): ${OBJS}
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit


all:		${NAME}

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1


fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a


re:			fclean all

.PHONY:		all clean fclean re


