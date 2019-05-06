/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyconf_mouse.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 11:45:51 by fhignett       #+#    #+#                */
/*   Updated: 2019/05/06 17:24:37 by fhignett      ########   odam.nl         */
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
	if (mlx->fract != 42)
	{
		if (button == WHEEL_FORW)
			KEYCONF->zoom *= 1.020;
		else if (button == WHEEL_BACK)
			KEYCONF->zoom *= 0.980;
	}
	return (0);
}

int				mouse_release(int button, int x, int y, t_mlx *mlx)
{
	if (button == R_MOUSE && mlx->fract == 1)
		KEYCONF->mouse_click = (KEYCONF->mouse_click == 0 ? 1 : 0);
	if (button == L_MOUSE && (x >= 30 && x <= 40) && (y >= 40 && y <= 50))
		KEYCONF->info = (KEYCONF->info + 1) % 2;
	if (KEYCONF->info)
		if (button == L_MOUSE && (x >= 120 && x <= 130)
		&& (y >= 140 && y <= 150))
			mlx->disco = (mlx->disco + 1) % 2;
	return (0);
}
