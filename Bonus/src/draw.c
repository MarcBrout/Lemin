/*
** draw.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:22:03 2016 THEIS Paul
** Last update Sun Apr 24 17:49:18 2016 marc brout
*/

#include "main.h"

void		set_pixel(SDL_Surface *surface, int x, int y,
			  Uint32 pixel)
{
  int		a;
  unsigned char *p;

  if (y < surface->h && y >= 0 && x < surface->w && x >= 0)
    {
      a = surface->format->BytesPerPixel;
      p = (unsigned char *)surface->pixels + y * surface->pitch + x * a;
      if (a == 4)
	*(unsigned long *)p = pixel;
    }
}

void		update_screen(t_info *info)
{
  SDL_Rect	pos;

  pos.x = SPACE_1;
  pos.y = SPACE_1;
  SDL_FillRect(info->screen, NULL, setter_color(0, 0, 0));
  SDL_BlitSurface(info->space, NULL, info->screen, &pos);
  init_toolbar(info);
  aff_round(info);
  aff_info_all(info);
}
