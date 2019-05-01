/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 15:22:41 by fhignett       #+#    #+#                */
/*   Updated: 2019/05/01 16:27:25 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			calc_pixel(int *x, int *y)
{
	if (*x == (WIDTH - 1))
	{
		*y += 1;
		*x = 0;
	}
	else
		*x += 1;
}

static	void		*draw_mandel(t_mlx *mlx, double x, double y)
{
	t_point point;
	t_point pos;
	double tmp;
	double i;

	pos = (t_point){
		ft_map(x, 0, HEIGHT, -4, 1)  * KEYCONF->zoom + KEYCONF->x_pos,
		ft_map(y, 0, HEIGHT, -2.5, 2.5) * KEYCONF->zoom + KEYCONF->y_pos};

	point = (t_point){pos.x, pos.y};
	for (i = 0; i < KEYCONF->itter; i++)
	{
		tmp = (point.x * point.x - point.y * point.y) + pos.x;
		point.y = 2 * point.x * point.y + pos.y;
		point.x = tmp;
		if (fabs(point.x + point.y) > 6)
			break ;
	}
	if (i == KEYCONF->itter)
		put_pixel(x, y, mlx, BLACK);
	else
	{
		// smooths itteration
		i = i - log2(log2(fabs(point.x * point.x + point.y * point.y))) + KEYCONF->glow;
		put_pixel(x, y, mlx, calc_colour(i, 0, KEYCONF->itter, BLACK, NEON));
	}
	return (NULL);
}

static void				*mandel(void *data)
{
	int 		x;
	t_mlx		*mlx;

	x = 0;
	mlx = (t_mlx*)data;
	while (mlx->y[0] < mlx->y[1])
	{
		draw_mandel(mlx, x, mlx->y[0]);
		calc_pixel(&x, &mlx->y[0]);
	}
	return (0);
}

int				start_mandel(t_mlx *mlx)
{
	int			i;
	t_mlx		data[12];
	pthread_t	threads[12];

	i = 0;
	while (i < 12)
	{
		// Copy mlx data into data[i].
		ft_memcpy(&data[i], mlx, sizeof(t_mlx));
		// Change new mlx data (data[i]) to have x new start and end y.
		data[i].y[0] = (HEIGHT / 12) * i;
		data[i].y[1] = (HEIGHT / 12) * (i + 1);
		// Create the thread with data[i].
		pthread_create(&threads[i], NULL, mandel, &data[i]);
		i++;
	}
	while (i > 0)
	{
		i--;
		// Join thread threads[i].
		pthread_join(threads[i], NULL);
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->image, 0, 0);
	return (0);
}