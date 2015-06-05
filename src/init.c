/*
** init.c for moulin in /home/kinoo_m/rendu/taupe
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Tue Dec  9 16:58:47 2014 Martin Kinoo
** Last update Fri Dec 19 06:12:34 2014 Martin Kinoo
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"taupe.h"

static void	*my_memset(char *res, size_t size)
{
  size_t	i;

  i = 0;
  while (i < size)
    {
      res[i] = '\0';
      i++;
    }
  return (res);
}

void            *xmalloc(int size)
{
  void          *res;

  if ((res = malloc(size)) == NULL)
    {
      write(2, "malloc failed.\n", 15);
      return (NULL);
    }
  return (my_memset(res, size));
}

void		init_task_pars_and_tri(t_task *task, t_taupe *taupe)
{
  char		*tmp;

  tmp = my_strdup("Name: State: Uid:");
  if (!(task->pars = init_pars(my_str_to_wordtab(tmp, ' '))))
    my_error("can't malloc task->pars");
  taupe->f[0] = &tri_pid;
  taupe->f[1] = &tri_user;
  taupe->f[2] = &tri_pri;
  taupe->f[3] = &tri_nice;
  taupe->f[4] = &tri_virt;
  taupe->f[5] = &tri_res;
  taupe->f[6] = &tri_shr;
  taupe->f[7] = &tri_state;
  taupe->f[8] = &tri_cpu;
  taupe->f[9] = &tri_mem;
  taupe->f[10] = &tri_time;
  taupe->f[11] = &tri_command;
}

t_taupe		*init_my_taupe()
{
  t_taupe	*taupe;
  char		*tmp;

  if (!(taupe = xmalloc(sizeof(t_taupe))) ||
      !(taupe->sys = xmalloc(sizeof(t_sys))) ||
      !(taupe->task = xmalloc(sizeof(t_task))) ||
      !(taupe->cpu = xmalloc(sizeof(t_cpu))) ||
      !(taupe->mem = xmalloc(sizeof(t_mem))) ||
      !(taupe->old = xmalloc(sizeof(t_cpu))) ||
      !(taupe->signal = xmalloc(sizeof(t_opt))) ||
      !(taupe->sort = xmalloc(sizeof(t_opt))) ||
      !(taupe->signal->win = xmalloc(sizeof(t_win))) ||
      !(taupe->sort->win = xmalloc(sizeof(t_win))) ||
      !(taupe->signal->top = xmalloc(sizeof(t_win))) ||
      !(taupe->sort->top = xmalloc(sizeof(t_win))) ||
      !(taupe->signal->menu = xmalloc(sizeof(t_menu))) ||
      !(taupe->sort->menu = xmalloc(sizeof(t_menu))))
    return (NULL);
  tmp = my_strdup("MemTotal: MemFree: Buffers: Cached: SwapTotal: SwapFree:");
  if (!(taupe->mem->pars = init_pars(my_str_to_wordtab(tmp, ' '))) ||
      !(taupe->task->menu = xmalloc(sizeof(t_menu))))
    return (NULL);
  init_task_pars_and_tri(taupe->task, taupe);
  new_list(&(taupe->proc));
  return (taupe);
}
