/*
** print_opt.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Tue Dec 16 21:09:05 2014 Martin Kinoo
** Last update Fri Dec 19 05:07:41 2014 Martin Kinoo
*/

#include	"taupe.h"

static void	print_menu_line(char *str, t_win *win, int color)
{
  wattron(win->win, COLOR_PAIR(color));
  wprintw(win->win, "%-12s\n", str);
}

void		print_signal(t_opt *opt, int pid)
{
  wprintw(opt->top->win, "Pid:%-8d\n", pid);
}

void		print_opt(t_opt *opt, char *str)
{
  t_list	*nav;
  int		tmp;

  wclear(opt->top->win);
  wclear(opt->win->win);
  wattron(opt->top->win, COLOR_PAIR(2));
  wprintw(opt->top->win, "%-12s\n", str);
  init_menu(opt->menu, opt->list);
  nav = opt->menu->first;
  tmp = opt->menu->len;
  while (tmp)
    {
      if (!(nav->data))
	tmp = 1;
      else if (nav == opt->menu->select)
	print_menu_line(nav->data, opt->win, 1);
      else
	print_menu_line(nav->data, opt->win, 9);
      nav = nav->next;
      tmp--;
    }
}
