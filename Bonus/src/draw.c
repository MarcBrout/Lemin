/*
** draw.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:22:03 2016 THEIS Paul
** Last update Sat Apr 23 16:21:50 2016 THEIS Paul
*/

#include "main.h"

void		set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
  int		bpp;
  unsigned char *p;

  if (y < surface->h && x < surface->w)
    {
      bpp = surface->format->BytesPerPixel;
      p = (unsigned char *)surface->pixels + y * surface->pitch + x * bpp;
      if (bpp == 4)
	*(unsigned long *)p = pixel;
    }
}

unsigned long	setter_color(int R, int G, int B)
{
  return ((65536*R) + (256*G) + (B));
}
