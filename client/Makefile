#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorre <fcorre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/26 19:25:11 by fcorre            #+#    #+#              #
#    Updated: 2014/06/10 15:07:05 by fcorre           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all clean fclean re

FILES = 
CFLAGS = -Wall -Wextra -Werror -O3 -I ./inc
SRC = $(addprefix src/, $(FILES))
OBJ = $(SRC:src/%.c=obj/%.o)
NAME = client
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


