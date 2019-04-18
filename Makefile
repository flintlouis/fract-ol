# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fhignett <fhignett@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/24 12:18:10 by rkuijper       #+#    #+#                 #
#    Updated: 2019/03/27 13:47:17 by fhignett      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol
INCL = -Ilibft -Iminilibx_macos
LIB = -Lminilibx_macos -lmlx -Llibft -lft
FILESC = *.c
FILESO = $(FILESC:.c=.o)

all: $(NAME)

$(NAME):
	@echo "Compiling..."
	@make -C libft
	@gcc -Wall -Werror -Wextra -o $(NAME) $(FILESC) $(LIB) $(INCL) -framework OpenGL -framework AppKit
	@echo "Done!"

clean:
	@echo "Removing object files..."
	@rm -f $(FILESO)
	@make -C libft clean
fclean: clean
	@echo "Removing binaries..."
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
