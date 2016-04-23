/*
** aff.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:25:04 2016 THEIS Paul
** Last update Sat Apr 23 15:25:02 2016 THEIS Paul
*/

#include "main.h"

void		aff_round(t_info *info)
{
  SDL_Rect	pos;
  SDL_Surface	*txt;
  SDL_Color	color;
  char		str[BUFF_SIZE];

  sprintf(str, "Round : %d", info->round);
  set_color(&color, 230, 230, 230);
  txt = TTF_RenderText_Blended(info->font, str, color);
  txt = rotozoomSurface(txt, 0, 3.2, 1);
  pos = set_pos(20, W_H - 90);
  SDL_BlitSurface(txt, NULL, info->screen, &pos);
  free(txt);
}

void		aff_info(char *id_room, int x, int y, t_info *info)
{
  SDL_Rect	pos;
  SDL_Surface	*txt;
  SDL_Color	color;
  int		id;
  char		str[BUFF_SIZE];

  id = sort_id(info, id_room);
  ((info->elem[id].opt == 1) ? (set_color(&color, 255, 0, 0)) :
      ((info->elem[id].opt == 2) ? (set_color(&color, 0, 255, 0)) :
       set_color(&color, 230, 230, 230)));
  sprintf(str, "#%s - %d ants", id_room, info->elem[id].nbr_ants);
  if (x >= 0 && x < info->screen->w && y >= 0 && y < info->screen->h)
	{
	  txt = TTF_RenderText_Blended(info->font, str, color);
	  pos = set_pos(x - 25, y + 30);
	  SDL_BlitSurface(txt, NULL, info->screen, &pos);
	}
  free(txt);
}

void		aff_room(char *id_room, int x, int y, t_info *info)
{
  SDL_Rect	pos;
  SDL_Surface	*room;

  if (x >= 0 && x < info->screen->w && y >= 0 && y < info->screen->h)
       {
	  info->nbr = 0;
	  pos = set_pos(x - 25, y - 25);
	  aff_info(id_room, pos.x, pos.y, info);
	  room = IMG_Load("img/room.png");
	  SDL_BlitSurface(room, NULL, info->space, &pos);
	  free(room);
	}
}

void	init_t_pos(SDL_Rect *pos1, SDL_Rect *pos2)
{
  iniSDL_Rect(pos1);
  iniSDL_Rect(pos2);
}

void	grep_coor(int i, SDL_Rect *pos, t_info *info)
{
  pos->x = info->elem[i].x;
  pos->y = info->elem[i].y;
}
