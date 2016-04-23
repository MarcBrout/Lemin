/*
** aff.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:25:04 2016 THEIS Paul
** Last update Sat Apr 23 17:14:42 2016 THEIS Paul
*/

#include "main.h"

int		get_room(t_info *info, bool a)
{
  int		i;

  i = -1;
  while (++i < BUFF_SIZE)
    {
      if (a && (info->elem[i].opt == 1))
	return (info->elem[i].nbr_ants);
      else if (!a && (info->elem[i].opt == 2))
	return (info->elem[i].nbr_ants);
    }
}

void		aff_round(t_info *info)
{
  SDL_Rect	pos;
  SDL_Surface	*txt;
  SDL_Color	color;
  char		str[BUFF_SIZE];

  sprintf(str, "Round : %d   |   Room: %d   |   Ants: %d             {Ant Man}"\
	  "              Start: %d    |    End: %d    |    Between: %d",
	  info->round, info->nbr_room, info->nbr_ants, get_room(info, TRUE),
	  get_room(info, FALSE), info->nbr_ants - (get_room(info, TRUE) +
		   get_room(info, FALSE)));
  set_color(&color, 230, 230, 230);
  txt = TTF_RenderText_Blended(info->font, str, color);
  txt = rotozoomSurface(txt, 0, 2, 1);
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
