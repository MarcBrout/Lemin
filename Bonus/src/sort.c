/*
** sort.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:24:29 2016 THEIS Paul
** Last update Thu Apr 21 20:19:37 2016 THEIS Paul
*/

#include "main.h"

int	sort_id(t_info *info, char *id)
{
  int	i;

  i = 0;
  while (i < BUFF_SIZE)
    {
      if (info->elem[i].id != NULL)
	{
	  if (strcmp(info->elem[i].id, id) == 0)
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
    info->elem[info->nbr_room].nbr_ants = info->nbr_ants;
  else
    info->elem[info->nbr_room].nbr_ants = 0;
  info->elem[info->nbr_room].x = pos->x * 50 + 100;
  info->elem[info->nbr_room].y = pos->y * 50 + 100;
  info->elem[info->nbr_room].opt = opt;
  info->elem[info->nbr_room].id = xalloc((strlen(id) + 1)
					    * sizeof(*id));
  memset(info->elem[info->nbr_room].id, 0,
	 (strlen(id) + 1) * sizeof(*id));
  strcpy(info->elem[info->nbr_room].id, id);
}

void	iniSDL_Rect(SDL_Rect *pos)
{
  pos->x = 0;
  pos->y = 0;
}
