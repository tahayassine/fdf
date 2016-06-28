
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
		ft_putstr("Inser map here !");
	return (0);
}
