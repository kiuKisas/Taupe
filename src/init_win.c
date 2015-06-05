/*
** init_win.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Thu Dec 11 16:23:18 2014 Martin Kinoo
** Last update Tue Dec 16 21:50:21 2014 Martin Kinoo
*/

#include	<curses.h>
#include	"taupe.h"

void		main_win(int top, int startx, t_taupe *taupe)
{
  int		starty;
  int		height;
  int		width;

  taupe->main->height = LINES - top - 2;
  taupe->main->width = COLS - startx;
  starty = ((LINES - taupe->main->height) / 2) + 3;
  height = taupe->main->height;
  width = taupe->main->width;
  taupe->main->win = newwin(height - 1, width, starty + 1, startx);
  taupe->main_top->win = newwin(1, width, starty, startx);
  taupe->main_bottom->win = newwin(1, width + startx, LINES - 1, 0);
  wbkgd(taupe->main_top->win, COLOR_PAIR(2));
  wbkgd(taupe->main_bottom->win, COLOR_PAIR(2));
}

void		top_win(t_win *top)
{
  int		startx;
  int		starty;

  top->height = 5;
  top->width = COLS;
  starty = 0;
  startx = 0;
  top->win = newwin(top->height, top->width, starty, startx);
  box(top->win, 0, 0);
}
