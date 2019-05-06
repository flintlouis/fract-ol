/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:03:10 by nvreeke        #+#    #+#                */
/*   Updated: 2019/05/06 13:56:09 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"

# define THREAD			40
# define HEIGHT			800
# define WIDTH			1200
# define BLACK			(t_colour){0x00, 0x00, 0x00}
# define TCOLOURS		(int[3]){0x33FF83, 0x2584DE, 0xDE2A25}
# define MEM(x)			(x*)ft_memalloc(sizeof(x))
# define KEYCONF		mlx->keyconf
# define NAME			(char*[3]){"Mandelbrot", "Julia", "Burning Ship"}

# define KEY_ESC		53
# define KEY_SPACE		49
# define KEY_SHIFT		257
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
# define L_MOUSE		1
# define R_MOUSE		2
# define WHEEL_FORW		4
# define WHEEL_BACK		5
# define KEY_1			18
# define KEY_2			19
# define KEY_3			20

typedef unsigned char	t_byte;

typedef struct			s_point
{
	double				x;
	double				y;
}						t_point;

typedef struct			s_colour
{
	t_byte				r;
	t_byte				g;
	t_byte				b;
}						t_colour;

typedef	struct			s_keyconf
{
	int					info;
	int					mouse_click;
	int					shift;
	int					itter[2];
	double				x_pos;
	double				y_pos;
	double				zoom;
	double				glow;
	t_colour			colours[3];
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
	int					fract;
	int					colour;
	int					y[2];
	int					disco;
	t_point				point;
	t_keyconf			*keyconf;
}						t_mlx;

int						press_key(int key, t_mlx *mlx);
int						release_key(int key, t_mlx *mlx);
int						close_window(void *ptr);
int						mouse_move(int x, int y, t_mlx *mlx);
int						mouse_press(int button, int x, int y, t_mlx *mlx);
int						mouse_release(int button, int x, int y, t_mlx *mlx);
int						frames(void);
double					calc_i(double i, t_mlx *mlx, t_point point);
void					init_fractol(int fract);
void					onscreentext(t_mlx *mlx);
void					*julia(void *data);
void					*mandel(void *data);
void					*ship(void *data);
void					*mandel42(void *data);
void					put_pixel(int x, int y, t_mlx *mlx, t_colour colour);
void					init_keyconf(t_mlx *mlx);
void					reset_fract(t_mlx *mlx);
void					calc_pixel_pos(int *x, int *y);
t_colour				calc_colour(double c, int *range,
						t_colour min_c, t_colour max_c);

#endif
