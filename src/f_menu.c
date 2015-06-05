/*
** f_menu.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Mon Dec 15 05:48:55 2014 Martin Kinoo
** Last update Fri Jun  5 22:17:41 2015 Martin Kinoo
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"taupe.h"

static void	hide_menu(t_taupe *taupe, t_opt *act)
{
  act->on = 0;
  wclear(taupe->main->win);
  wclear(taupe->main_top->win);
  delwin(taupe->main->win);
  taupe->menu = taupe->task->menu;
  delwin(taupe->main_top->win);
  taupe->bottom_mess = my_strdup("F3 SortBy    F4 Kill");
  main_win(5, 0, taupe);
}

void		f_manager(t_taupe *taupe, t_opt *act, t_opt *pas)
{
  t_proc	*cast;

  if (pas->on)
    return ;
  if (act->on)
    hide_menu(taupe, act);
  else if (!(act->on))
    {
      act->on = 1;
      cast = taupe->task->menu->select->data;
      taupe->pid = cast->pid;
      taupe->menu = act->menu;
      act->menu->select = act->list->next;
      act->menu->dist = 0;
      wclear(taupe->main->win);
      wclear(taupe->main_top->win);
      delwin(taupe->main->win);
      delwin(taupe->main_top->win);
      free(taupe->bottom_mess);
      taupe->bottom_mess = act->str;
      main_win(5, 14, taupe);
    }
}
