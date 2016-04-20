##
## Makefile for Makefile in /home/duhieu_b/CPE/CPE_2015_Lemin
## 
## Made by benjamin duhieu
## Login   <duhieu_b@epitech.net>
## 
## Started on  Fri Apr  8 15:45:04 2016 benjamin duhieu
## Last update Wed Apr 20 22:41:41 2016 marc brout
##

# USEFUL VARIABLES

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e

# COREWAR VARIABLES

PARSING		=	parsing/

ALGO		=	algo/

SRC		=	$(PARSING)parsing.c \
			$(PARSING)errors.c \
			$(PARSING)my_bzero.c \
			$(PARSING)misc.c \
			$(PARSING)solve_one_path.c \
			$(PARSING)my_getnbr.c \
			$(PARSING)checks.c \
			$(PARSING)graph.c \
			$(PARSING)free.c \
			$(PARSING)get_graph.c \
			$(ALGO)tri.c \
			$(ALGO)clean.c \
			$(ALGO)algo.c \
			$(ALGO)all_path.c \
			$(ALGO)ant.c \
			$(ALGO)larg_path.c \
			$(ALGO)add_pile.c \
			$(ALGO)aff_ant.c \
			$(ALGO)free_pil.c \
			$(ALGO)get_short_path.c \

OBJS    	=	$(SRC:.c=.o)


# LIBRARY VARIABLES

LIBPATH =       lib/

LIB	=	lib/libmy.a

SRCLIB	=	$(LIBPATH)my/get_next_line.c \
		$(LIBPATH)my/my_getnbr.c \
		$(LIBPATH)my/my_power_rec.c \
		$(LIBPATH)my/my_printf.c \
		$(LIBPATH)my/my_printfcsspb.c \
		$(LIBPATH)my/my_printfdiouxx.c \
		$(LIBPATH)my/my_printfmetc.c \
		$(LIBPATH)my/my_putchar.c \
		$(LIBPATH)my/my_put_nbr.c \
		$(LIBPATH)my/my_putstr.c \
		$(LIBPATH)my/my_revstr.c \
		$(LIBPATH)my/my_strcmp.c \
		$(LIBPATH)my/my_strdup.c \
		$(LIBPATH)my/my_strlen.c \
		$(LIBPATH)my/my_strncmp.c \

LDFLAGS =       -lmy -L$(LIBPATH)

OBJSLIB	=	$(SRCLIB:.c=.o)


# PROJECT VARIABLES

NAME	=	lem_in

IFLAG	=	-Iinclude/

CFLAGS  =	-W -Wall -Wextra

CC      =	gcc -g $(CFLAGS) $(IFLAG)


# PROJECT RULES

$(NAME)		: 	$(LIB) $(OBJS)
			@$(ECHO) "$(GREEN)\n>>>>>>>>>>>>>>>>\n\n> Linking \"$(NAME)\"\n\twith \
\"$(CC)\"\n\n>>>>>>>>>>>>>>>\t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(LIB)		:	$(OBJSLIB)
			@ar rc $(LIB) $(OBJSLIB)
			@ranlib $(LIB)
			@cp $(LIBPATH)/my/my.h include/
			@cp $(LIBPATH)/my/get_next_line.h include/
			@$(ECHO) "$(GREEN)\n> Compiling Library\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"


all		:	$(NAME)

clean		:
			@$(RM) $(OBJS)
			@$(RM) $(OBJSLIB)
			@$(ECHO) "$(GREEN)\n> Cleaning repository\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

fclean		: 	clean
			@$(RM) $(NAME)
			@$(RM) $(LIBPATH)/libmy.a
			@$(ECHO) "$(GREEN)\n> Cleaning exec\t\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

re		:	fclean all

.c.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"
