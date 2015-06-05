
/*
** menu.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Sun Dec 14 19:11:45 2014 Martin Kinoo
** Last update Mon Dec 15 01:17:10 2014 Martin Kinoo
*/

#include	<stdlib.h>
#include	"taupe.h"

void		init_menu(t_menu *menu, t_list *list)
{
  int		tmp;

  if (!(menu->select))
    {
      menu->select = list->next;
      menu->dist = 0;
      menu->first = menu->select;
    }
  else
    {
      if (menu->dist >= menu->len)
	(menu->dist)--;
      else if (menu->dist < 0)
	menu->dist = 0;
      tmp = menu->dist;
      menu->first = menu->select;
      while (menu->first->prev->data && tmp)
	{
	  menu->first = menu->first->prev;
	  tmp--;
	}
    }
}

void		del_menu(t_menu *menu)
{
  menu->first = NULL;
  menu->select = NULL;
  menu->dist = 0;
}
