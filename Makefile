CC		=	gcc

NAME	=	bswolf3d

SRC		=	main.c						\
			base/colorgen.c				\
			base/dotgen.c				\
			base/draw_vertex.c			\
			base/my_draw_line.c			\
			base/my_put_pixel.c			\
			base/vertex_gen.c			\
			map/drawmap.c				\
			map/draw_square.c			\
			map/setmap.c				\
			misc/dot_pr.c				\
			misc/getspecs.c				\
			misc/load_file_in_mem.c		\
			misc/malchartab.c			\
			misc/my_get_nbr.c			\
			misc/selectstr.c			\
			player/moveplayer.c			\
			player/ray_horiz.c			\
			player/ray_vert.c			\
			player/ray_main.c			\
			player/ray_simple.c			\
			player/strafeplayer.c		\
			window/buffer_reset.c		\
			window/init_gen.c			\
			window/keyloop.c			\
			window/draw_background.c

OBJ		=	$(SRC:.c=.o)

INCLUDE	= -lm -lc_graph_prog -I./include/

CFLAGS	+=	$(INCLUDE)

LDFLAGS	+=

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -W -Wall -Wextra -Werror -pedantic -ansi

all:	$(NAME)	

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all clean

opti:
	echo gcc -Ofast base/*.c main.c map/* misc/* player/* window/* -lc_graph_prog -lm -I./include -o cancerstein >> comp
	chmod 755 comp
	./comp
	rm -rf comp

.PHONY:	all clean fclean re run
