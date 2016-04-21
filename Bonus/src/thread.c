/*
** thread.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:24:04 2016 THEIS Paul
** Last update Wed Apr 20 17:50:40 2016 THEIS Paul
*/

#include "main.h"

void		do_op(SDL_Rect *pos1, t_info *info, int i)
{
  int		j;
  SDL_Rect	*pos2;

  j = 0;
  pos2 = xalloc(sizeof(*pos2));
  while (j < 512)
    {
      if (info->element[j].id != NULL)
	{
	  if (strcmp(info->element[i].id, info->element[j].id) != 0)
	    {
	      pos2->x = info->element[j].x;
	      pos2->y = info->element[j].y;
	      draw_line(pos1, pos2, info);
	    }
	}
      j++;
    }
  free(pos2);
}

void	redraw_thread(t_info *info)
{
  int		i;
  SDL_Rect	*pos1;

  pos1 = xalloc(sizeof(*pos1));
  i = 0;
  while (i < 512)
    {
      if (info->element[i].id != NULL)
	{
	  pos1->x = info->element[i].x;
	  pos1->y = info->element[i].y;
	  do_op(pos1, info, i);
	}
      i++;
    }
  free(pos1);
}

void	aff_info_all(t_info *info)
{
  int	i;

  i = 0;
  while (i < 512)
    {
      if (info->element[i].id != NULL)
	{
	  aff_info(info->element[i].id, info->element[i].x,
		   info->element[i].y, info);
	  if (info->element[i].nbr_ants >= 1)
	    put_ant_screen(info->element[i].x, info->element[i].y, info);
	}
      i++;
    }
}
