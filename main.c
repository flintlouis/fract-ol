/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/04 17:24:22 by fhignett       #+#    #+#                */
/*   Updated: 2019/05/04 17:25:33 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		USAGE;
	else
	{
		fract = check_fract(argv[1]);
		if (argc == 3 && fract != -1)
		{
			if (ft_strequ(argv[2], "--options"))
				OPTIONS;
			else
			{
				USAGE;
				return (0);
			}
		}
		if (fract == -1)
			USAGE;
		else
			init_fractol(fract);
	}
	return (0);
}
