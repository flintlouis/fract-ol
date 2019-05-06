/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   onscreentext.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:14:25 by fhignett       #+#    #+#                */
/*   Updated: 2019/05/06 13:55:57 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static void	disco(t_mlx *mlx)
{
	mlx_string_put(mlx->init, mlx->win, 40, 130, \
	TCOLOURS[mlx->colour], "DISCO :");
	if (!mlx->disco)
		mlx_string_put(mlx->init, mlx->win, 120, 130, \
		TCOLOURS[mlx->colour], "X");
	else
		mlx_string_put(mlx->init, mlx->win, 120, 130, \
		TCOLOURS[mlx->colour], "0");
}

static void	display_fps(t_mlx *mlx, char *fps)
{
	mlx_string_put(mlx->init, mlx->win, 40, 50, \
	TCOLOURS[mlx->colour], "FPS   :");
	mlx_string_put(mlx->init, mlx->win, 120, 50, TCOLOURS[mlx->colour], fps);
}

static void	display_info(t_mlx *mlx, char *fps)
{
	char *info;

	mlx_string_put(mlx->init, mlx->win, 30, 30, TCOLOURS[mlx->colour], "-");
	display_fps(mlx, fps);
	mlx_string_put(mlx->init, mlx->win, 40, 70, \
	TCOLOURS[mlx->colour], "ITTER :");
	info = ft_itoa(KEYCONF->itter[1]);
	mlx_string_put(mlx->init, mlx->win, 120, 70, TCOLOURS[mlx->colour], info);
	free(info);
	mlx_string_put(mlx->init, mlx->win, 40, 90, \
	TCOLOURS[mlx->colour], "GLOW  :");
	info = ft_itoa(ft_map(KEYCONF->glow, -40, 45, 0, 100));
	mlx_string_put(mlx->init, mlx->win, 120, 90, TCOLOURS[mlx->colour], info);
	free(info);
	mlx_string_put(mlx->init, mlx->win, 40, 110, \
	TCOLOURS[mlx->colour], "FRACT :");
	mlx_string_put(mlx->init, mlx->win, 120, 110, \
	TCOLOURS[mlx->colour], NAME[mlx->fract]);
	disco(mlx);
}

static void	info(t_mlx *mlx)
{
	int		c[3];
	char	*fps;

	c[0] = 0x33FF83;
	c[1] = 0x2584DE;
	c[2] = 0xDE2A25;
	fps = ft_itoa(frames());
	if (KEYCONF->info == 0)
		mlx_string_put(mlx->init, mlx->win, 30, 30, TCOLOURS[mlx->colour], "+");
	else
		display_info(mlx, fps);
	free(fps);
}

void		onscreentext(t_mlx *mlx)
{
	if (mlx->disco == 1)
		mlx->colour = (mlx->colour + 1) % 3;
	if (mlx->fract != 42)
		info(mlx);
}
