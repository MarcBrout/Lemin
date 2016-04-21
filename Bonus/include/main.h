/*
** main.h for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:30:56 2016 THEIS Paul
** Last update Thu Apr 21 20:28:59 2016 THEIS Paul
*/

#ifndef MAIN_H
# define MAIN_H
#define	W_W	1280
#define STATBAR_H 50
#define TOOLBAR_H 120
#define SPACE_H 600
#define SPACE_1 5
#define W_H (TOOLBAR_H + SPACE_H)

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

# include <SDL/SDL.h>
# include <SDL2/SDL.h>
# include <SDL/SDL_ttf.h>
# include <SDL/SDL_image.h>
# include <SDL/SDL_rotozoom.h>

# define	FALSE		0
# define	TRUE		!FALSE
# define	BUFF_SIZE	4096

typedef unsigned char		bool;

# include "str.h"
# include "get_next_line.h"
# include "display.h"


typedef struct 	s_elem
{
  int		x;
  int		y;
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
  t_elem	elem[BUFF_SIZE];
  int		current;
  int		nbr;
  int		nbr_room;
  int		nbr_fourm;
  int		nbr_ants;
  SDL_Rect	pos;
  t_ants	ants[1024];
  int		round;
  int		opt;
  int		speed;
  SDL_Color	black;
}		t_info;

/* TOOL */
SDL_Rect	set_pos(int x, int y);

void		init_struct(t_info *info);
void		init_toolbar(t_info *info);
void		init_space(t_info *info);
void		init_statbar(t_info *info);

void		aff_round(t_info *info);
void		aff_info(char *id_room, int x, int y, t_info *info);
void		aff_room(char *id_room, int x, int y, t_info *info);
void		init_t_pos(SDL_Rect *pos1, SDL_Rect *pos2);
void		grep_coor(int i, SDL_Rect *pos, t_info *info);
int		sort_id(t_info *info, char *id);
void		put_error(char *str);
void		check_nbr_ants(char *str, t_info *info);
int		sort_id_ant(t_info *info, char *id);
void		set_color(SDL_Color *color, int r, int g, int b);
void		save_room(char *id, SDL_Rect *pos, t_info *info, int opt);
void		iniSDL_Rect(SDL_Rect *pos);
void		do_op(SDL_Rect *pos1, t_info *info, int i);
void		redraw_thread(t_info *info);
void		aff_info_all(t_info *info);
void		parse(t_info *info);
void		tread_line(char *str, t_info *info);
void		decision(SDL_Rect flag, SDL_Rect pos, char *str, t_info *info);
void		parse_path(char *str, t_info *info);
void		parse_thread(char *str, t_info *info, int i, int j);
void		swapint(int *x, int *y);
void		PutPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
void		step2(SDL_Rect *pos1, SDL_Rect *pos2, SDL_Rect incr, SDL_Surface *surf);
void		step1(SDL_Rect *pos1, SDL_Rect *pos2, SDL_Rect incr, SDL_Surface *surf);
void		parse_decl(char *str, t_info *info, int opt, int cmptr);
void		ml(SDL_Surface* surf, SDL_Rect *pos1, SDL_Rect *pos2);
void		draw_line(SDL_Rect *pos1, SDL_Rect *pos2, t_info *info);
void		draw_tunel(char *id1, char *id2, t_info *info);
void		update_all(char *id, char *room, t_info *info);
unsigned long	convert_color(int R, int G, int B);
void		ants_path(char *str, t_info *info);
void		set_property_ants_all(int total, t_info *info, char *id);
void		put_ants_room(t_info *info, int nbr);
void		put_ants_room(t_info *info, int nbr);
void		update_screen(t_info *info);
void		put_ant_screen(int x, int y, t_info *info);
void		anim_ant(int id_room_start, int id_room_end, t_info *info);
void		del_ant_in_room(char *id, t_info *info, char *room);
void		add_ant_in_room(char *id, char *room, t_info *info);

#endif /* MAIN_H */