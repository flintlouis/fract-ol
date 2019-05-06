/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/04 17:24:22 by fhignett       #+#    #+#                */
/*   Updated: 2019/05/06 12:48:19 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	options(void)
{
	ft_putendl("Keys :\n\t1\t\t: Mandelbrot\n\t2\t\t: Julia\
\n\t3\t\t: Burningship\n\tW,A,S,D\t\t: Move\n\tUp,Down\t\t: Change itteration\n\
\tLeft,Right\t: Change glow\n\tMouse wheel,-,+\t: Zoom\n\tRight mouse\t: Pause \
Julia\n\tSpace\t\t: Reset [Shift + Space : change colour]\n\tEsc\t\t: Exit");
}

static	void	usage(void)
{
	ft_putendl("Usage:  ./fractol [fractolname] [--options]\n   \
• Mandelbrot\t  : mandel\n   • Julia\t  : julia\n   • Burning Ship : ship");
}

static	int		check_fract(char *fract)
{
	if (ft_strequ(fract, "mandel"))
		return (0);
	else if (ft_strequ(fract, "julia"))
		return (1);
	else if (ft_strequ(fract, "ship"))
		return (2);
	return (-1);
}

int				main(int argc, char **argv)
{
	int fract;

	if (argc != 2 && argc != 3)
		usage();
	else
	{
		fract = check_fract(argv[1]);
		if (argc == 3 && fract != -1)
		{
			if (ft_strequ(argv[2], "--options"))
				options();
			else
			{
				usage();
				return (0);
			}
		}
		if (fract == -1)
			usage();
		else
			init_fractol(fract);
	}
	return (0);
}
