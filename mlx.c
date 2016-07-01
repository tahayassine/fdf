/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 18:59:10 by tyassine          #+#    #+#             */
/*   Updated: 2016/06/29 18:59:14 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_import_map(t_win *win)
{
	win->init = mlx_init();
	win->win = mlx_new_window(win->init, WIN_W, WIN_H, "FdF");
	win->cte1 = 0.5;
	win->cte2 = 0.3;
	win->pad = 15;
	win->opt = PARA;
	win->pad_h = 1;
	win->move_lr = 1;
	win->move_ud = 1;
	win->img = mlx_new_image(win->init, WIN_W, WIN_H);
	win->data = mlx_get_data_addr(win->img, &(win->color), &(win->size),
		&(win->endian));
	win->map = create_map(win);
	mlx_key_hook(win->win, key_hook, win);
	mlx_mouse_hook(win->win, mouse_hook, win);
	mlx_expose_hook(win->win, expose_hook, win);
	mlx_loop(win->init);
	(void)win;
}

int		expose_hook(t_win *win)
{
	calcule_coord(win);
	mlx_put_image_to_window(win->init, win->win, win->img, 0, 0);
	return (0);
	(void)win;
}

int		key_hook(int keycode, t_win *win)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		zoom_map(win);
	if (keycode == 78)
		de_zoom_map(win);
	if (keycode == 126)
		move_image_up(win);
	if (keycode == 125)
		move_image_down(win);
	if (keycode == 123)
		move_image_left(win);
	if (keycode == 124)
		move_image_right(win);
	if (keycode == 35)
		para_projection(win);
	if (keycode == 34)
		iso_projection(win);
	if (keycode == 49)
		re_mode(win);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_win *win)
{
	if (button == 1)
		increase_pike(win);
	if (button == 2)
		decrease_pike(win);
	(void)x;
	(void)y;
	return (0);
}
