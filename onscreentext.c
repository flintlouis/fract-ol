/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   onscreentext.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:14:25 by fhignett       #+#    #+#                */
/*   Updated: 2019/05/03 15:27:38 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	display_fps(t_mlx *mlx)
{
	char *fps;

	fps = ft_itoa(frames());
	mlx_string_put(mlx->init, mlx->win, 1040, 70, 0x33FF83, "FPS :");
	mlx_string_put(mlx->init, mlx->win, 1105, 70, 0x33FF83, fps);
	free(fps);
}	

void		onscreentext(t_mlx *mlx)
{
	display_fps(mlx);
}