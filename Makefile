# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fhignett <fhignett@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/24 12:18:10 by rkuijper       #+#    #+#                 #
#    Updated: 2019/05/06 14:09:08 by fhignett      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol
INCL = -Iincludes -Iminilibx_macos
LIB = -Lminilibx_macos -lmlx printflibft.a
FRAMEWORK = -framework OpenGL -framework AppKit
CFILES = fps init_fract init_keyconf burningship julia mandel42 mandelbrot \
keyconf_keys keyconf_mouse main onscreentext pixels
SOURCE = $(CFILES:%=source/%.c)
FILESO = $(SOURCE:.c=.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@echo "Creating fractols..."
	@gcc -o $(NAME) $(FLAGS) $(SOURCE) $(LIB) $(INCL) $(FRAMEWORK)
	@make clean
	@echo "Voila!"

clean:
	@rm -f $(FILESO)

fclean: clean
	@echo "Poof they're gone..."
	@rm -f $(NAME)

re: fclean all
