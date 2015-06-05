/*
** proc_parser.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Sun Dec 14 00:26:18 2014 Martin Kinoo
** Last update Fri Dec 19 11:56:30 2014 Martin Kinoo
*/

#include	<sys/types.h>
#include	<pwd.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"taupe.h"

static void	proc_status(t_proc *proc, char *path, t_task *task)
{
  t_pars	*cast;
  int		fd;
  struct passwd	*pss_wd;

  if ((fd = open(path, O_RDONLY)) == -1)
    return ;
  close(fd);
  path = my_strcat(path, "/status");
  if (list_parsing(path, ' ', task->pars->next))
    return ;
  cast = task->pars->next->data;
  proc->command = my_strdup(cast->wordtab[1]);
  cast = task->pars->next->next->data;
  proc->status = cast->wordtab[1][0];
  cast = task->pars->next->next->next->data;
  if (cast && (pss_wd = getpwuid(atoi(cast->wordtab[1]))))
    {
      free(proc->user);
      proc->user = NULL;
      proc->user = my_strdup(pss_wd->pw_name);
    }
  free(path);
  delete_pars(task->pars);
}

static void	proc_time(t_proc *proc, char **wordtab)
{
  proc->sec = (double)atol(wordtab[13]);
  proc->sec += (double)atol(wordtab[14]);
  proc->min = proc->sec / 100;
  proc->hour = (int)proc->min / 60;
  proc->min -= (proc->hour * 60);
}

static void	proc_stat(t_proc *proc, char *path, t_cpu *cpu)
{
  char		**wordtab;
  int		fd;

  if ((fd = open(path, O_RDONLY)) == -1)
    return ;
  close(fd);
  path = my_strcat(path, "/stat");
  if (!(wordtab = one_line_parsing(path, ' ')))
    return ;
  free(proc->pr);
  proc->cpu = (((double)atol(wordtab[13]) - proc->utime) / cpu->delta);
  proc->cpu += ((((double)atol(wordtab[14]) / sysconf(_SC_CLK_TCK)) -
		 proc->stime) / cpu->delta);
  proc->cpu *= 1000;
  proc->utime = (double)atol(wordtab[13]);
  proc->stime = (double)atol(wordtab[14]) / sysconf(_SC_CLK_TCK);
  proc->pr = my_strdup(wordtab[17]);
  proc->nice = atol(wordtab[18]);
  proc_time(proc, wordtab);
  free_wordtab(wordtab);
  free(path);
}

static void	proc_statm(t_proc *proc, char *path, t_mem *mem)
{
  char		**wordtab;
  int		fd;

  if ((fd = open(path, O_RDONLY)) == -1)
    return ;
  close(fd);
  path = my_strcat(path, "/statm");
  if (!(wordtab = one_line_parsing(path, ' ')))
    my_error("invalid /proc/[pid]/statm");
  proc->virt = (double)atol(wordtab[0]) * getpagesize() / 1024;
  proc->res = (double)atol(wordtab[1]) * getpagesize() / 1024;
  proc->shr = (double)atol(wordtab[2]) * getpagesize() / 1024;
  proc->mem = proc->res / mem->mem * 100;
  free_wordtab(wordtab);
  free(path);
}

void		proc_parser(t_proc *proc, char *path, t_task *task, t_taupe *t)
{
  (task->overall)++;
  proc_status(proc, path, task);
  proc_stat(proc, path, t->old);
  proc_statm(proc, path, t->mem);
  if (proc->status == 'S')
    (task->sleep)++;
  else if (proc->status == 'R')
    (task->run)++;
  else if (proc->status == 'Z')
    (task->zombie)++;
  else if (proc->status == 'T')
    (task->stop)++;
}
