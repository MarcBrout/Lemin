/*
** draw.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:22:03 2016 THEIS Paul
** Last update Sat Apr 23 20:05:19 2016 marc brout
*/

#include "main.h"

void		set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
  int		bpp;
  unsigned char *p;

  if (y < surface->h && y >= 0 && x < surface->w && x >= 0)
    {
      bpp = surface->format->BytesPerPixel;
      p = (unsigned char *)surface->pixels + y * surface->pitch + x * bpp;
      if (bpp == 4)
	*(unsigned long *)p = pixel;
    }
}
