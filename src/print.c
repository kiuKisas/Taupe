/*
** print.c for taupe in /home/kinoo_m/rendu/taupe
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Tue Dec  9 17:23:29 2014 Martin Kinoo
** Last update Fri Dec 19 06:40:02 2014 Martin Kinoo
*/

#include	<curses.h>
#include	"taupe.h"

static void	print_sys(t_sys *sys, t_win *top)
{
  wprintw(top->win, "taupe - %.2d:%.2d:%.2d up", sys->hour, sys->min, sys->sec);
  if (sys->up_day)
    wprintw(top->win, " %d days,", sys->up_day);
  if (sys->up_day || sys->up_hour)
   wprintw(top->win, "  %d:%.2d,", sys->up_hour, sys->up_min);
  else
    wprintw(top->win, "  %d min,", sys->up_min);
  wprintw(top->win, "  %d users,", sys->user);
  wprintw(top->win, "  load average: %s, %s, %s\n", sys->average[0],
	 sys->average[1], sys->average[2]);
}

static void	print_task(t_task *task, t_win *top)
{
  wprintw(top->win, "Tasks:  %d total,", task->overall);
  wprintw(top->win, "   %d running,  %d sleeping,", task->run, task->sleep);
  wprintw(top->win, "   %d stopped,   %d zombie\n", task->stop, task->zombie);
}

static void	print_cpu(t_cpu *cpu, t_win *top)
{
  wprintw(top->win, "%%Cpu(s):  %.1lf us,", cpu->user);
  wprintw(top->win, " %.1lf sy,  %.1lf ni,", cpu->sys, cpu->nice);
  wprintw(top->win, " %.1lf id,  %.1lf wa,", cpu->no_use, cpu->wa);
  wprintw(top->win, " %.1lf hi,  %.1lf si,", cpu->hard_i, cpu->soft_i);
  wprintw(top->win, " %.1lf st\n", cpu->thief);
}

static void	print_mem(t_mem *mem, t_win *top)
{
  wprintw(top->win, "Kib Mem:  %d total,  %d used,", mem->mem, mem->mem_use);
  wprintw(top->win, "  %d free,  %d buffers\n", mem->mem_free, mem->buffer);
  wprintw(top->win, "Kib Swap:  %d total,  %d used,", mem->swap, mem->swap_use);
  wprintw(top->win, "  %d free.  %d cached Mem\n", mem->swap_free, mem->cached);
}

int		print_hub(t_taupe *taupe)
{
  wclear(taupe->top->win);
  print_sys(taupe->sys, taupe->top);
  print_task(taupe->task, taupe->top);
  print_cpu(taupe->cpu, taupe->top);
  print_mem(taupe->mem, taupe->top);
  if (taupe->signal->on)
    {
      print_opt(taupe->signal, "Send Signal");
      print_signal(taupe->signal, taupe->pid);
    }
  else if (taupe->sort->on)
    print_opt(taupe->sort, "Sort By");
  print_main(taupe);
  return (0);
}
