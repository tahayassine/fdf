/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 18:57:58 by tyassine          #+#    #+#             */
/*   Updated: 2016/06/29 19:02:34 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_win	win;

	win.path = argv[1];
	if (argc == 2)
	{
		ft_import_map(&win);
	}
	else
		ft_putstr("Error: induce map in argument!");
	return (0);
}
