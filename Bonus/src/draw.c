/*
** draw.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:22:03 2016 THEIS Paul
** Last update Thu Apr 21 20:33:02 2016 THEIS Paul
*/

#include "main.h"

void	swapint(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
}

void		PutPixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
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

unsigned long	convert_color(int R, int G, int B)
{
  return 65536*R + 256*G + B;
}

void	step2(SDL_Rect *pos1, SDL_Rect *pos2, SDL_Rect incr, SDL_Surface *surf)
{
  int	error;
  int	dx;
  int	dy;
  int	x;
  int	y;
  int	i;

  x = pos1->x;
  y = pos1->y;
  dx = abs(pos2->x - pos1->x);
  dy = abs(pos2->y - pos1->y);
  error = dy / 2;
  i = 0;
  while (i < dy)
    {
      y += incr.y;
      error += dx;
      if (error > dy)
	{
	  error -= dy;
	  x += incr.x;
	}
      PutPixel(surf, x + 50, y + 50, convert_color(255, 0, 0));
      i++;
    }
}

void	step1(SDL_Rect *pos1, SDL_Rect *pos2, SDL_Rect incr, SDL_Surface *surf)
{
  int	error;
  int	dx;
  int	dy;
  int	x;
  int	y;
  int	i;

  x = pos1->x;
  y = pos1->y;
  dx = abs(pos2->x - pos1->x);
  dy = abs(pos2->y - pos1->y);
  error = dx / 2;
  i = 0;
  while (i < dx)
    {
      x += incr.x;
      error += dy;
      if (error > dx)
	{
	  error -= dx;
	  y += incr.y;
	}
      PutPixel(surf, x + 50, y + 50, convert_color(0, 255, 0));
      i++;
    }
}
