/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_conf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 14:18:18 by nvreeke        #+#    #+#                */
/*   Updated: 2019/05/02 12:14:13 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->point = (t_point){(x - (WIDTH / 2)) * 3, (y - (HEIGHT / 2)) * 3};
	return (0);
}

int				mouse_press(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	return (0);
}

int				mouse_release(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	(void)mlx;
	return (0);
}

void		reset_fract(t_mlx *mlx)
{
	KEYCONF->itter = 50;
	KEYCONF->zoom = 1.0;
	KEYCONF->x_pos = 0;
	KEYCONF->y_pos = 0;
	KEYCONF->glow = 3;
}

void	init_keyconf(t_mlx *mlx)
{
	KEYCONF = MEM(t_keyconf);
	reset_fract(mlx);
}

int			close_window(void *ptr)
{
	(void)ptr;
	exit(0);
	return (0);
}

int			press_key(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		close_window(NULL);
	if (key == KEY_W)
		KEYCONF->itter += 1;
	if (key == KEY_S)
		KEYCONF->itter -= 1;
	if (key == KEY_RIGHT)
		KEYCONF->x_pos += 0.05 * KEYCONF->zoom;
	if (key == KEY_LEFT)
		KEYCONF->x_pos -= 0.05 * KEYCONF->zoom;
	if (key == KEY_DOWN)
		KEYCONF->y_pos += 0.05 * KEYCONF->zoom;
	if (key == KEY_UP)
		KEYCONF->y_pos -= 0.05 * KEYCONF->zoom;
	if (key == KEY_PLUS)
		KEYCONF->zoom *= 0.985;
	if (key == KEY_MIN)
		KEYCONF->zoom *= 1.015;
	if (key == KEY_A)
	{
		if (KEYCONF->glow < 45)
			KEYCONF->glow += .5;
	}
	if (key == KEY_D)
	{
		if (KEYCONF->glow > -45)
			KEYCONF->glow -= .5;
	}
	if (key == KEY_SPACE)
		reset_fract(mlx);
	
	// ft_printf("key : %d\n", key);
	return (0);
}
