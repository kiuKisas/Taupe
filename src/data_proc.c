/*
** data_proc.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Sat Dec 13 21:01:31 2014 Martin Kinoo
** Last update Fri Dec 19 00:38:38 2014 Martin Kinoo
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<dirent.h>
#include	<stdlib.h>
#include	"taupe.h"

static int	str_is_nbr(char *str)
{
  if (!str)
    return (0);
  while (*str)
    {
      if (*str < '0' || *str > '9')
	return (0);
      str++;
    }
  return (1);
}

static void	delink_save(t_list *save)
{
  save->prev->next = save->next;
  save->next->prev = save->prev;
}

static void	my_add_pid(char *str_pid, t_list **new_proc,
			   t_list *proc, t_taupe *taupe)
{
  t_proc	*elem;
  int		pid;
  t_list	*save;

  elem = NULL;
  pid = atoi(str_pid);
  while (proc && !elem && proc->data)
    {
      elem = proc->data;
      if (elem->pid != pid)
	elem = NULL;
      save = proc;
      proc = proc->next;
    }
  if (elem)
    delink_save(save);
  else if (!(elem = xmalloc(sizeof(t_proc))))
    my_error("failed to malloc t_proc");
  elem->pid = pid;
  add_elem(new_proc, elem);
  if (save == taupe->task->menu->select)
    taupe->task->menu->select = (*new_proc)->prev;
  proc_parser(elem, my_strcat("/proc/", str_pid), taupe->task, taupe);
}

static void	delete_proc_list(t_list *proc, t_menu *menu, t_list *new_proc)
{
  t_proc	*tmp;
  t_list	*it;

  if (!proc)
    return ;
  while (proc->data)
    {
      it = proc;
      tmp = it->data;
      if (proc == menu->select)
	{
	  menu->select = new_proc->next;
	  menu->dist = 0;
	}
      proc = proc->next;
      free(tmp->user);
      free(tmp->command);
      free(it);
    }
  free(proc);
}

t_list		*data_proc(t_list *proc, t_taupe *taupe)
{
  DIR		*rep;
  struct dirent	*file;
  struct stat	s_stat;
  char		*tmp;
  t_list	*new_proc;

  new_proc = NULL;
  taupe->task->overall = 0;
  taupe->task->run = 0;
  taupe->task->sleep = 0;
  taupe->task->stop = 0;
  taupe->task->zombie = 0;
  if (!(rep = opendir("/proc/")))
    my_error("failed to load /proc fold");
  while ((file = readdir(rep)))
    {
      stat((tmp = my_strcat("/proc/", file->d_name)), &s_stat);
      if (S_ISDIR(s_stat.st_mode) && str_is_nbr(file->d_name))
	my_add_pid(file->d_name, &new_proc, proc->next, taupe);
      free(tmp);
    }
  closedir(rep);
  delete_proc_list(proc->next, taupe->task->menu, new_proc);
  return (new_proc);
}
