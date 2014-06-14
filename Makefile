#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorre <fcorre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/26 19:25:11 by fcorre            #+#    #+#              #
#    Updated: 2014/06/11 17:58:16 by pciavald         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all clean fclean re

all: serveur client gfx

serveur:
	make -C serveur/

client:
	make -C client/

clean:
	make -C serveur/ clean
	make -C client/ clean
	make -C gfx/ clean

fclean:
	make -C serveur/ fclean
	make -C client/ fclean
	make -C gui/ fclean

re: fclean all
