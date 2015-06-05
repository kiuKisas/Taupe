/*
** kill.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Fri Dec 19 04:56:06 2014 Martin Kinoo
** Last update Fri Dec 19 05:12:33 2014 Martin Kinoo
*/

#include	<sys/types.h>
#include	<signal.h>
#include	"taupe.h"

void		send_signal(int pid, char *signal)
{
  int		sig;

  if (!signal)
    return ;
  sig = (*signal) - 48;
  signal++;
  if (*signal != ' ')
    {
      sig *= 10;
      sig += (*signal) - 48;
    }
  if (kill(pid, sig))
    my_error("kill failed");
}
