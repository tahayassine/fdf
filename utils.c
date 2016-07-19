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

int		len_tab(int fd)
{
	char	*buff;
	int		ret;
	int		size;

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

int		check_type_file(char *str, char *type)
{
	while ((*str) != '\0')
	{
		if (*str == '.' && ft_strequ(str + 1, type) == 1)
		{
			return (1);
		}
		str++;
	}
	return (0);
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
