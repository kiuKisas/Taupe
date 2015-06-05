/*
** mem_and_swap.c for taupe in /home/kinoo_m/rendu/taupe/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Wed Dec 10 21:31:52 2014 Martin Kinoo
** Last update Sat Dec 13 19:43:31 2014 Martin Kinoo
*/

#include	<stdlib.h>
#include	"taupe.h"

void		data_mem(t_mem *mem)
{
  t_list	*nav;
  t_pars	*cast;
  long		*ptr;

  if (list_parsing("/proc/meminfo", ' ', mem->pars->next))
    my_error("missing meminfo data");
  ptr = &(mem->mem);
  nav = mem->pars->next;
  while (nav->data)
    {
      cast = nav->data;
      *ptr = atol(cast->wordtab[1]);
      nav = nav->next;
      ptr++;
    }
  mem->mem_use = mem->mem - (mem->mem_free + mem->buffer);
  mem->swap_use = mem->swap - mem->swap_free;
}
