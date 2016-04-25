/*
** sort.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:24:29 2016 THEIS Paul
** Last update Mon Apr 25 17:11:15 2016 marc brout
*/

#include "main.h"

int	verif_id(t_info *info, char *id)
{
  int	i;

  i = -1;
  while (++i < BUFF_SIZE)
    if (info->elem[i].id != NULL)
      if (my_strcmp(info->elem[i].id, id) == 0)
	return (i);
  return (my_put_error("Error : Room not found\n"), -1);
}

int	verif_id_ant(t_info *info, char *id)
{
  int	i;

  i = -1;
  while (++i < BUFF_SIZE / 4)
    if (info->ants[i].id != NULL)
      if (my_strcmp(info->ants[i].id, id) == 0)
	return (i);
  return (my_put_error("Error : Ant not found\n"), -1);
}

int	save_room(char *id, SDL_Rect *pos, t_info *info, int opt)
{
  (opt == 1) ? (info->elem[info->nbr_room].nbr_ants = info->nbr_ants) :
	       (info->elem[info->nbr_room].nbr_ants = 0);
  info->elem[info->nbr_room].opt = opt;
  info->elem[info->nbr_room].pos.x = pos->x;
  info->elem[info->nbr_room].pos.y = pos->y;
  info->elem[info->nbr_room].opt = opt;
  if (!(info->elem[info->nbr_room].id = xalloc((my_strlen(id) + 1)
					       * sizeof(*id))))
    return (1);
  my_bzero(info->elem[info->nbr_room].id,
	    (my_strlen(id) + 1) * sizeof(*id), 0);
  my_strcpy(info->elem[info->nbr_room].id, id);
  return (0);
}
