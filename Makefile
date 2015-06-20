##
## Makefile for taupe in /home/kinoo_m/rendu/taupe
##
## Made by Martin Kinoo
## Login   <kinoo_m@epitech.net>
##
## Started on  Mon Dec  8 16:38:56 2014 Martin Kinoo
## Last update Sat Jun 20 15:57:32 2015 Martin Kinoo
##

NAME=		taupe

CC=		cc

ifeq ($(DEBUG), yes)
CFLAGS +=	-g
endif

RM=		rm -f

CFLAGS +=	-Wall -Wextra
CFLAGS +=	-I./inc/

LDFLAGS +=	-lcurses

SRC=		src/print.c	\
		src/tri_other.c	\
		src/error.c	\
		src/init.c	\
		src/menu_and_key.c	\
		src/parser.c	\
		src/print_opt.c	\
		src/print_main.c	\
		src/list.c	\
		src/tri_extra.c	\
		src/mem_and_swap.c	\
		src/make_pars.c	\
		src/tri.c	\
		src/kill.c	\
		src/init_signal.c	\
		src/main.c	\
		src/menu.c	\
		src/proc_parser.c	\
		src/f_menu.c	\
		src/data.c	\
		src/data_proc.c	\
		src/init_win.c	\
		src/fonctions/get_next_line.c	\
		src/fonctions/my_strdup.c	\
		src/fonctions/my_str_to_wordtab.c	\
		src/fonctions/my_strncat.c	\
		src/fonctions/give_me_fd.c	\
		src/fonctions/epur_str.c	\
		src/fonctions/my_strcmp.c	\
		src/fonctions/my_strcat.c	\
		src/fonctions/my_strndup.c	\
		src/my_exit.c 

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
