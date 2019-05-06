/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyconf_keys.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 14:18:18 by nvreeke        #+#    #+#                */
/*   Updated: 2019/05/06 13:43:03 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

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

static void	key_press(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		close_window(NULL);
	if (mlx->fract != 42)
	{
		if (key == KEY_SHIFT)
			KEYCONF->shift = 1;
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
	}
}

static void	change_fract(int key, t_mlx *mlx)
{
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
}

int			press_key(int key, t_mlx *mlx)
{
	key_press(key, mlx);
	if (mlx->fract != 42)
	{
		if (key == KEY_UP)
			if (KEYCONF->itter[1] < 250)
				KEYCONF->itter[1] += 1;
		if (key == KEY_DOWN)
			if (KEYCONF->itter[1] > 10)
				KEYCONF->itter[1] -= 1;
		if (key == KEY_LEFT)
			if (KEYCONF->glow < 45)
				KEYCONF->glow += .5;
		if (key == KEY_RIGHT)
			if (KEYCONF->glow > -40)
				KEYCONF->glow -= .5;
		change_fract(key, mlx);
	}
	return (0);
}
