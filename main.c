/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:01:26 by nvreeke        #+#    #+#                */
/*   Updated: 2019/05/03 17:28:51 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int			start_fract(t_mlx *mlx)
{
	int			i;
	t_mlx		data[THREAD];
	pthread_t	threads[THREAD];

	i = 0;
	while (i < THREAD)
	{
		// Copy mlx data into data[i].
		ft_memcpy(&data[i], mlx, sizeof(t_mlx));
		// Change new mlx data (data[i]) to have x new start and end y.
		data[i].y[0] = (HEIGHT / THREAD) * i;
		data[i].y[1] = (HEIGHT / THREAD) * (i + 1);
		// Create the thread with data[i].
		if (mlx->fract == 0)
			pthread_create(&threads[i], NULL, mandel, &data[i]);
		else if (mlx->fract == 1)
			pthread_create(&threads[i], NULL, julia, &data[i]);
		else
			pthread_create(&threads[i], NULL, ship, &data[i]);
		i++;
	}
	while (i > 0)
	{
		i--;
		// Join thread threads[i].
		pthread_join(threads[i], NULL);
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->image, 0, 0);
	onscreentext(mlx);
	return (0);
}

static t_mlx		*init_window(void)
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

static	int		check_fract(char *fract)
{
	if (ft_strequ(fract, "mandel"))
		return (0);
	else if (ft_strequ(fract, "julia"))
		return (1);
	else if (ft_strequ(fract, "ship"))
		return (2);
	return (0);
}

static	void		init_fractol(int fract)
{
	t_mlx	*mlx;

	mlx = init_window();
	mlx->fract = fract;
	init_keyconf(mlx);
	//get time sla op in static var
	//frames/ get time
	mlx_loop_hook(mlx->init, start_fract, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, mouse_press, mlx);
	mlx_hook(mlx->win, 5, 1L << 3, mouse_release, mlx);
	mlx_hook(mlx->win, 6, 1L << 6, mouse_move, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, press_key, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, close_window, NULL);
	mlx_loop(mlx->init);
}

int			main(int argc, char **argv)
{
	int fract;

	if (argc != 2)
		USAGE;
	else
	{
		fract = check_fract(argv[1]);
		ft_putendl(NAME[fract]);
		if (fract == -1)
			USAGE;
		else
			init_fractol(fract);
	}
	return (0);
}
