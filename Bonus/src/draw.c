/*
** draw.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:22:03 2016 THEIS Paul
<<<<<<< HEAD
<<<<<<< HEAD
** Last update Sat Apr 23 19:55:22 2016 benjamin duhieu
=======
** Last update Sat Apr 23 20:05:19 2016 marc brout
>>>>>>> 73b0862f14ca32db4b3470887ea057e9bee55244
=======
** Last update Sun Apr 24 15:40:44 2016 THEIS Paul
>>>>>>> 114140939418effc5751a14a72c7d5f217ed652b
*/

#include "main.h"

void		set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
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
