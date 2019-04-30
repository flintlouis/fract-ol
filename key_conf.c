/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_conf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 14:18:18 by nvreeke        #+#    #+#                */
/*   Updated: 2019/04/30 16:42:06 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		reset_mandel(t_mlx *mlx)
{
	mlx->keyconf->itter = 50;
	mlx->keyconf->stop = 16;
	mlx->keyconf->a_plus = 2.0;
	mlx->keyconf->a_min = -3.0;
	mlx->keyconf->b_plus = 2.5;
	mlx->keyconf->b_min = -2.5;
}

void	init_keyconf(t_mlx *mlx)
{
	mlx->keyconf = MEM(t_keyconf);
	reset_mandel(mlx);
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
		mlx->keyconf->itter += 1;
	if (key == KEY_S)
		mlx->keyconf->itter -= 1;
	if (key == KEY_A)
		mlx->keyconf->stop += 1;
	if (key == KEY_D)
		mlx->keyconf->stop -= 1;
	if (key == KEY_LEFT)
	{
		mlx->keyconf->a_plus += 0.15;
		mlx->keyconf->a_min += 0.15;
	}
	if (key == KEY_RIGHT)
	{
		mlx->keyconf->a_plus -= 0.15;
		mlx->keyconf->a_min -= 0.15;
	}
	if (key == KEY_UP)
	{
		mlx->keyconf->b_plus += 0.15;
		mlx->keyconf->b_min += 0.15;
	}
	if (key == KEY_DOWN)
	{
		mlx->keyconf->b_plus -= 0.15;
		mlx->keyconf->b_min -= 0.15;
	}
	if (key == KEY_SPACE)
		reset_mandel(mlx);

	// ft_printf("key : %d\n", key);
	return (0);
}
