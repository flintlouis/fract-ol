/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandel42.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 15:22:41 by fhignett       #+#    #+#                */
/*   Updated: 2019/05/06 13:42:19 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static	t_point		set_point(t_mlx *mlx, double x, double y)
{
	t_point	point;

	point = (t_point) {
		ft_map(x, 0, HEIGHT, -4, 1) * KEYCONF->zoom + KEYCONF->x_pos,
		ft_map(y, 0, HEIGHT, -2.5, 2.5) * KEYCONF->zoom + KEYCONF->y_pos};
	return (point);
}

static	void		*draw_mandel42(t_mlx *mlx, double x, double y)
{
	t_point	point;
	t_point	pos;
	double	tmp;
	double	i;

	i = 0;
	point = (t_point){mlx->point.x / WIDTH, mlx->point.y / HEIGHT};
	pos = set_point(mlx, x, y);
	while (fabs(point.x + point.y) < 6 && i < KEYCONF->itter[1])
	{
		tmp = (point.x * point.x - point.y * point.y) + pos.x;
		point.y = 2 * point.x * point.y + pos.y;
		point.x = tmp;
		i++;
	}
	if (i == KEYCONF->itter[1])
		put_pixel(x, y, mlx, BLACK);
	else
	{
		i = calc_i(i, mlx, point);
		put_pixel(x, y, mlx,
		calc_colour(i, KEYCONF->itter, BLACK, (t_colour){0xB3, 0x85, 0xCD}));
	}
	return (NULL);
}

void				*mandel42(void *data)
{
	int		x;
	t_mlx	*mlx;

	x = 0;
	mlx = (t_mlx*)data;
	while (mlx->y[0] < mlx->y[1])
	{
		draw_mandel42(mlx, x, mlx->y[0]);
		calc_pixel_pos(&x, &mlx->y[0]);
	}
	return (0);
}
