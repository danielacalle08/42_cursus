# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 20:12:10 by dcalle-m          #+#    #+#              #
#    Updated: 2024/01/31 13:48:55 by dcalle-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COMANDOS
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

#EJECUTABLES
CLIENT_NAME = client
SERVER_NAME = server
SRC_FILES = server.c client.c utils.c
OBJ_SERVER = server.o
OBJ_CLIENT = client.o utils.o

#FICHEROS
HEADER = minitalk.h

LIBS = printf/libftprintf.a

#COMPILAR
all: libs $(CLIENT_NAME) $(SERVER_NAME)

#REGLAS
libs:
	@make -C printf

$(OBJ_CLIENT): %.o: %.c ${HEADER}
	@$(CC) $(CFLAGS) -c -o $@ $<
$(OBJ_SERVER): %.o: %.c ${HEADER}
	@$(CC) $(CFLAGS) -c -o $@ $<


$(CLIENT_NAME): $(OBJ_CLIENT) libs
	@$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(OBJ_CLIENT) $(LIBS)
$(SERVER_NAME): $(OBJ_SERVER) libs
	@$(CC) $(CFLAGS) -o $(SERVER_NAME) $(OBJ_SERVER) $(LIBS)

	
clean:
	@make clean -C printf
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(LIBS)

re: fclean all
