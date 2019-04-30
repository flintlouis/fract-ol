/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:01:26 by nvreeke        #+#    #+#                */
/*   Updated: 2019/04/30 16:37:27 by fhignett      ########   odam.nl         */
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

static int			mandel(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		draw_mandel(mlx, x, y);
		calc_pixel(&x, &y);
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->image, 0, 0);
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

void		init_fractol(char *fract)
{
	t_mlx	*mlx;

	mlx = init_window();
	init_keyconf(mlx);
	mlx_loop_hook(mlx->init, mandel, mlx);
	
	mlx_hook(mlx->win, 2, 1L << 0, press_key, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, close_window, NULL);

	mlx_loop(mlx->init);
}

int			main(int argc, char **argv)
{
	if (argc != 2)
		ft_putendl("Usage: ./fractol [fractolname]");
	else
		init_fractol(argv[1]);
	return (0);
}
