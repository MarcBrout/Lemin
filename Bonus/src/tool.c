/*
** tool.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Thu Apr 21 17:32:59 2016 THEIS Paul
** Last update Sat Apr 23 16:00:12 2016 THEIS Paul
*/

#include "main.h"

void		set_color(SDL_Color *color, int r, int g, int b)
{
  color->r = r;
  color->g = g;
  color->b = b;
}

SDL_Rect	set_pos(int x, int y)
{
  SDL_Rect	pos;

  pos.x = x;
  pos.y = y;
  return (pos);
}

void		swap_int(Sint16 *a, Sint16 *b)
{
  Sint16	c;

  c = *a;
  *a = *b;
  *b = c;
}

bool		is_num(char c)
{
  return ((c >= '0' && c <= '9') ? (TRUE) : (FALSE));
}

void		get_coor(int i, SDL_Rect *pos, t_info *info)
{
  pos->x = info->elem[i].pos.x;
  pos->y = info->elem[i].pos.y;
}
