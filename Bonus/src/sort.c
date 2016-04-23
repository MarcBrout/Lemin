/*
** sort.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:24:29 2016 THEIS Paul
** Last update Sat Apr 23 15:58:37 2016 THEIS Paul
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
  printf("Error : Room (%s) not found\n", id);
  exit (-1);
}

int	sort_id_ant(t_info *info, char *id)
{
  int	i;

  i = 0;
  while (i < BUFF_SIZE / 4)
    {
      if (info->ants[i].id != NULL)
	{
	  if (strcmp(info->ants[i].id, id) == 0)
	    return (i);
	}
      i++;
    }
  printf("Error : Ant (%s) not found\n", id);
  exit (0);
}

void	save_room(char *id, SDL_Rect *pos, t_info *info, int opt)
{
  if (opt == 1)
    info->elem[info->nbr_room].nbr_ants = info->nbr_ants;
  else
    info->elem[info->nbr_room].nbr_ants = 0;
  info->elem[info->nbr_room].pos.x = pos->x * 50 + 100;
  info->elem[info->nbr_room].pos.y = pos->y * 50 + 100;
  info->elem[info->nbr_room].opt = opt;
  info->elem[info->nbr_room].id = xalloc((strlen(id) + 1)
					    * sizeof(*id));
  memset(info->elem[info->nbr_room].id, 0,
	 (strlen(id) + 1) * sizeof(*id));
  strcpy(info->elem[info->nbr_room].id, id);
}
