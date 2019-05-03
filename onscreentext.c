/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   onscreentext.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:14:25 by fhignett       #+#    #+#                */
/*   Updated: 2019/05/03 17:39:50 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	display_fps(t_mlx *mlx, int *c)
{
	char *fps;

	fps = ft_itoa(frames());
	mlx_string_put(mlx->init, mlx->win, 40, 50, c[mlx->fract], "FPS   :");
	mlx_string_put(mlx->init, mlx->win, 120, 50, c[mlx->fract], fps);
	free(fps);
}

static void	display_info(t_mlx *mlx, int *c)
{
	char *info;

	mlx_string_put(mlx->init, mlx->win, 30, 30, c[mlx->fract], "-");
	display_fps(mlx, c);

	mlx_string_put(mlx->init, mlx->win, 40, 70, c[mlx->fract], "ITTER :");
	info = ft_itoa(KEYCONF->itter);
	mlx_string_put(mlx->init, mlx->win, 120, 70, c[mlx->fract], info);
	free(info);

	mlx_string_put(mlx->init, mlx->win, 40, 90, c[mlx->fract], "GLOW  :");
	info = ft_itoa(ft_map(KEYCONF->glow, -40, 45, 0, 100));
	mlx_string_put(mlx->init, mlx->win, 120, 90, c[mlx->fract], info);
	free(info);

	mlx_string_put(mlx->init, mlx->win, 40, 110, c[mlx->fract], "FRACT :");
	mlx_string_put(mlx->init, mlx->win, 120, 110, c[mlx->fract], NAME[mlx->fract]);
}

static void	info(t_mlx *mlx)
{
	int c[3];

	c[0] = 0x33FF83;
	c[1] = 0x2584DE;
	c[2] = 0xDE2A25;
	if (KEYCONF->info == 0)
		mlx_string_put(mlx->init, mlx->win, 30, 30, c[mlx->fract], "+");
	else
		display_info(mlx, c);
}

void		onscreentext(t_mlx *mlx)
{
	info(mlx);
}