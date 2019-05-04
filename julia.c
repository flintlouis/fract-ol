/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 15:22:41 by fhignett       #+#    #+#                */
/*   Updated: 2019/05/04 17:46:54 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

/*
** the (i) calculation smooths the colour gradient
*/

static	void		*draw_julia(t_mlx *mlx, double x, double y)
{
	t_point point;
	t_point pos;
	double tmp;
	double i;

	pos = (t_point){mlx->point.x / WIDTH, mlx->point.y / HEIGHT};
	point = (t_point){
		ft_map(x, 0, HEIGHT, -3.7, 1.3)  * KEYCONF->zoom + KEYCONF->x_pos,
		ft_map(y, 0, HEIGHT, -2.5, 2.5) * KEYCONF->zoom + KEYCONF->y_pos};
	for (i = 0; i < KEYCONF->itter[1]; i++)
	{
		tmp = (point.x * point.x - point.y * point.y) + pos.x;
		point.y = 2 * point.x * point.y + pos.y;
		point.x = tmp;
		if (fabs(point.x + point.y) > 6)
			break ;
	}
	if (i == KEYCONF->itter[1])
		put_pixel(x, y, mlx, BLACK);
	else
	{
		i = i - log2(log2(fabs(point.x * point.x + point.y * point.y))) + KEYCONF->glow;
		put_pixel(x, y, mlx, calc_colour(i, KEYCONF->itter, BLACK, FCOLOURS[mlx->colour]));
	}
	return (NULL);
}

void				*julia(void *data)
{
	int 		x;
	t_mlx		*mlx;

	x = 0;
	mlx = (t_mlx*)data;
	while (mlx->y[0] < mlx->y[1])
	{
		draw_julia(mlx, x, mlx->y[0]);
		calc_pixel_pos(&x, &mlx->y[0]);
	}
	return (0);
}
