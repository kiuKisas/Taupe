/*
** error.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Wed Dec 10 13:45:52 2014 Martin Kinoo
** Last update Wed Dec 10 13:54:22 2014 Martin Kinoo
*/

#include	<stdlib.h>
#include	<unistd.h>
#include        <curses.h>
#include	"taupe.h"

int		my_error(char *str)
{
  endwin();
  write(2, str, my_strlen(str));
  write(2, "\n", 1);
  exit(1);
}
