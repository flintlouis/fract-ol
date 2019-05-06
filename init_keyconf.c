/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_keyconf.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 11:42:36 by fhignett       #+#    #+#                */
/*   Updated: 2019/05/06 11:44:12 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_fract(t_mlx *mlx)
{
	if (mlx->fract != 1)
		KEYCONF->itter[1] = 50;
	else
		KEYCONF->itter[1] = 85;
	KEYCONF->itter[0] = 0;
	KEYCONF->zoom = 1.0;
	KEYCONF->x_pos = 0;
	KEYCONF->y_pos = 0;
	KEYCONF->glow = 3;
	mlx->colour = mlx->fract;
	mlx->disco = 0;
}

void	init_keyconf(t_mlx *mlx)
{
	KEYCONF = MEM(t_keyconf);
	KEYCONF->colours[0] = (t_colour){0x33, 0xFF, 0x83};
	KEYCONF->colours[1] = (t_colour){0x25, 0x84, 0xDE};
	KEYCONF->colours[2] = (t_colour){0xDE, 0x2A, 0x25};
	reset_fract(mlx);
}
