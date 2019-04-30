# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fhignett <fhignett@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/24 12:18:10 by rkuijper       #+#    #+#                 #
#    Updated: 2019/04/30 11:19:13 by fhignett      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol
INCL = -Iincludes -Iminilibx_macos
LIB = -Lminilibx_macos -lmlx printflibft.a
FRAMEWORK = -framework OpenGL -framework AppKit
FILESC = *.c
FILESO = $(FILESC:.c=.o)
FLAGS = -Wall -Werror -Wextra # ADD ME LATER

all: $(NAME)

$(NAME):
	@echo "Compiling..."
	@gcc -o $(NAME) $(FILESC) $(LIB) $(INCL) $(FRAMEWORK)
	@make clean
	@echo "Done!"

clean:
	@echo "Removing object files..."
	@rm -f $(FILESO)

fclean: clean
	@echo "Removing binaries..."
	@rm -f $(NAME)

re: fclean all
