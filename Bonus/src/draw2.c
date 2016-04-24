/*
** draw2.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:22:38 2016 THEIS Paul
** Last update Sun Apr 24 16:30:24 2016 THEIS Paul
*/

#include "main.h"

void		line1(SDL_Surface* surf, SDL_Rect *pos1, SDL_Rect *pos2)
{
  int d;
  SDL_Rect	posd;
  SDL_Rect	inc;
  SDL_Rect	posinc;
  SDL_Rect	pos;

  posinc.x = (pos2->x > pos1->x) ? (1) : (-1);
  posd = set_pos(abs(pos2->x- pos1->x), pos2->y - pos1->y);
  d = 2 * posd.x - posd.y;
  inc = set_pos(2 * (posd.x - posd.y), 2 * posd.x);
  pos = set_pos(pos1->x, pos1->y);
  set_pixel(surf, pos.x, pos.y, setter_color(0, 0, 255));
  pos.y = pos1->y;
  while (++pos.y <= pos2->y)
    {
      if (d >= 0)
	{
	  pos.x += posinc.x;
	  d += inc.x;
	}
      else
	d += inc.y;
      set_pixel(surf, pos.x, pos.y, setter_color(0, 0, 255));
    }
}

void		line2(SDL_Surface* surf, SDL_Rect *pos1, SDL_Rect *pos2)
{
  int d;
  SDL_Rect	posd;
  SDL_Rect	inc;
  SDL_Rect	posinc;
  SDL_Rect	pos;

  posinc.y = pos2->y > pos1->y ? 1 : -1;
  posd = set_pos(pos2->x- pos1->x, abs(pos2->y - pos1->y));
  d = 2 * posd.y - posd.x;
  inc = set_pos(2 * (posd.y - posd.x), 2 * posd.y);
  pos = set_pos(pos1->x, pos1->y);
  set_pixel(surf, pos.x, pos.y, setter_color(0, 0, 255));
  pos.x = pos1->x;
  while (++pos.x <= pos2->x)
    {
      if (d >= 0)
	{
	  pos.y += posinc.y;
	  d += inc.x;
	}
      else
	d += inc.y;
      set_pixel(surf, pos.x, pos.y, setter_color(0, 0, 255));
    }
}

void		draw_line(SDL_Rect *pos1, SDL_Rect *pos2, t_info *info)
{
  if (abs(pos2->x - pos1->x) < abs(pos2->y - pos1->y))
    {
      if (pos1->y > pos2->y)
	{
	  swap_int(&pos1->x, &pos2->x);
	  swap_int(&pos1->y, &pos2->y);
	}
	line1(info->space, pos1, pos2);
    }
    else
    {
	if (pos1->x > pos2->x) {
	  swap_int(&pos1->x, &pos2->x);
	  swap_int(&pos1->y, &pos2->y);
	}
      line2(info->space, pos1, pos2);
    }
}

void	draw_tunel(char *id1, char *id2, t_info *info)
{
  int		i;
  SDL_Rect	*pos1;
  SDL_Rect	*pos2;

  pos1 = xalloc(sizeof(SDL_Rect));
  init_SDL_Rect(pos1);
  pos2 = xalloc(sizeof(SDL_Rect));
  init_SDL_Rect(pos2);
  i = -1;
  while (++i < BUFF_SIZE)
    {
      if (info->elem[i].id != NULL)
      	{
      	  ((strcmp(info->elem[i].id, id1) == 0) ? (get_coor(i, pos1, info)) :
	   ((strcmp(info->elem[i].id, id2) == 0) ? (get_coor(i, pos2, info)) :
	   (0)));
      	}
    }
  find_max(info);
  pos1->x = pos1->x * info->spacer.x + 50;
  pos1->y = pos1->y * info->spacer.y + 50;
  pos2->x = pos2->x * info->spacer.x + 50;
  pos2->y = pos2->y * info->spacer.y + 50;
  draw_line(pos1, pos2, info);
  aff_room(id1, pos1->x, pos1->y, info);
  aff_room(id2, pos2->x, pos2->y, info);
  free(pos1);
  free(pos2);
}
