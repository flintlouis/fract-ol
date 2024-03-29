# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fhignett <fhignett@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/24 12:18:10 by rkuijper       #+#    #+#                 #
#    Updated: 2019/05/06 15:08:22 by fhignett      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol
INCL = -Iincludes -Iminilibx_macos -Ift_libft/includes
LIB = -Lminilibx_macos -lmlx ft_libft/libft.a
FRAMEWORK = -framework OpenGL -framework AppKit
CFILES = fps init_fract init_keyconf burningship julia mandel42 mandelbrot \
keyconf_keys keyconf_mouse main onscreentext pixels
SOURCE = $(CFILES:%=source/%.c)
OFILES = $(SOURCE:.c=.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@echo "Creating fractols..."
	@make -C ft_libft
	@gcc -o $(NAME) $(FLAGS) $(SOURCE) $(LIB) $(INCL) $(FRAMEWORK)
	@make clean
	@echo "Voila!"

clean:
	@make clean -C ft_libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ft_libft
	@echo "Poof they're gone..."

re: fclean all
