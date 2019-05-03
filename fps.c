/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fps.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 13:40:56 by fhignett       #+#    #+#                */
/*   Updated: 2019/05/03 15:13:56 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

static int seconds(void)
{
    time_t now;
    struct tm *tm;

    now = time(0);
    tm = localtime(&now);
    return (tm->tm_sec);
}

int     frames(void)
{
    static int frames;
    static int prev_sec;
	static int fps;
    int cur_sec;

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
