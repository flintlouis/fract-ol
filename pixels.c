/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixels.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 12:54:42 by fhignett       #+#    #+#                */
/*   Updated: 2019/05/02 11:18:22 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		calc_pixel_pos(int *x, int *y)
{
	if (*x == (WIDTH - 1))
	{
		*y += 1;
		*x = 0;
	}
	else
		*x += 1;
}

void		put_pixel(int x, int y, t_mlx *mlx, t_colour colour)
{
	int i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * mlx->bits_per_pixel / 8) + (y * mlx->size_line);
		mlx->data_addr[i] = colour.b;
		i++;
		mlx->data_addr[i] = colour.g;
		i++;
		mlx->data_addr[i] = colour.r;
	}
}

t_colour	set_colour(t_byte r, t_byte g, t_byte b)
{
	t_colour c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_colour	calc_colour(double c, int min, int max, t_colour min_c, t_colour max_c)
{
	c = ft_map(c, min, max, 0, 1);
	c = ft_clamp(0, 1, c);
	return (set_colour(
	(min_c.r * (1 - c) + max_c.r * c),
	(min_c.g * (1 - c) + max_c.g * c),
	(min_c.b * (1 - c) + max_c.b * c)));
}
