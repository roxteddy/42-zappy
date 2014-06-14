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

NAME = gfx

all: $(NAME)

$(NAME):
	echo "#!/bin/sh" > $(NAME)
	echo "python ./main.py $$1 $$2" >> $(NAME)
	chmod 700 $(NAME)

clean:

fclean:
	rm -rf $(NAME)

re: fclean all