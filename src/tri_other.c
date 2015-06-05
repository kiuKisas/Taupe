/*
** tri_other.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Fri Dec 19 05:35:47 2014 Martin Kinoo
** Last update Fri Dec 19 05:56:14 2014 Martin Kinoo
*/

#include	"taupe.h"

int		tri_cpu(t_proc *elem1, t_proc *elem2)
{
  if (elem1->cpu < elem2->cpu)
    return (1);
  return (0);
}

int		tri_mem(t_proc *elem1, t_proc *elem2)
{
  if (elem1->mem < elem2->mem)
    return (1);
  return (0);
}

int		tri_time(t_proc *elem1, t_proc *elem2)
{
  if (elem1->sec < elem2->sec)
    return (1);
  return (0);
}

int		tri_state(t_proc *elem1, t_proc *elem2)
{
  if (elem1->status > elem2->status)
    return (1);
  return (0);
}

int		tri_command(t_proc *elem1, t_proc *elem2)
{
  if ((my_strcmp(elem1->command, elem2->command)) > 0)
    return (1);
  return (0);
}
