/*
** draw2.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:22:38 2016 THEIS Paul
** Last update Thu Apr 21 18:02:02 2016 THEIS Paul
*/

#include "main.h"

void	check_nbr_room(t_info *info)
{
  if (info->nbr_room >= 511)
    {
      exit (0);
      printf("Error : Number maximum of room must be inferior at 512\n");
    }
  else
    info->nbr_room++;
}

void		parse_decl(char *str, t_info *info, int opt, int cmptr)
{
  char		id[4096];
  SDL_Rect	pos;
  SDL_Rect	pos2;

  //pos = xalloc(sizeof(SDL_Rect));
  //pos2 = xalloc(sizeof(SDL_Rect));
  //init_t_pos(pos, pos2);
  pos = set_pos(0, 0);
  pos2 = set_pos(0, 0);
  while (str[pos2.x])
    {
      if (str[pos2.x] == ' ')
    	cmptr++;
      else if (str[pos2.x] >= '0' && str[pos2.x] <= '9')
    	if (cmptr == 1)
    	  pos.x = pos.x * 10 + (str[pos2.x] - '0');
    	else if (cmptr == 2)
    	  pos.y = pos.y * 10 + (str[pos2.x] - '0');
    	else
    	  id[pos2.y++] = str[pos2.x];
      else
	id[pos2.y++] = str[pos2.x];
      pos2.x++;
    }
  id[pos2.y] = 0;
  check_nbr_room(info);
  save_room(id, &pos, info, opt);
}

void		ml(SDL_Surface* surf, SDL_Rect *pos1, SDL_Rect *pos2)
{
  int		Dx;
  int		Dy;
  SDL_Rect	incr;

  Dx = abs(pos2->x - pos1->x);
  Dy = abs(pos2->y - pos1->y);
  if (pos1->x < pos2->x)
    incr.x = 1;
  else
    incr.x = -1;
  if (pos1->y < pos2->y)
    incr.y = 1;
  else
    incr.y = -1;
  if (Dx > Dy)
    step1(pos1, pos2, incr, surf);
  else
    step2(pos1, pos2, incr, surf);
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
  i = 0;
  while (i < 512)
    {
      if (info->element[i].id != NULL)
      	{
      	  if (strcmp(info->element[i].id, id1) == 0)
	    grep_coor(i, pos1, info);
      	  else if (strcmp(info->element[i].id, id2) == 0)
      	    grep_coor(i, pos2, info);
      	}
      i++;
    }
  draw_line(pos1, pos2, info);
  aff_room(id1, pos1->x, pos1->y, info);
  aff_room(id2, pos2->x, pos2->y, info);
  free(pos1);
  free(pos2);
}
