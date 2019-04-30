/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 15:22:41 by fhignett       #+#    #+#                */
/*   Updated: 2019/04/30 16:31:19 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Z0 = 0
** Zn+1 = Zn"2 + C
*/

t_colour	calc_colour(double c, int min, int max, t_colour min_c, t_colour max_c)
{
	c = ft_map(c, min, max, 0, 1);
	c = ft_clamp(0, 1, c);
	return (set_colour((min_c.r * (1 - c) + max_c.r * c),
	(min_c.g * (1 - c)	+ max_c.g * c),
	(min_c.b * (1 - c)	+ max_c.b * c)));
}

// void			draw_mandel(t_mlx *mlx, int x, int y)
// {
// 	double a;
// 	double b;
// 	double tmpa;
// 	double tmpb;
// 	double oga;
// 	double ogb;
// 	t_colour c;
// 	int n;
// 	int z;
	
// 	a = ft_map(x, 0, WIDTH, mlx->keyconf->a_min, mlx->keyconf->a_plus);
// 	b = ft_map(y, 0, HEIGHT, mlx->keyconf->b_min, mlx->keyconf->b_plus);
// 	oga = a;
// 	ogb = b;
// 	n = 0;
// 	while (n < mlx->keyconf->itter)
// 	{
// 		tmpa = a * a - b * b;
// 		tmpb = 2 * a * b;
// 		a = tmpa + oga;
// 		b = tmpb + ogb;
// 		if (fabs(tmpa + tmpb) > mlx->keyconf->stop)
// 			break ;
// 		n++;
// 	}
// 	c = calc_colour(n, 0, mlx->keyconf->itter, BLACK, NEON);
// 	if (n == (mlx->keyconf->itter))
// 		c = WHITE;
// 	put_pixel(x, y, mlx, c); 
// }

void			draw_mandel(t_mlx *mlx, double x, double y)
{
	double a = 0;
	double b = 0;
	double tmp;
	int i;
	t_colour c;

	for (i = 0; i < mlx->keyconf->itter; i++)
	{
		tmp = a * a - b * b + ft_map(x, 0, WIDTH, mlx->keyconf->a_min, mlx->keyconf->a_plus);
		b = 2 * a * b + ft_map(y, 0, HEIGHT, mlx->keyconf->b_min, mlx->keyconf->b_plus);
		a = tmp;
		if (fabs(a + b) > mlx->keyconf->stop)
			break ;
	}
	c = calc_colour(i, 0, mlx->keyconf->itter, BLACK, NEON);
	if (i == (mlx->keyconf->itter))
		c = WHITE;
	put_pixel(x, y, mlx, c);
}

// void			draw_mandel(t_mlx *mlx, double x, double y)
// {

// }
