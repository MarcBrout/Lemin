/*
** sort.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:24:29 2016 THEIS Paul
** Last update Thu Apr 21 17:50:54 2016 THEIS Paul
*/

#include "main.h"

int	sort_id(t_info *info, char *id)
{
  int	i;

  i = 0;
  while (i < 512)
    {
      if (info->element[i].id != NULL)
	{
	  if (strcmp(info->element[i].id, id) == 0)
	    return (i);
	}
      i++;
    }
  printf("Error : id (%s) of room unfoudable\n", id);
  exit (-1);
}

int	sort_id_ant(t_info *info, char *id)
{
  int	i;

  i = 0;
  while (i < 1024)
    {
      if (info->ants[i].id != NULL)
	{
	  if (strcmp(info->ants[i].id, id) == 0)
	    return (i);
	}
      i++;
    }
  printf("Error : id (%s) of ant unfoudable\n", id);
  exit (0);
}

void	set_color(SDL_Color *color, int r, int g, int b)
{
  color->r = r;
  color->g = g;
  color->b = b;
}

void	save_room(char *id, SDL_Rect *pos, t_info *info, int opt)
{
  if (opt == 1)
    info->element[info->nbr_room].nbr_ants = info->nbr_ants;
  else
    info->element[info->nbr_room].nbr_ants = 0;
  info->element[info->nbr_room].x = pos->x * 40 + 80;
  info->element[info->nbr_room].y = pos->y * 40 + 80;
  info->element[info->nbr_room].opt = opt;
  info->element[info->nbr_room].id = xalloc((strlen(id) + 1)
					    * sizeof(*id));
  memset(info->element[info->nbr_room].id, 0,
	 (strlen(id) + 1) * sizeof(*id));
  strcpy(info->element[info->nbr_room].id, id);
}

void	iniSDL_Rect(SDL_Rect *pos)
{
  pos->x = 0;
  pos->y = 0;
}
