/*
** tri.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Sun Dec 14 19:38:03 2014 Martin Kinoo
** Last update Fri Dec 19 05:46:02 2014 Martin Kinoo
*/

#include	"taupe.h"

static void	switch_list(t_list *one, t_list *two)
{
  t_list	*tmp;

  two->next->prev = one;
  one->prev->next = two;
  one->next = two->next;
  tmp = one->prev;
  one->prev = two;
  two->next = one;
  two->prev = tmp;
}

int		tri_pid(t_proc *elem1, t_proc *elem2)
{
  if (elem1->pid > elem2->pid)
    return (1);
  return (0);
}

int		tri_user(t_proc *elem1, t_proc *elem2)
{
  if ((my_strcmp(elem1->user, elem2->user)) > 0)
    return (1);
  return (0);
}

int		tri_master(t_list *task, t_menu *menu, t_taupe *taupe)
{
  t_list	*tmp1;
  t_list	*tmp2;

  if (!task)
    return (1);
  tmp1 = task->next;
  tmp2 = tmp1->next;
  while (tmp2->data)
    {
      if ((*(taupe->tri))(tmp1->data, tmp2->data))
	{
	  switch_list(tmp1, tmp2);
	  return (tri_master(task, menu, taupe));
	}
      tmp1 = tmp2;
      tmp2 = tmp2->next;
    }
  init_menu(menu, task);
  return (0);
}
