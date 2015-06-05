/*
** data.c for taupe in /home/kinoo_m/rendu/taupe
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Tue Dec  9 19:01:23 2014 Martin Kinoo
** Last update Fri Dec 19 01:39:05 2014 Martin Kinoo
*/

#include		<string.h>
#include		<curses.h>
#include		<utmp.h>
#include		<sys/sysinfo.h>
#include		<time.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		"taupe.h"

static void		data_user(t_sys *sys)
{
  struct utmp		*info;

  sys->user = 0;
  while ((info = getutent()))
    {
      if ((info->ut_type == USER_PROCESS))
	(sys->user)++;
    }
  endutent();
}

static int		data_sysinfo(t_sys *sys)
{
  struct sysinfo	info;

  if (sysinfo(&info))
    return (1);
  sys->up_sec = info.uptime;
  sys->up_min = (int)sys->up_sec / 60;
  sys->up_sec -= (double)sys->up_min;
  sys->up_hour = sys->up_min / 60;
  sys->up_min %= 60;
  sys->up_day = sys->up_hour / 24;
  sys->up_hour %= 24;
  return (0);
}

static void		data_average(t_sys *sys)
{
  char			**average;

  average = one_line_parsing("/proc/loadavg", ' ');
  if (my_wordlen(average) < 3)
    my_error("invalid /proc/loadavg");
  sys->average[0] = my_strdup(average[0]);
  sys->average[1] = my_strdup(average[1]);
  sys->average[2] = my_strdup(average[2]);
  free_wordtab(average);
}

static void		data_cpu(t_cpu *cpu, t_cpu *old)
{
  t_cpu			tmp;
  char			**data;

  if ((data = one_line_parsing("/proc/stat", ' ')) && my_wordlen(data) < 9)
    my_error("invalid /proc/stat");
  tmp.overall = (tmp.user = (double)atol(data[1]));
  tmp.overall += (tmp.nice = (double)atol(data[2]));
  tmp.overall += (tmp.sys = (double)atol(data[3]));
  tmp.overall += (tmp.no_use = (double)atol(data[4]));
  tmp.overall += (tmp.wa = (double)atol(data[5]));
  tmp.overall += (tmp.hard_i = (double)atol(data[6]));
  tmp.overall += (tmp.soft_i = (double)atol(data[7]));
  tmp.overall += (tmp.thief = (double)atol(data[8]));
  tmp.delta = (tmp.overall - cpu->overall);
  cpu->user = ((tmp.user - old->user) / tmp.delta) * 100;
  cpu->sys = ((tmp.sys - old->sys) / tmp.delta) * 100;
  cpu->nice = ((tmp.nice - old->nice) / tmp.delta) * 100;
  cpu->no_use = ((tmp.no_use - old->no_use) / tmp.delta) * 100;
  cpu->wa = ((tmp.wa - old->wa) / tmp.delta) * 100;
  cpu->hard_i = ((tmp.hard_i - old->hard_i) / tmp.delta) * 100;
  cpu->soft_i = ((tmp.soft_i - old->soft_i) / tmp.delta) * 100;
  cpu->thief = ((tmp.thief - old->thief) / tmp.delta) * 100;
  cpu->overall = tmp.overall;
  memcpy(old, &tmp, sizeof(t_cpu));
  free_wordtab(data);
}

int			data_hub(t_taupe *taupe)
{
  struct tm		*tm;
  time_t		ti;

  if (!(ti = time(NULL)))
    return (1);
  tm = localtime(&ti);
  taupe->sys->hour = tm->tm_hour;
  taupe->sys->min = tm->tm_min;
  taupe->sys->sec = tm->tm_sec;
  data_user(taupe->sys);
  data_average(taupe->sys);
  data_mem(taupe->mem);
  if (data_sysinfo(taupe->sys))
    return (1);
  data_cpu(taupe->cpu, taupe->old);
  taupe->proc = data_proc(taupe->proc, taupe);
  return (0);
}
