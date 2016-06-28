
#include "fdf.h"

void	move_image_up(t_win *win)
{
	win->move_ud -= 10;
	erase(win);
}

void	move_image_down(t_win *win)
{
	win->move_ud += 10;
	erase(win);
}

void	move_image_left(t_win *win)
{
	win->move_lr -= 10;
	erase(win);
}

void	move_image_right(t_win *win)
{
	win->move_lr += 10;
	erase(win);
}
