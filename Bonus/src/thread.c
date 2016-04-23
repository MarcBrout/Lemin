/*
** thread.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:24:04 2016 THEIS Paul
** Last update Thu Apr 21 18:39:22 2016 THEIS Paul
*/

#include "main.h"

void		do_op(SDL_Rect *pos1, t_info *info, int i)
{
  int		j;
  SDL_Rect	*pos2;

  j = 0;
  pos2 = xalloc(sizeof(*pos2));
  while (j < BUFF_SIZE)
    {
      if (info->elem[j].id != NULL)
	{
	  if (strcmp(info->elem[i].id, info->elem[j].id) != 0)
	    {
	      pos2->x = info->elem[j].x;
	      pos2->y = info->elem[j].y;
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
  while (i < BUFF_SIZE)
    {
      if (info->elem[i].id != NULL)
	{
	  pos1->x = info->elem[i].x;
	  pos1->y = info->elem[i].y;
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
  while (i < BUFF_SIZE)
    {
      if (info->elem[i].id != NULL)
	{
	  aff_info(info->elem[i].id, info->elem[i].x,
		   info->elem[i].y, info);
	  if (info->elem[i].nbr_ants >= 1)
	    put_ant_screen(info->elem[i].x, info->elem[i].y, info);
	}
      i++;
    }
}
