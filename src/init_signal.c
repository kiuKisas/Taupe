/*
** init_opt.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Tue Dec 16 18:20:51 2014 Martin Kinoo
** Last update Fri Dec 19 06:20:07 2014 Martin Kinoo
*/

#include	"taupe.h"

static void	opt_win(t_opt *signal, int top)
{
  int		starty;

  signal->win->width = 14;
  signal->top->width = 14;
  signal->win->height = LINES - top - 2;
  starty = ((LINES - signal->win->height) / 2) + 4;
  signal->win->win = newwin(signal->win->height - 2,
			    signal->win->width, starty + 1, 0);
  signal->top->win = newwin(2, signal->win->width, starty - 1, 0);
}

static void	signal_win_extra(t_opt *signal)
{
  signal->menu->len = LINES - 9;
  add_elem(&(signal->list), my_strdup("19 SIGSTOP"));
  add_elem(&(signal->list), my_strdup("20 SIGTSTP"));
  add_elem(&(signal->list), my_strdup("21 SIGTTIN"));
  add_elem(&(signal->list), my_strdup("22 SIGTTOU"));
  add_elem(&(signal->list), my_strdup("23 SIGURG"));
  add_elem(&(signal->list), my_strdup("24 SIGXCPU"));
  add_elem(&(signal->list), my_strdup("25 SIGXFSZ"));
  add_elem(&(signal->list), my_strdup("26 SIGVTALRM"));
  add_elem(&(signal->list), my_strdup("27 SIGPROF"));
  add_elem(&(signal->list), my_strdup("28 SIGWINCH"));
  add_elem(&(signal->list), my_strdup("29 SIGIO"));
  add_elem(&(signal->list), my_strdup("29 SIGPOLL"));
  add_elem(&(signal->list), my_strdup("30 SIGPWR"));
  add_elem(&(signal->list), my_strdup("31 SIGSYS"));
}

void		signal_win(t_opt *signal, int top)
{
  opt_win(signal, top);
  signal->str = my_strdup("Enter Send   F2 Cancel");
  new_list(&(signal->list));
  add_elem(&(signal->list), my_strdup("1 SIGHUP"));
  add_elem(&(signal->list), my_strdup("2 SIGINT"));
  add_elem(&(signal->list), my_strdup("3 SIQUIT"));
  add_elem(&(signal->list), my_strdup("4 SIGILL"));
  add_elem(&(signal->list), my_strdup("5 SIGTRAP"));
  add_elem(&(signal->list), my_strdup("6 SIABRT"));
  add_elem(&(signal->list), my_strdup("6 SIGIOT"));
  add_elem(&(signal->list), my_strdup("7 SIGBUS"));
  add_elem(&(signal->list), my_strdup("8 SIGFPE"));
  add_elem(&(signal->list), my_strdup("9 SIGKILL"));
  add_elem(&(signal->list), my_strdup("10 SIGUSR1"));
  add_elem(&(signal->list), my_strdup("11 SIGSEGV"));
  add_elem(&(signal->list), my_strdup("12 SIGUSR2"));
  add_elem(&(signal->list), my_strdup("13 SIGPIPE"));
  add_elem(&(signal->list), my_strdup("14 SIGALRM"));
  add_elem(&(signal->list), my_strdup("15 SIGTERM"));
  add_elem(&(signal->list), my_strdup("16 SIGSTKLT"));
  add_elem(&(signal->list), my_strdup("17 SIGCHLD"));
  add_elem(&(signal->list), my_strdup("18 SIGCON"));
  signal_win_extra(signal);
}

void		sort_win(t_opt *sort, int top)
{
  opt_win(sort, top);
  sort->menu->len = LINES - 9;
  sort->str = my_strdup("Enter Sort   F1 Cancel");
  new_list(&(sort->list));
  add_elem(&(sort->list), my_strdup("PID"));
  add_elem(&(sort->list), my_strdup("USER"));
  add_elem(&(sort->list), my_strdup("PRIORITY"));
  add_elem(&(sort->list), my_strdup("NICE"));
  add_elem(&(sort->list), my_strdup("M_SIZE"));
  add_elem(&(sort->list), my_strdup("M_RESIDENT"));
  add_elem(&(sort->list), my_strdup("M_SHARE"));
  add_elem(&(sort->list), my_strdup("STATE"));
  add_elem(&(sort->list), my_strdup("PERCENT_CPU"));
  add_elem(&(sort->list), my_strdup("PERCENT_MEM"));
  add_elem(&(sort->list), my_strdup("TIME"));
  add_elem(&(sort->list), my_strdup("Command"));
}
