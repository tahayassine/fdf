/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 18:58:46 by tyassine          #+#    #+#             */
/*   Updated: 2016/06/29 19:04:46 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		calcule_coord(t_win *win)
{
	int i;
	int j;

	j = 0;
	while (j < win->map_h)
	{
		i = 0;
		while (i < win->map_w)
		{
			calculate(win, &(win->map[j][i]));
			i++;
		}
		j++;
	}
	draw_map(win);
}

void		calculate(t_win *win, t_point *point)
{
	int act_x;
	int act_y;
	int act_z;

	act_x = point->d3x * win->pad;
	act_y = point->d3y * win->pad;
	act_z = point->d3z * win->pad_h;
	if (win->opt == ISO)
	{
		point->d2x = act_x - act_y + WIN_W * win->cte1;
		point->d2y =
			-act_z + act_x * win->cte1 + act_y * win->cte1 + WIN_H * win->cte2;
	}
	else if (win->opt == PARA)
	{
		point->d2x = act_x - act_z + WIN_W * win->cte1;
		point->d2y = act_y + -1 * win->cte1 * act_z + WIN_H * win->cte2;
	}
}
