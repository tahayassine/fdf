

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