#include	<stdlib.h>
#include	"taupe.h"

void		my_exit(t_taupe *taupe)
{
  endwin();
  if (taupe)
    {
      free(taupe->sys);
      free(taupe->task);
      free(taupe->cpu);
      free(taupe->old);
      free(taupe->mem);
      free(taupe->proc);
      free(taupe->top);
      free(taupe->main);
      free(taupe->main_top);
      free(taupe->main_bottom);
      free(taupe->menu);
      free(taupe->sort_mess);
      free(taupe->bottom_mess);
      free(taupe->signal);
      free(taupe->sort);
    }
  exit(0);
}
