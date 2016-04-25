##
## Makefile for lemin in /home/brout_m/RENDU/CPE/CPE_2015_Lemin
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Sun Apr 24 17:02:29 2016 marc brout
## Last update Mon Apr 25 15:13:31 2016 benjamin duhieu
##

NAME		=	visu-hex

SRC		=	main.c \
			get_next_line.c	\
			text.c \
			refresh.c \
			ants.c \
			draw2.c	\
			draw.c \
			parser.c \
			thread.c \
			verif.c \
			aff.c \
			init.c \
			str.c \
			str2.c \
			str3.c \
			str4.c \
			str5.c \
			error.c	\
			tool.c \
			tool2.c \
			my_bzero.c \
			my_strcmp.c

OBJ			= $(addprefix src/, $(SRC:.c=.o))

IFLAG   		= `sdl-config --cflags --libs` -lSDL_gfx -lSDL_image -lSDLmain -lSDL_ttf  -Iinclude/

RM			= rm -f

CFLAGS			= -W -Wall -Wextra

CC			= gcc $(IFLAG) $(CFLAGS)

ECHO			= echo -e

GREEN			= \033[1;32m

WHITE			= \033[0m

.c.o:	
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

all:			$(NAME)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
