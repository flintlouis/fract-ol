/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:01:26 by nvreeke        #+#    #+#                */
/*   Updated: 2019/05/01 16:03:15 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		return (1);
	else if (ft_strequ(fract, "julia"))
		return (2);
	else if (ft_strequ(fract, "ship"))
		return (3);
	return (0);
}

static	void		init_fractol(int fract)
{
	t_mlx	*mlx;

	mlx = init_window();
	init_keyconf(mlx);
	if (fract == 1)
	{
		mlx_loop_hook(mlx->init, start_mandel, mlx);
	}
	mlx_hook(mlx->win, 2, 1L << 0, press_key, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, close_window, NULL);

	mlx_loop(mlx->init);
}

int			main(int argc, char **argv)
{
	int fract;
	
	if (argc != 2)
		ft_putendl("Usage: ./fractol [fractolname]");
	else
	{
		fract = check_fract(argv[1]);
		if (!fract)
			ft_putendl("Usage: ./fractol [fractolname]");
		else
			init_fractol(fract);
	}
	return (0);
}
