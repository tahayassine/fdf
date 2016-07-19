/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 18:59:30 by tyassine          #+#    #+#             */
/*   Updated: 2016/07/19 17:26:01 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**create_map(t_win *win)
{
	t_point	**grid;
	int		i;
	char	*temp;

	i = 0;
	win->map_w = 0;
	grid = (t_point **)malloc(sizeof(t_point *) * len_tab(win->fd));
	win->fd = open(win->av, O_RDONLY);
	while (get_next_line(win->fd, &temp))
	{
		grid[i] = create_int_table(win, temp, i);
		i++;
	}
	close(win->fd);
	win->map_h = i;
	return (grid);
}

t_point		*create_int_table(t_win *win, char *str, int pos)
{
	t_point	*list;
	char	**str_lst;
	int		i;
	int		size;

	i = 0;
	str_lst = ft_strsplit(str, ' ');
	size = count_map_length(str_lst);
	win->map_w = (size > win->map_w) ? size : win->map_w;
	list = (t_point *)malloc(sizeof(t_point) * (win->map_w + 1));
	while (str_lst[i] != NULL)
	{
		win->max_z = ((ft_atoi(str_lst[i])) > win->max_z) ? ft_atoi(str_lst[i])
		: win->max_z;
		list[i] = ft_create_point(str_lst[i], i, pos);
		i++;
	}
	while (i < win->map_w)
	{
		list[i] = ft_create_point("0", i, pos);
		i++;
	}
	return (list);
}

t_point		ft_create_point(char *str, int x, int y)
{
	t_point point;

	point.d3x = x;
	point.d3y = y;
	point.d3z = ft_atoi(str);
	return (point);
}
