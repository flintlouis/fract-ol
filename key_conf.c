/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_conf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 14:18:18 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/27 14:28:20 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		close_window(void *ptr)
{
	(void)ptr;
	exit(0);
	return (0);
}

int		press_key(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == KEY_ESC)
		close_window(NULL);
	return (0);
}
