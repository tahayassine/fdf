/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 18:59:24 by tyassine          #+#    #+#             */
/*   Updated: 2016/06/29 19:00:06 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_image_up(t_win *win)
{
	win->move_ud -= 10;
	erase(win);
}

void	move_image_down(t_win *win)
{
	win->move_ud += 10;
	erase(win);
}

void	move_image_left(t_win *win)
{
	win->move_lr -= 10;
	erase(win);
}

void	move_image_right(t_win *win)
{
	win->move_lr += 10;
	erase(win);
}
