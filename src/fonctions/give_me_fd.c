/*
** give_me_fd.c for projstarter in /home/kinoo_m/rendu/projstarter/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Thu Nov 13 21:46:56 2014 Martin Kinoo
** Last update Wed Dec 10 13:45:26 2014 Martin Kinoo
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<errno.h>
#include	"taupe.h"

static int	error_file(int fd, char *path, int (*f)(char *))
{
  (*f)(path);
  free(path);
  close(fd);
  return (-1);
}

int		my_file_fd(char *path, int (*f)(char *), int flag)
{
  int		fd;
  char		*print;
  char		*tmp;

  if ((fd = open(path, O_DIRECTORY, S_IRUSR)) > 0)
    return (error_file(fd, my_strcat(path, " is a folder"), f));
  if ((fd = open(path, flag, S_IWUSR)) > 0)
    return (fd);
  tmp = my_strcat("can't access to ", path);
  if (errno == EACCES)
    print = my_strcat(tmp, " permission denied");
  else if  (errno == ENOENT)
    print = my_strcat(tmp, " file not found");
  else if  (errno == ENAMETOOLONG)
    print = my_strcat(tmp, " too long pathname");
  else
    print = tmp;
  if (print != tmp)
    free(tmp);
  (*f)(print);
  free(print);
  return (-1);
}
