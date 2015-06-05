/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/kinoo_m/rendu/fonctions/my_str_to_wordtab
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on Thu May  8 22:53:35 2014 Martin Kinoo
** Last update Wed Dec 10 15:19:11 2014 Martin Kinoo
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"taupe.h"

static int		nbr_word(char *str, char c)
{
  int			nbr;
  int			i;

  if (str == NULL || *str == 0)
    return (0);
  nbr = 1;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
	nbr++;
      i++;
    }
  return (nbr);
}

static int		put_word(char **ret, char *str, int nbr, char c)
{
  char			*curs;
  int			i;

  if (nbr == 0)
    return (1);
  curs = str;
  i = 1;
  ret[0] = curs;
  while (*curs != '\0')
    {
      if (*curs == c)
	{
	  *curs = '\0';
	  ret[i++] = (curs + 1);
	}
      curs++;
    }
  ret[i] = NULL;
  return (0);
}

char			**my_str_to_wordtab(char *str, char c)
{
  int			nbr;
  char			*tmp;
  char			**ret;

  if ((tmp = my_epur_str(str)) == NULL)
    return (NULL);
  nbr = nbr_word(tmp, c);
  if ((ret = malloc(sizeof(char*) * (nbr + 1))) == NULL)
    {
      free(tmp);
      write(2, "erreur malloc.\n", 15);
      return (NULL);
    }
  if (put_word(ret, tmp, nbr, c))
    {
      free(ret);
      free(tmp);
      return (NULL);
    }
  return (ret);
}

void			free_wordtab(char **str)
{
  free(*str);
  free(str);
  str = NULL;
}

int			my_wordlen(char **str)
{
  int			i;

  if (!str || !(*str))
    return (0);
  i = 0;
  while (str[i])
    i++;
  return (i);
}
