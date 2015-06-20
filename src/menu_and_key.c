/*
** menu_and_key.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Sun Dec 14 18:14:16 2014 Martin Kinoo
** Last update Fri Jun 19 18:46:16 2015 Martin Kinoo
*/

#include	<unistd.h>
#include	<curses.h>
#include	"taupe.h"

static void	menu_down(t_menu *menu)
{
  if (!(menu->select->next->data))
    return ;
  if (menu->select->next)
    {
      menu->select = menu->select->next;
      (menu->dist)++;
    }
}

static void	menu_up(t_menu *menu)
{
  if (!(menu->select->prev->data))
    return ;
  if (menu->select->prev)
    {
      menu->select = menu->select->prev;
      (menu->dist)--;
    }
}

static void	change_my_sort(t_taupe *taupe)
{
  int		len;
  t_list	*nav;

  len = 0;
  nav = taupe->sort->list->next;
  while (nav != taupe->sort->menu->select)
    {
      len++;
      nav = nav->next;
    }
  taupe->tri = taupe->f[len];
  taupe->task->menu->select = NULL;
  taupe->task->menu->dist = 0;
}

static void	menu_enter(t_taupe *taupe)
{
  if (taupe->signal->on)
    {
      send_signal(taupe->pid, taupe->signal->menu->select->data);
      f_manager(taupe, taupe->signal, taupe->sort);
    }
  else if (taupe->sort->on)
    {
      change_my_sort(taupe);
      f_manager(taupe, taupe->sort, taupe->signal);
    }
}

void		keypad_manager(t_taupe *taupe)
{
  int		key;

  key = wgetch(taupe->top->win);
  if (key == KEY_DOWN)
    menu_down(taupe->menu);
  else if (key == KEY_UP)
    menu_up(taupe->menu);
  else if (key == KEY_F(3))
    f_manager(taupe, taupe->sort, taupe->signal);
  else if (key == KEY_F(4))
    f_manager(taupe, taupe->signal, taupe->sort);
  else if (key == 10)
    menu_enter(taupe);
  else if (key == 113)
    my_exit(taupe);
}
