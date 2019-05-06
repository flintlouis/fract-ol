/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   burningship.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 15:22:41 by fhignett       #+#    #+#                */
/*   Updated: 2019/05/06 12:06:43 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static	t_point		set_position(t_mlx *mlx, double x, double y)
{
	t_point	pos;

	pos = (t_point){
		ft_map(x, 0, HEIGHT, -4, 1) * KEYCONF->zoom + KEYCONF->x_pos,
		ft_map(y, 0, HEIGHT, -3, 2) * KEYCONF->zoom + KEYCONF->y_pos};
	return (pos);
}

static	void		*draw_ship(t_mlx *mlx, double x, double y)
{
	t_point	point;
	t_point	pos;
	double	tmp;
	double	i;

	i = 0;
	pos = set_position(mlx, x, y);
	point = (t_point){pos.x, pos.y};
	while (fabs(point.x + point.y) < 6 && i < KEYCONF->itter[1])
	{
		tmp = (point.x * point.x - point.y * point.y) + pos.x;
		point.y = fabs(2 * point.x * point.y) + pos.y;
		point.x = tmp;
		i++;
	}
	if (i == KEYCONF->itter[1])
		put_pixel(x, y, mlx, BLACK);
	else
	{
		i = calc_i(i, mlx, point);
		put_pixel(x, y, mlx,
		calc_colour(i, KEYCONF->itter, BLACK, KEYCONF->colours[mlx->colour]));
	}
	return (NULL);
}

void				*ship(void *data)
{
	int		x;
	t_mlx	*mlx;

	x = 0;
	mlx = (t_mlx*)data;
	while (mlx->y[0] < mlx->y[1])
	{
		draw_ship(mlx, x, mlx->y[0]);
		calc_pixel_pos(&x, &mlx->y[0]);
	}
	return (0);
}
