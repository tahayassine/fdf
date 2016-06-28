

#include "fdf.h"

void	para_projection(t_win *win)
{
	win->opt = PARA;
	erase(win);
}

void	iso_projection(t_win *win)
{
	win->opt = ISO;
	erase(win);
}

void	re_mode(t_win *win)
{
	win->cte1 = 0.5;
	win->cte2 = 0.2;
	win->pad = 15;
	win->opt = PARA;
	win->pad_h = 5;
	win->move_lr = 1;
	win->move_ud = 1;
	erase(win);
}
