/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 18:59:16 by tyassine          #+#    #+#             */
/*   Updated: 2016/06/29 18:59:21 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		increase_pike(t_win *win)
{
	win->pad_h += 1.2;
	erase(win);
}

void		decrease_pike(t_win *win)
{
	win->pad_h -= 1.2;
	erase(win);
}
