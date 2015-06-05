/*
** tri_extra.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Fri Dec 19 05:29:09 2014 Martin Kinoo
** Last update Fri Dec 19 05:49:52 2014 Martin Kinoo
*/

#include	<stdlib.h>
#include	"taupe.h"

int		tri_pri(t_proc *elem1, t_proc *elem2)
{
  if (atoi(elem1->pr) > atoi(elem2->pr))
    return (1);
  return (0);
}

int		tri_nice(t_proc *elem1, t_proc *elem2)
{
  if (elem1->nice > elem2->nice)
    return (1);
  return (0);
}

int		tri_virt(t_proc *elem1, t_proc *elem2)
{
  if (elem1->virt < elem2->virt)
    return (1);
  return (0);
}

int		tri_res(t_proc *elem1, t_proc *elem2)
{
  if (elem1->res < elem2->res)
    return (1);
  return (0);
}

int		tri_shr(t_proc *elem1, t_proc *elem2)
{
  if (elem1->shr < elem2->shr)
    return (1);
  return (0);
}
