/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_conf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 14:18:18 by nvreeke        #+#    #+#                */
/*   Updated: 2019/05/04 16:25:40 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_move(int x, int y, t_mlx *mlx)
{
	if (KEYCONF->mouse_click == 0)
		mlx->point = (t_point){(x - (WIDTH / 2)) * 3, (y - (HEIGHT / 2)) * 3};
	return (0);
}

int				mouse_press(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == WHEEL_FORW)
		KEYCONF->zoom *= 1.020;
	else if (button == WHEEL_BACK)
		KEYCONF->zoom *= 0.980;
	return (0);
}

int				mouse_release(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == R_MOUSE && mlx->fract == 1)
		KEYCONF->mouse_click = (KEYCONF->mouse_click == 0 ? 1 : 0);	
	if (button == L_MOUSE && (x >= 30 && x <= 40) && (y >= 40 && y <= 50))
	{
		if (KEYCONF->info == 0)
			KEYCONF->info = 1;
		else
			KEYCONF->info = 0;
	// ft_printf("x : %d y : %d\n", x, y);
	}
	return (0);
}

void		reset_fract(t_mlx *mlx)
{
	if (mlx->fract != 1)
		KEYCONF->itter = 50;
	else
		KEYCONF->itter = 85;
	KEYCONF->zoom = 1.0;
	KEYCONF->x_pos = 0;
	KEYCONF->y_pos = 0;
	KEYCONF->glow = 3;
	mlx->colour = mlx->fract;
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

int			release_key(int key, t_mlx *mlx)
{
	if (key == KEY_SPACE && KEYCONF->shift == 0)
		reset_fract(mlx);
	if (key == KEY_SHIFT)
		KEYCONF->shift = 0;
	if (key == KEY_SPACE && KEYCONF->shift == 1)
		mlx->colour = (mlx->colour + 1) % 3;
	return (0);
}

int			press_key(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		close_window(NULL);
	if (key == KEY_SHIFT)
		KEYCONF->shift = 1;
	if (key == KEY_UP)
		if (KEYCONF->itter < 250)
			KEYCONF->itter += 1;
	if (key == KEY_DOWN)
	{
		if (KEYCONF->itter > 10)
			KEYCONF->itter -= 1;
	}
	if (key == KEY_D)
		KEYCONF->x_pos += 0.05 * KEYCONF->zoom;
	if (key == KEY_A)
		KEYCONF->x_pos -= 0.05 * KEYCONF->zoom;
	if (key == KEY_S)
		KEYCONF->y_pos += 0.05 * KEYCONF->zoom;
	if (key == KEY_W)
		KEYCONF->y_pos -= 0.05 * KEYCONF->zoom;
	if (key == KEY_PLUS)
		KEYCONF->zoom *= 0.985;
	if (key == KEY_MIN)
		KEYCONF->zoom *= 1.015;
	if (key == KEY_LEFT)
	{
		if (KEYCONF->glow < 45)
			KEYCONF->glow += .5;
	}
	if (key == KEY_RIGHT)
	{
		if (KEYCONF->glow > -40)
			KEYCONF->glow -= .5;
	}
	if (key == KEY_1 && mlx->fract != 0)
	{
		mlx->fract = 0;
		reset_fract(mlx);
	}
	if (key == KEY_2 && mlx->fract != 1)
	{
		mlx->fract = 1;
		reset_fract(mlx);
	}
	if (key == KEY_3 && mlx->fract != 2)
	{
		mlx->fract = 2;
		reset_fract(mlx);
	}	
	
	// ft_printf("key : %d\n", key);
	return (0);
}
