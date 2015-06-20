/*
** taupe.h for taupe in /home/kinoo_m/rendu/taupe
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Mon Dec  8 16:45:41 2014 Martin Kinoo
** Last update Fri Jun 19 18:48:30 2015 Martin Kinoo
*/

#ifndef		_TAUPE_H_
# define	_TAUPE_H_

# define	BUFF_SIZE 4096

# include	<curses.h>

typedef struct	s_list
{
  void		*data;
  struct s_list	*prev;
  struct s_list	*next;
}		t_list;

typedef struct	t_menu
{
  t_list	*first;
  t_list	*select;
  int		len;
  int		dist;
}		t_menu;

typedef struct	s_sys
{
  int		hour;
  int		min;
  int		sec;
  int		up_day;
  int		up_hour;
  int		up_min;
  double	up_sec;
  int		user;
  char		*average[3];
}		t_sys;

typedef struct	s_task
{
  int		overall;
  int		run;
  int		sleep;
  int		stop;
  int		zombie;
  t_menu	*menu;
  t_list	*pars;
}		t_task;

typedef struct	s_cpu
{
  double	overall;
  double	delta;
  double	user;
  double	sys;
  double	nice;
  double	no_use;
  double	wa;
  double	hard_i;
  double	soft_i;
  double	thief;
}		t_cpu;

typedef struct	s_mem
{
  t_list	*pars;
  long		mem;
  long		mem_free;
  long		buffer;
  long		cached;
  long		swap;
  long		swap_free;
  long		mem_use;
  long		swap_use;
}		t_mem;

typedef struct	s_proc
{
  char		status;
  int		pid;
  char		*pr;
  long		nice;
  double	virt;
  double	res;
  double	shr;
  double	utime;
  double	stime;
  double	cpu;
  double	mem;
  int		hour;
  double	min;
  double	sec;
  char		*user;
  char		*command;
}		t_proc;

typedef struct	s_win
{
  int		width;
  int		height;
  WINDOW	*win;
}		t_win;

typedef struct	s_pars
{
  char		*str;
  char		**wordtab;
}		t_pars;

typedef struct	s_opt
{
  char		on;
  t_win		*win;
  t_win		*top;
  t_list	*list;
  t_menu	*menu;
  char		*str;
}		t_opt;

typedef struct	s_taupe
{
  t_sys		*sys;
  t_task	*task;
  t_cpu		*cpu;
  t_cpu		*old;
  t_mem		*mem;
  t_list	*proc;
  t_win		*top;
  t_win		*main;
  t_win		*main_top;
  t_win		*main_bottom;
  t_opt		*signal;
  t_opt		*sort;
  int		pid;
  t_menu	*menu;
  char		*sort_mess;
  char		*bottom_mess;
  int		(*f[12])(t_proc *, t_proc *);
  int		(*tri)(t_proc *, t_proc *);
}		t_taupe;

void		new_list(t_list **);
void		delete_list(t_list **);
void		delete_elem(t_list *);
void		add_elem(t_list **, void *);

int		my_strlen(char *);

int		my_error(char *);

int		my_strcmp(char *, char *);

char		*get_next_line(int);

char		*my_epur_str(char *);

int		my_wordlen(char **);
char		**my_str_to_wordtab(char *, char);
void		free_wordtab(char **);

char		*my_strncat(char *, char *, int);
char		*my_strcat(char *, char *);
char		*my_strdup(char *);
char		*my_strndup(char *, int);

int		my_file_fd(char *, int (*)(char *), int);

void		*xmalloc(int);

t_taupe		*init_my_taupe();

int		print_hub(t_taupe *);

void		print_opt(t_opt *, char *);
void		print_main(t_taupe *);
int		data_hub(t_taupe *);

char		**one_line_parsing(char *, char);
int		list_parsing(char *, char, t_list *);
void		delete_pars(t_list *);

t_list		*init_pars(char **);

void		data_mem(t_mem *);

t_list		*data_proc(t_list *, t_taupe *);

void		proc_parser(t_proc *, char *, t_task *, t_taupe *);

int		tri_master(t_list *, t_menu *, t_taupe *);

void		init_menu(t_menu *, t_list *);
void		del_menu(t_menu *);

void		keypad_manager(t_taupe *);

void		f_manager(t_taupe *, t_opt *, t_opt *);

void		main_win(int, int, t_taupe *);
void		top_win(t_win *);
void		signal_win(t_opt *, int);

void		sort_win(t_opt *, int);
void		send_signal(int, char *);

int		tri_pid(t_proc *, t_proc *);
int		tri_user(t_proc *, t_proc *);
int		tri_pri(t_proc *, t_proc *);
int		tri_nice(t_proc *, t_proc *);
int		tri_virt(t_proc *, t_proc *);
int		tri_res(t_proc *, t_proc *);
int		tri_shr(t_proc *, t_proc *);
int		tri_cpu(t_proc *, t_proc *);
int		tri_mem(t_proc *, t_proc *);
int		tri_time(t_proc *, t_proc *);
int		tri_state(t_proc *, t_proc *);
int		tri_command(t_proc *, t_proc *);

void		print_signal(t_opt *, int);

void		my_exit(t_taupe *);

#endif
