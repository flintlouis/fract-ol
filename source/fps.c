/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fps.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 13:40:56 by fhignett       #+#    #+#                */
/*   Updated: 2019/05/06 12:05:05 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

static int	seconds(void)
{
	time_t		now;
	struct tm	*tijd;

	now = time(0);
	tijd = localtime(&now);
	return (tijd->tm_sec);
}

int			frames(void)
{
	static int	frames;
	static int	prev_sec;
	static int	fps;
	int			cur_sec;

	frames++;
	cur_sec = seconds();
	if (cur_sec != prev_sec)
	{
		prev_sec = cur_sec;
		fps = frames;
		frames = 0;
		return (fps);
	}
	return (fps);
}
