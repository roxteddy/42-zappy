#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorre <fcorre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/26 19:25:11 by fcorre            #+#    #+#              #
#    Updated: 2014/06/14 14:04:00 by mfebvay          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all clean fclean re

FILES = main.c opt.c team_add.c usage.c init_data.c init_server.c \
srv_accept.c client_read.c client_write.c clean_fd.c error.c check_fd.c \
init_fd.c cmd_handl.c player_init.c player_add.c egg_del.c
CFLAGS = -Wall -Wextra -Werror -I ./inc
SRC = $(addprefix src/, $(FILES))
OBJ = $(SRC:src/%.c=obj/%.o)
NAME = serveur
CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

obj/%.o: src/%.c
	@mkdir -p obj/
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj/

fclean: clean
	rm -rf $(NAME)

re: fclean all