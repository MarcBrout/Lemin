id		=				test

SRC		=	main.c							\
			get_next_line.c				\
			refresh.c							\
			ants.c								\
			draw2.c								\
			draw.c								\
			parser.c							\
			thread.c							\
			sort.c								\
			aff.c									\
			init.c 								\
			str.c 								\
			str2.c 								\
			str3.c 								\
			str4.c 								\
			str5.c 								\
			error.c 							\
			tool.c

OBJ			=				$(addprefix src/, $(SRC:.c=.o))

IFLAG   =       `sdl-config --cflags --libs` -lSDL_gfx -lSDL_image -lSDLmain -lSDL_ttf  -Iinclude/

RM			=				rm -f

CC			=				gcc -O1 $(IFLAG)

ECHO		=				echo -e

GREEN	=	\033[1;32m

WHITE	=	\033[0m

all:						$(OBJ)
								$(CC) -o $(id) $(OBJ)

clean:
								$(RM) $(OBJ)

fclean:					clean
								$(RM) $(id)

re:							fclean all

.c.o:
								@$(CC) -c $< -o $@
								@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"
