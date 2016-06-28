

#include "fdf.h"

void	zoom_map(t_win *win)
{
	win->pad += 1;
	erase(win);
}

void	de_zoom_map(t_win *win)
{
	win->pad -= 1;
	erase(win);
}
