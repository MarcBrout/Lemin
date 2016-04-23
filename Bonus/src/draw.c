/*
** draw.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:22:03 2016 THEIS Paul
** Last update Sat Apr 23 15:19:43 2016 THEIS Paul
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

void	check_nbr_room(t_info *info)
{
  (info->nbr_room >= BUFF_SIZE - 1) ?
      (my_put_err("Error : Too Much Room\n", TRUE)) : (info->nbr_room++);
}

void		parse_decl(char *str, t_info *info, int opt, int cmptr)
{
  char		id[BUFF_SIZE];
  SDL_Rect	*pos1;
  SDL_Rect	*pos2;

  pos1 = xalloc(sizeof(SDL_Rect));
  iniSDL_Rect(pos1);
  pos2 = xalloc(sizeof(SDL_Rect));
  iniSDL_Rect(pos2);
  while (str[pos2->x])
    {
      if (str[pos2->x] == C_SPACE)
    	cmptr++;
      else if (is_num(str[pos2->x]))
    	if (cmptr == 1)
    	  pos1->x = pos1->x * 10 + (str[pos2->x] - '0');
    	else if (cmptr == 2)
    	  pos1->y = pos1->y * 10 + (str[pos2->x] - '0');
    	else
    	  id[pos2->y++] = str[pos2->x];
      else
	id[pos2->y++] = str[pos2->x];
      pos2->x++;
    }
  id[pos2->y] = 0;
  check_nbr_room(info);
  save_room(id, pos1, info, opt);
}
