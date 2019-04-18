/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:01:26 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/27 14:34:13 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_fractol(t_mlx *mlx)
{
	return (0);
}

t_mlx		*init_window(char **argv)
{
	t_mlx	*mlx;

	mlx = MEM(t_mlx);
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "Fractol");
	mlx->image = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	mlx->data_addr = mlx_get_data_addr(mlx->image, &(mlx->bits_per_pixel),
	&(mlx->size_line), &(mlx->endian));
	mlx->argv = argv;
	return (mlx);
}

void		init_fractol(char **argv)
{
	t_mlx	*mlx;

	(void)argv;
	mlx = init_window(argv);
	mlx_hook(mlx->win, 2, 1L << 0, press_key, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, close_window, NULL);

	mlx_loop_hook(mlx->init, ft_fractol, mlx);

	mlx_loop(mlx->init);
}

int			main(int argc, char **argv)
{
	if (argc <= 1)
		ft_putendl("Usage: ./fractol [fractolname]");
	else
		init_fractol(&argv[1]);
	return (0);
}
