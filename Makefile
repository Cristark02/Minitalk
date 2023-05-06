# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmita <mmita@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/30 16:18:16 by mmita             #+#    #+#              #
#    Updated: 2023/05/06 20:05:06 by mmita            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[32m #Define una cadena de caracteres que se utiliza para dar color verde al texto en la salida de la terminal.
RED = \033[31m
RESET = \033[0m


CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs #Define un comando que se utilizará para crear un archivo de biblioteca estática.

INC = -Iinclude/ -Ilibft/ -Iprintf #Define la ubicación de los archivos de encabezado que se utilizarán para compilar el código fuente.

LIBFT = ./libft/libft.a

PRINTF = ./printf/libftprintf.a

SERVER = server
SRCS_SERVER = ./srcs/server.c

CLIENT = client
SRCS_CLIENT = ./srcs/client.c

SERVER_B = server_bonus
SRCS_SERVER_B = ./srcs_bonus/server_bonus.c

CLIENT_B = client_bonus
SRCS_CLIENT_B = ./srcs_bonus/client_bonus.c

all: $(SERVER) $(CLIENT)

$(SERVER): $(LIBFT) $(PRINTF) $(SRCS_SERVER)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT)  $(PRINTF) -o $(SERVER) $(SRCS_SERVER)
	@echo "\n $(GREEN) El Servidor está listo. Ejecútelo con el comando ./server y siga las instrucciones.$(RESET) ✅\n"

$(CLIENT): $(LIBFT) $(PRINTF) $(SRCS_CLIENT)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) $(PRINTF) -o $(CLIENT) $(SRCS_CLIENT)
	@echo "\n $(GREEN) El Cliente está listo.$(RESET) ✅\n"

$(SERVER_B): $(LIBFT) $(PRINTF) $(SRCS_SERVER_B)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) $(PRINTF) -o $(SERVER_B) $(SRCS_SERVER_B)
	@echo "\n $(GREEN) El Servidor Bunus está listo. Ejecútelo con el comando ./server_bonus y siga las instrucciones.$(RESET) ✅\n"

$(CLIENT_B): $(LIBFT) $(PRINTF) $(SRCS_CLIENT_B)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) $(PRINTF) -o $(CLIENT_B) $(SRCS_CLIENT_B)
	@echo "\n $(GREEN) El Cliente está listo.$(RESET) ✅\n"

$(LIBFT):
	@make -C libft --silent
	@echo "\n $(GREEN)Libft (¿recuerdas lo difícil que nos resultó terminarla?) está lista.$(RESET) ✅\n"
$(PRINTF):
	@make -C printf --silent
clean:
	@make -C libft clean --silent
	@make -C printf clean --silent
	@echo "\n $(RED) Archivos Binarios eliminados. $(RESET) \n"

fclean: clean
	@make -C libft fclean --silent
	@make -C printf fclean --silent
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_B) $(SERVER_B)
	@echo "\n $(RED) Archivos ejecutables eliminados. $(RESET) \n"

bonus: $(SERVER_B) $(CLIENT_B)

re: fclean all

.PHONY: all clean fclean re bonus