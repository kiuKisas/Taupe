/*
** main.c for taupe in /home/kinoo_m/rendu/taupe
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Mon Dec  8 16:45:48 2014 Martin Kinoo
** Last update Fri Jun  5 22:20:48 2015 Martin Kinoo
*/

#include		<stdlib.h>
#include		<curses.h>
#include		<sys/select.h>
#include		<sys/time.h>
#include		<sys/types.h>
#include		<unistd.h>
#include		"taupe.h"

static void		my_refresh(t_taupe *taupe)
{
  wrefresh(taupe->top->win);
  wrefresh(taupe->main_top->win);
  wrefresh(taupe->main_bottom->win);
  if (taupe->sort->on)
    {
      wrefresh(taupe->sort->top->win);
      wrefresh(taupe->sort->win->win);
    }
  else if (taupe->signal->on)
    {
      wrefresh(taupe->signal->top->win);
      wrefresh(taupe->signal->win->win);
    }
  wrefresh(taupe->main->win);
}

static void		my_init_color()
{
  initscr();
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_BLUE);
  init_pair(2, COLOR_BLACK, COLOR_GREEN);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_GREEN, COLOR_BLACK);
  init_pair(6, COLOR_YELLOW, COLOR_BLACK);
  init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(8, COLOR_CYAN, COLOR_BLACK);
  init_pair(9, COLOR_WHITE, COLOR_BLACK);
}

static void		init_curses(t_taupe *taupe)
{
  if (!(taupe->top = xmalloc(sizeof(t_win))) ||
      !(taupe->main = xmalloc(sizeof(t_win))) ||
      !(taupe->main_top = xmalloc(sizeof(t_win))) ||
      !(taupe->main_bottom = xmalloc(sizeof(t_win))))
    exit(1);
  cbreak();
  noecho();
  curs_set(0);
  main_win(5, 0, taupe);
  taupe->task->menu->len = LINES - 8;
  top_win(taupe->top);
  keypad(taupe->top->win, TRUE);
  signal_win(taupe->signal, 5);
  sort_win(taupe->sort, 5);
  taupe->bottom_mess = my_strdup("F3 Sort    F4 Kill");
  taupe->menu = taupe->task->menu;
  taupe->tri = &tri_cpu;
}

static int		launch_my_taupe(t_taupe *taupe)
{
  fd_set		fd;
  struct timeval	tv;

  my_init_color();
  init_curses(taupe);
  if (data_hub(taupe))
    return (1);
  while (42)
    {
      print_hub(taupe);
      my_refresh(taupe);
      FD_ZERO(&fd);
      FD_SET(0, &fd);
      tv.tv_sec = 1;
      tv.tv_usec = 0;
      select(1, &fd, NULL, NULL, &tv);
      if (FD_ISSET(0, &fd))
	keypad_manager(taupe);
      else if (data_hub(taupe))
	return (1);
    }
  return (0);
}

int			main(void)
{
  t_taupe		*taupe;

  if (!(taupe = init_my_taupe()))
    return (1);
  launch_my_taupe(taupe);
  endwin();
  return (0);
}
