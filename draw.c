/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 18:58:33 by tyassine          #+#    #+#             */
/*   Updated: 2016/06/29 19:05:36 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_map(t_win *win)
{
	int i;
	int j;

	j = 0;
	while (j < win->map_h)
	{
		i = 0;
		while (i < win->map_w)
		{
			if (i < win->map_w - 1)
				draw_line(win, &(win->map[j][i]), &(win->map[j][i + 1]));
			if (j < win->map_h - 1)
				draw_line(win, &(win->map[j][i]), &(win->map[j + 1][i]));
			i++;
		}
		j++;
	}
}

void		draw_line(t_win *win, t_point *point1, t_point *point2)
{
	int		x;
	int		y;
	int		e2;
	t_bres	*bres;

	bres = bres_construct(point1, point2, (win->max_z * win->pad_h));
	x = point1->d2x;
	y = point1->d2y;
	while (1)
	{
		if ((check_x(win, x) && check_y(win, y)))
			draw_point(win, create_x(win, x), create_y(win, y), point1->color);
		if (x == point2->d2x && y == point2->d2y)
			break ;
		if ((e2 = bres->delta_error) > -(bres->delta_x))
		{
			bres->delta_error -= bres->delta_y;
			x += bres->sign_x;
		}
		if (e2 < bres->delta_y)
		{
			bres->delta_error += bres->delta_x;
			y += bres->sign_y;
		}
	}
}

void		draw_point(t_win *win, int x, int y, int color)
{
	ft_memcpy(&win->data[(x * 4) + (y * win->size)], &(color),
			(size_t)(sizeof(int)));
}

int			choose_color(int p1, int p2, int max)
{
	max = max + 1;
	if (((p1 + p2) / 2) > 0)
		return (GREY);
	else if (((p1 + p2) / 2) == 0)
		return (GREEN);
	else if (((p1 + p2) / 2) < 0)
		return (BLUE);
	else
		return (WHITE);
}

t_bres		*bres_construct(t_point *point1, t_point *point2, int max)
{
	t_bres *bres;

	bres = (t_bres *)malloc(sizeof(t_bres));
	bres->delta_x = abs(point2->d2x - point1->d2x);
	bres->sign_x = point1->d2x < point2->d2x ? 1 : -1;
	bres->delta_y = abs(point2->d2y - point1->d2y);
	bres->sign_y = point1->d2y < point2->d2y ? 1 : -1;
	bres->delta_error = (bres->delta_x > bres->delta_y ? bres->delta_x :
		-(bres->delta_y))
	/ 2;
	point1->color = choose_color(point1->d3z, point2->d3z, max);
	return (bres);
}
