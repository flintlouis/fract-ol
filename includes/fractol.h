/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:03:10 by nvreeke        #+#    #+#                */
/*   Updated: 2019/05/01 16:22:27 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include <math.h>
# include <stdlib.h>
# include <pthread.h>

# define HEIGHT			800
# define WIDTH			1200
# define BLACK			set_colour(0x00, 0x00, 0x00)
# define WHITE			set_colour(0xFF, 0xFF, 0xFF)
# define NEON			set_colour(0x33, 0xFF, 0x83)
# define MEM(x)			(x*)ft_memalloc(sizeof(x))
# define KEYCONF		mlx->keyconf

# define KEY_ESC		53
# define KEY_SPACE		49
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_RIGHT		124
# define KEY_LEFT		123
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_PLUS		24
# define KEY_MIN		27

typedef unsigned char 	t_byte;

typedef struct			s_point
{
	double 				x;
	double 				y;
}						t_point;

typedef struct			s_colour
{
	t_byte				r;
	t_byte				g;
	t_byte				b;
}						t_colour;

typedef	struct			s_keyconf
{
	int					itter;
	double				x_pos;
	double				y_pos;
	double				zoom;
	double				glow;
}						t_keyconf;

typedef	struct			s_mlx
{
	void				*init;
	void				*win;
	void				*image;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int					y[2];
	t_keyconf			*keyconf;
}						t_mlx;

int						press_key(int key, t_mlx *mlx);
int						close_window(void *ptr);
int						start_mandel(t_mlx *mlx);
void					put_pixel(int x, int y, t_mlx *mlx, t_colour colour);
void					init_keyconf(t_mlx *mlx);
t_colour				set_colour(t_byte r, t_byte g, t_byte b);
t_colour				calc_colour(double c, int min, int max, t_colour min_c, t_colour max_c);

#endif