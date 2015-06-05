/*
** make_pars.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Sat Dec 13 17:48:32 2014 Martin Kinoo
** Last update Sat Dec 13 19:36:01 2014 Martin Kinoo
*/

#include	<stdlib.h>
#include	"taupe.h"

t_list		*init_pars(char **to_pars)
{
  t_list	*ret;
  t_pars	*elem;
  int		i;

  if (!to_pars || !(*to_pars))
    return (NULL);
  i = 0;
  new_list(&ret);
  while (to_pars[i])
    {
      if (!(elem = xmalloc(sizeof(t_pars))))
	return (NULL);
      elem->str = my_strdup(to_pars[i]);
      add_elem(&ret, elem);
      i++;
    }
  free_wordtab(to_pars);
  return (ret);
}
