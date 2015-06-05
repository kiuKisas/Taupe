/*
** print_main.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Thu Dec 11 18:03:47 2014 Martin Kinoo
** Last update Fri Dec 19 06:31:59 2014 Martin Kinoo
*/

#include	<curses.h>
#include	"taupe.h"

static void	print_proc(t_proc *proc, t_win *win, int color)
{
  if (!proc || !(proc->user))
    return ;
  wattron(win->win, COLOR_PAIR(color));
  wprintw(win->win, "%5d %-8s", proc->pid, proc->user);
  if (!my_strcmp(proc->pr, "-100"))
    wprintw(win->win, "  rt");
  else
    wprintw(win->win, "%4s", proc->pr);
  wprintw(win->win, " %3ld %6.1fm", proc->nice, (proc->virt / 1024));
  wprintw(win->win, " %5.1fm %5.1fm %5.1f", (proc->res / 1024),
	  (proc->shr / 1024), proc->cpu);
  wprintw(win->win, " %4.1f%4d:", proc->mem, proc->hour);
  if (proc->min < 10)
    wprintw(win->win, "0");
  wprintw(win->win, "%.2f", proc->min);
  wprintw(win->win, " %c", proc->status);
  wprintw(win->win, " %s\n", proc->command);
}

void		print_main(t_taupe *taupe)
{
  t_list	*nav;
  int		tmp;

  wclear(taupe->main->win);
  wclear(taupe->main_top->win);
  wclear(taupe->main_bottom->win);
  tri_master(taupe->proc, taupe->task->menu, taupe);
  nav = taupe->task->menu->first;
  tmp = taupe->task->menu->len;
  while (tmp)
    {
      if (!(nav->data))
	tmp = 1;
      else if (nav == taupe->task->menu->select)
	print_proc(nav->data, taupe->main, 1);
      else
	print_proc(nav->data, taupe->main, 9);
      nav = nav->next;
      tmp--;
    }
  wprintw(taupe->main_top->win, "  PID USER      PR  NI    VIRT    RES");
  wprintw(taupe->main_top->win, "    SHR  %%CPU %%MEM     TIME+ S COM.");
  wprintw(taupe->main_bottom->win, taupe->bottom_mess);
}
