/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_fract.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:01:26 by nvreeke        #+#    #+#                */
/*   Updated: 2019/05/04 17:25:28 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <pthread.h>

/*
** Copy mlx data into data[i]
** Change new mlx data (data[i]) to have new start and end y
** Create the thread with data[i]
** Join thread threads[i]
*/

static	void	join_threads(int i, pthread_t *threads)
{
	while (i > 0)
	{
		i--;
		pthread_join(threads[i], NULL);
	}
}

static	int		start_fract(t_mlx *mlx)
{
	int			i;
	t_mlx		data[THREAD];
	pthread_t	threads[THREAD];

	i = 0;
	if (mlx->disco == 1)
		mlx->colour = (mlx->colour + 1) % 3;
	while (i < THREAD)
	{
		ft_memcpy(&data[i], mlx, sizeof(t_mlx));
		data[i].y[0] = (HEIGHT / THREAD) * i;
		data[i].y[1] = (HEIGHT / THREAD) * (i + 1);
		if (mlx->fract == 0)
			pthread_create(&threads[i], NULL, mandel, &data[i]);
		else if (mlx->fract == 1)
			pthread_create(&threads[i], NULL, julia, &data[i]);
		else
			pthread_create(&threads[i], NULL, ship, &data[i]);
		i++;
	}
	join_threads(i, threads);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->image, 0, 0);
	onscreentext(mlx);
	return (0);
}

static t_mlx	*init_window(void)
{
	t_mlx	*mlx;

	mlx = MEM(t_mlx);
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "Fractol");
	mlx->image = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	mlx->data_addr = mlx_get_data_addr(mlx->image, &(mlx->bits_per_pixel),
	&(mlx->size_line), &(mlx->endian));
	return (mlx);
}

void			init_fractol(int fract)
{
	t_mlx	*mlx;

	mlx = init_window();
	mlx->fract = fract;
	init_keyconf(mlx);
	mlx_loop_hook(mlx->init, start_fract, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, mouse_press, mlx);
	mlx_hook(mlx->win, 5, 1L << 3, mouse_release, mlx);
	mlx_hook(mlx->win, 6, 1L << 6, mouse_move, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, press_key, mlx);
	mlx_hook(mlx->win, 3, 1L << 1, release_key, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, close_window, NULL);
	mlx_loop(mlx->init);
}
