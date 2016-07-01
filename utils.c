/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 19:00:29 by tyassine          #+#    #+#             */
/*   Updated: 2016/06/29 19:00:34 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		len_tab(char *argv)
{
	int		fd;
	char	*buff;
	int		ret;
	int		size;

	fd = open(argv, O_RDONLY);
	buff = (char *)ft_strnew(200);
	size = 0;
	while ((ret = read(fd, buff, 200)) > 0)
	{
		size += ret;
	}
	close(fd);
	free(buff);
	return (size);
}

int		count_map_length(char **str)
{
	int		count;

	count = 0;
	while (str[count] != NULL)
		count++;
	return (count);
}

void	erase(t_win *win)
{
	ft_bzero(win->data, WIN_H * WIN_W * 4);
	expose_hook(win);
}
