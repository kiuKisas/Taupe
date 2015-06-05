/*
** parser.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Wed Dec 10 13:24:38 2014 Martin Kinoo
** Last update Sat Dec 13 19:53:39 2014 Martin Kinoo
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"taupe.h"

char		**one_line_parsing(char *path, char sep)
{
  int		fd;
  char		*str;
  char		**wordtab;

  wordtab = NULL;
  fd = my_file_fd(path, &my_error, O_RDONLY);
  if ((str = get_next_line(fd)))
    {
      wordtab = my_str_to_wordtab(str, sep);
      free(str);
    }
  while ((str = get_next_line(fd)))
    free(str);
  close(fd);
  return (wordtab);
}

static int	find_my_start(char *str, char *from)
{
  int		i;

  if (!str || !from)
    return (0);
  i = 0;
  while (str[i])
    {
      if (from[i] != str[i])
	return (0);
      i++;
    }
  return (1);
}

void		delete_pars(t_list *list)
{
  t_pars	*cast;

  if (!list)
    return ;
  while (list->data)
    {
      cast = list->data;
      free(cast->wordtab);
      cast->wordtab = NULL;
      list = list->next;
    }
}

int		list_parsing(char *path, char sep, t_list *content)
{
  int		fd;
  char		*str;
  t_pars	*cast;

  if (!(content->data))
    return (0);
  delete_pars(content);
  cast = content->data;
  fd = my_file_fd(path, &my_error, O_RDONLY);
  while ((str = get_next_line(fd)))
    {
      if (cast && find_my_start(cast->str, str))
	{
	  free(cast->wordtab);
	  cast->wordtab = my_str_to_wordtab(str, sep);
	  content = content->next;
	  cast = content->data;
	}
      free(str);
    }
  close(fd);
  if (content->data)
    return (1);
  return (0);
}
