/*
** my_strndup.c for my_strndup in /home/kinoo_m/rendu/fonctions
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on Sat May 10 02:35:06 2014 Martin Kinoo
** Last update Wed Dec 10 13:50:56 2014 Martin Kinoo
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"taupe.h"

char			*my_strndup(char *str, int n)
{
  char			*ret;
  int			i;

  if (str == NULL || n < 0)
    return (NULL);
  if ((ret = xmalloc(sizeof(char) * (n + 1))) == NULL)
    {
      write(2, "erreur malloc.\n", 15);
      return (NULL);
    }
  i = 0;
  while (i++ < n && str[i - 1])
    ret[i - 1] = str[i - 1];
  ret[i - 1] = '\0';
  return (ret);
}
