#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorre <fcorre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/26 19:25:11 by fcorre            #+#    #+#              #
#    Updated: 2014/06/10 15:04:22 by fcorre           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all clean fclean re

all: serveur client gfx

serveur:
	make -I serveur/

client:
	make -I client/

clean:
	make -I serveur/ clean
	make -I client/ clean
	make -I gfx/ clean

fclean:
	make -I serveur/ fclean
	make -I client/ fclean
	make -I gfx/ fclean

re: fclean all


