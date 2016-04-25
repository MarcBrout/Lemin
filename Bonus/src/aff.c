/*
** aff.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:25:04 2016 THEIS Paul
** Last update Mon Apr 25 15:40:47 2016 THEIS Paul
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
  return (0);
}

int		aff_round(t_info *info)
{
  SDL_Rect	pos;
  SDL_Surface	*txt;
  SDL_Color	color;
  char		str[BUFF_SIZE];

  /* sprintf(str, "Round : %d   |   Room: %d   |   Ants: %d"\ */
  /* 	  "{Ant Man}"\ */
  /* 	  "              Start: %d    |    End: %d    |    Between: %d", */
  /* 	  info->round, info->nbr_room, info->nbr_ants, */
  /* 	  get_room(info, TRUE), */
  /* 	  get_room(info, FALSE), info->nbr_ants - */
  /* 	  (get_room(info, TRUE) + get_room(info, FALSE))); */
  str = text_round(info);
  set_color(&color, 230, 230, 230);
  if (!(txt = TTF_RenderText_Blended(info->font, str, color)) ||
      !(txt = rotozoomSurface(txt, 0, 2, 1)))
    return (1);
  pos = set_pos(20, W_H - 90);
  if (SDL_BlitSurface(txt, NULL, info->screen, &pos) < 0)
    return (1);
  if (txt)
    free(txt);
  return (0);
}

int		aff_info(char *id_room, int x, int y, t_info *info)
{
  SDL_Rect	pos;
  SDL_Surface	*txt;
  SDL_Color	color;
  int		id;
  char		str[BUFF_SIZE];

  if ((id = verif_id(info, id_room)) < 0)
    return (1);
  txt = NULL;
  ((info->elem[id].opt == 1) ? (set_color(&color, 255, 0, 0)) :
   ((info->elem[id].opt == 2) ? (set_color(&color, 0, 255, 0)) :
    set_color(&color, 230, 230, 230)));
  sprintf(str, "#%s - %d ants", id_room, info->elem[id].nbr_ants);
  if (x >= 0 && x < info->screen->w && y >= 0 && y < info->screen->h)
    pos = set_pos(x - 25, y + 30);
  if (pos.x >= 0 && pos.x < W_W && pos.y >= 0 && pos.y < W_H)
    {
      if (!(txt = TTF_RenderText_Blended(info->font, str, color)) ||
	  SDL_BlitSurface(txt, NULL, info->screen, &pos) < 0)
	return (1);
    }
  if (txt)
    free(txt);
  return (0);
}

int		aff_room(int x, int y, t_info *info)
{
  SDL_Rect	pos;
  SDL_Surface	*room;

  info->nbr = 0;
  pos = set_pos(x -25, y -25);
  if ((pos.x >= 0 && pos.x < W_W) && (pos.y >= 0 && pos.y < W_H))
    {
      if (!(room = IMG_Load("img/room.png")))
	return (my_put_error("Room.png not found\n"), 1);
      if (SDL_BlitSurface(room, NULL, info->space, &pos) < 0)
	return (1);
      free(room);
    }
  return (0);
}
