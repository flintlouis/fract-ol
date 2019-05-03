/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_conf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 14:18:18 by nvreeke        #+#    #+#                */
/*   Updated: 2019/05/03 15:25:01 by fhignett      ########   odam.nl         */
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
	// (void)x;
	// (void)y;
	if (button == R_MOUSE && mlx->fract == 2)
	{		
		if (KEYCONF->mouse_click == 0)
			KEYCONF->mouse_click = 1;
		else
			KEYCONF->mouse_click = 0;
		ft_printf("x : %d y : %d\n", x, y);		
	}
	return (0);
}

void		reset_fract(t_mlx *mlx)
{
	if (mlx->fract != 2)
		KEYCONF->itter = 50;
	else
		KEYCONF->itter = 85;
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
	if (key == KEY_UP)
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
	if (key == KEY_SPACE)
		reset_fract(mlx);
	if (key == KEY_1)
	{
		mlx->fract = 1;
		reset_fract(mlx);
	}
	if (key == KEY_2)
	{
		mlx->fract = 2;
		reset_fract(mlx);
	}
	if (key == KEY_3)
	{
		mlx->fract = 3;
		reset_fract(mlx);
	}
	
	// ft_printf("key : %d\n", key);
	// ft_printf("%d\n", KEYCONF->itter);
	return (0);
}
