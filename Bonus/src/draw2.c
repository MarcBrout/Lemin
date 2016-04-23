/*
** draw2.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:22:38 2016 THEIS Paul
** Last update Sat Apr 23 15:17:46 2016 THEIS Paul
*/

#include "main.h"

void		ml(SDL_Surface* surf, SDL_Rect *pos1, SDL_Rect *pos2)
{
  int d;
  int dx;
  int dy;
  int aincr;
  int bincr;
  int xincr;
  int yincr;
  int x;
  int y;

  if (abs(pos2->x - pos1->x) < abs(pos2->y - pos1->y)) {
	if (pos1->y > pos2->y) {
	  swap_int(&pos1->x, &pos2->x);
	  swap_int(&pos1->y, &pos2->y);
	}
      xincr = (pos2->x > pos1->x) ? (1) : (-1);
      dy = pos2->y - pos1->y;
      dx = abs(pos2->x- pos1->x);
      d = 2 * dx - dy;
      aincr = 2 * (dx - dy);
      bincr = 2 * dx;
      x = pos1->x;
      y = pos1->y;
      set_pixel(surf, x, y, setter_color(0, 0, 255));
	for (y = pos1->y + 1; y <= pos2->y; ++y) {
	    if (d >= 0) {
	      x += xincr;
	      d += aincr;
	    } else
	    d += bincr;

        set_pixel(surf, x, y, setter_color(0, 0, 255));
	}
    } else {
	if (pos1->x > pos2->x) {
	  swap_int(&pos1->x, &pos2->x);
	  swap_int(&pos1->y, &pos2->y);
	}
      yincr = pos2->y > pos1->y ? 1 : -1;
      dx = pos2->x- pos1->x;
      dy = abs(pos2->y - pos1->y);
      d = 2 * dy - dx;
      aincr = 2 * (dy - dx);
      bincr = 2 * dy;
      x = pos1->x;
      y = pos1->y;
      set_pixel(surf, x, y, setter_color(0, 0, 255));
	for (x = pos1->x + 1; x <= pos2->x; ++x) {
	    if (d >= 0) {
	      y += yincr;
	      d += aincr;
	    } else
              d += bincr;

	  set_pixel(surf, x, y, setter_color(0, 0, 255));
	    }
  }
}

void	draw_line(SDL_Rect *pos1, SDL_Rect *pos2, t_info *info)
{
  ml(info->space, pos1, pos2);
}

void	draw_tunel(char *id1, char *id2, t_info *info)
{
  int		i;
  SDL_Rect	*pos1;
  SDL_Rect	*pos2;

  pos1 = xalloc(sizeof(SDL_Rect));
  iniSDL_Rect(pos1);
  pos2 = xalloc(sizeof(SDL_Rect));
  iniSDL_Rect(pos2);
  i = -1;
  while (++i < BUFF_SIZE)
    {
      if (info->elem[i].id != NULL)
      	{
      	  if (strcmp(info->elem[i].id, id1) == 0)
	    grep_coor(i, pos1, info);
      	  else if (strcmp(info->elem[i].id, id2) == 0)
      	    grep_coor(i, pos2, info);
      	}
    }
  draw_line(pos1, pos2, info);
  aff_room(id1, pos1->x, pos1->y, info);
  aff_room(id2, pos2->x, pos2->y, info);
  free(pos1);
  free(pos2);
}
