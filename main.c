/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 18:57:58 by tyassine          #+#    #+#             */
/*   Updated: 2016/07/01 18:45:32 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_win	win;

	if (argc == 2 && (win.fd = open(argv[1], O_RDONLY)) > 0
		&& check_type_file(argv[1], "fdf"))
	{
		win.av = argv[1];
		import_map(&win);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
