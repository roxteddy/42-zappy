# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/04 11:09:53 by pciavald          #+#    #+#              #
#    Updated: 2014/06/11 22:48:24 by pciavald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	client
CC		=	gcc
FLAGS	=	-O3 -Wall -Wextra -Werror

SDIR	=	./src/
IDIR	=	./inc/
ODIR	=	./obj/

EXT		+=	Makefile
EXT		+=	$(IDIR)$(NAME).h

SRC		=	main.c error.c data.c\

S		=	$(addprefix $(SDIR), $(SRC))

OBJ		=	$(SRC:.c=.o)
O		=	$(addprefix $(ODIR), $(OBJ))

all: $(NAME)

$(NAME): $(O) $(EXT)
	@echo "creating $(NAME)..."
	@$(CC) $(FLAGS) -I $(IDIR) -o $@ $(O)
	@echo "done."

$(ODIR)%.o: $(SDIR)%.c $(EXT)
	@echo "compiling $<..."
	@$(CC) $(FLAGS) -c -o $@ $< -I $(IDIR)

$(O): | $(ODIR)
$(ODIR):
	@mkdir $(ODIR)

clean:
	@echo "cleaning object files..."
	@rm -rf $(ODIR)

fclean: clean
	@echo "cleaning $(NAME) binary..."
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
