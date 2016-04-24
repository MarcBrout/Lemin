##
## Makefile for Makefile in /home/duhieu_b/CPE/CPE_2015_Lemin/Bonus
## 
## Made by benjamin duhieu
## Login   <duhieu_b@epitech.net>
## 
## Started on  Sun Apr 24 17:02:46 2016 benjamin duhieu
## Last update Sun Apr 24 17:09:37 2016 benjamin duhieu
##

NAME		=	visu-hex

SRC		=	main.c \
			get_next_line.c	\
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

OBJ			= $(addprefix src/, $(SRC:.c=.o))

IFLAG   		=       `sdl-config --cflags --libs` -lSDL_gfx -lSDL_image -lSDLmain -lSDL_ttf  -Iinclude/

RM			= rm -f

CC			= gcc $(IFLAG) -g

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
