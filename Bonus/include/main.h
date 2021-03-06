
/*
** main.h for bonus in ~/git/CPE/CPE_2015_Lemin/Bonus/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:30:56 2016 THEIS Paul
** Last update Mon Apr 25 20:36:28 2016 marc brout
*/

#ifndef MAIN_H
# define MAIN_H

# define	W_W		(1280)
# define	STATBAR_H	(50)
# define	TOOLBAR_H	(120)
# define	SPACE_H		(600)
# define	SPACE_1		(5)
# define	W_H		(TOOLBAR_H + SPACE_H)
# define	FALSE		0
# define	TRUE		!FALSE
# define	BUFF_SIZE	4096
# define	C_FLAG		'P'
# define	C_MIN		'-'
# define	C_SPACE		' '
# define	JOIN		my_strjoin
# define	NB_CH		my_putnbr_char

# include 	<stdio.h>
# include 	<unistd.h>
# include 	<stdlib.h>
# include 	<string.h>
# include 	<sys/types.h>
# include 	<sys/stat.h>
# include 	<fcntl.h>
# include 	<stdlib.h>

# include 	<SDL/SDL.h>
# include 	<SDL2/SDL.h>
# include 	<SDL/SDL_ttf.h>
# include 	<SDL/SDL_image.h>
# include 	<SDL/SDL_rotozoom.h>

typedef unsigned char		bool;

# include "str.h"
# include "get_next_line.h"
# include "display.h"

typedef struct 	s_elem
{
  SDL_Rect	pos;
  char		*id;
  int		opt;
  int		nbr_ants;
}		t_elem;

typedef struct	s_ants
{
  char		*id;
  char		*room;
}		t_ants;

typedef struct	s_info
{
  SDL_Surface	*screen;
  SDL_Surface	*space;
  SDL_Surface	*statbar;
  SDL_Surface	*toolbar;
  TTF_Font	*font;
  SDL_Rect	pos;
  SDL_Rect	spacer;
  SDL_Color	black;
  t_elem	elem[BUFF_SIZE];
  t_ants	ants[BUFF_SIZE / 4];
  int		current;
  int		nbr;
  int		nbr_room;
  int		nbr_ants;
  int		round;
  int		opt;
  int		speed;
}		t_info;

/*
**TOOL
*/
SDL_Rect	set_pos(int x, int y);
bool		is_num(char c);
bool		is_alpha(char c);
void		get_coor(int i, SDL_Rect *pos, t_info *info);
void		set_color(SDL_Color *color, int r, int g, int b);
void		swap_int(Sint16 *x, Sint16 *y);
unsigned long	setter_color(int R, int G, int B);
/*
**INIT
*/
int		init_struct(t_info *info);
int		init_toolbar(t_info *info);
int		init_space(t_info *info);
void		init_SDL_Rect(SDL_Rect *pos);

/*
**AFF
*/
int		aff_round(t_info *info);
int		aff_info(char *id_room, int x, int y, t_info *info);
int		aff_room(int x, int y, t_info *info);
char		*text_round(t_info *info);
char		*concat_str_int(char *tmp, char *tmp2,
				char *str, int nb);
char		*concat_str(char *tmp, char *tmp2);
char		*my_putnbr_char(int nb);
int		get_room(t_info *info, bool a);

/*
**VERIF
*/
int		verif_id(t_info *info, char *id);
int		verif_id_ant(t_info *info, char *id);
int		save_room(char *id, SDL_Rect *pos, t_info *info,
			  int opt);
/*
**PARSER
*/
int		parse_path(char *str, t_info *info);
int		parse(t_info *info);
int		parse_decl(char *str, t_info *info, int opt, int cmptr);
int		parse_thread(char *str, t_info *info);
int		parse_it(SDL_Rect flag, SDL_Rect pos, char *str,
			 t_info *info);
/*
**ANTS
*/
int		set_ants(int total, t_info *info, char *id);
int		put_ant_screen(int x, int y, t_info *info);
int		update_screen(t_info *info);
int		ants_path(char *str, t_info *info);
int		put_ants_room(t_info *info, int nbr);

/*
**DRAW
*/
void		draw_line(SDL_Rect *pos1, SDL_Rect *pos2, t_info *info);
int		draw_tunel(char *id1, char *id2, t_info *info);
void		set_pixel(SDL_Surface *surface, int x, int y,
			  Uint32 pixel);
/*
**REFRESH
*/
int		anim_ant(int id_room_start, int id_room_end,
			 t_info *info);
int		del_ant_in_room(char *id, t_info *info, char *room);
int		add_ant_in_room(char *id, char *room, t_info *info);

/*
**THREAD
*/
int		aff_info_all(t_info *info);

/*
** ADD
*/
void		put_error(char *str);
int		tread_line(char *str, t_info *info);
int		update_all(char *id, char *room, t_info *info);
void		find_max(t_info *info);
void		my_bzero(void *ptr, int size, char val);
int		my_strcmp(char *str, char *str2);
void		my_put_error(char *str);

#endif /* !MAIN_H */
