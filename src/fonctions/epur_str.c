/*
** epur_str.c for epur_str in /home/kinoo_m/rendu/fonctions/epur_str
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on Fri May  9 01:08:13 2014 Martin Kinoo
** Last update Tue Nov 18 06:03:09 2014 Martin Kinoo
*/

#include		<stdlib.h>

static int		nbr_cara(char *str)
{
  int			i;
  int			nbr;

  i = 0;
  nbr = 0;
  if (!str)
    return (0);
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] != '\0')
    {
      if ((str[i] != ' ' && str[i] != '\t') ||				\
	  ((str[i] == ' ' || str[i] == '\t') &&				\
	   (str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1] != '\0')))
	nbr++;
      i++;
    }
  return (nbr);
}

char			*my_epur_str(char *str)
{
  char			*ret;
  int			i;
  int			j;

  if (!str)
    return (NULL);
  if ((ret = malloc(sizeof(char) * (nbr_cara(str) + 1))) == NULL)
    return (NULL);
  i = -1;
  j = 0;
  while (str[++i] == ' ' || str[i] == '\t') ;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	ret[j++] = str[i];
      else if   ((str[i] == ' ' || str[i] == '\t') &&			\
		 str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1] != '\0')
	ret[j++] = ' ';
      i++;
    }
  ret[j] = '\0';
  return (ret);
}
