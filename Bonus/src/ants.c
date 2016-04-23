/*
** ants.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:20:38 2016 THEIS Paul
** Last update Sat Apr 23 14:42:17 2016 THEIS Paul
*/

#include "main.h"

void	update_all(char *id, char *room, t_info *info)
{
  del_ant_in_room(id, info, room);
  add_ant_in_room(id, room, info);
  update_screen(info);
}

void	ants_path(char *str, t_info *info)
{
  char	id[BUFF_SIZE];
  char	room[BUFF_SIZE];
  int	i;
  int	j;

  i = 0;
  while (str[i])
    {
      j = 0;
      if (str[i++] == C_FLAG)
	{
	  while (str[i] != C_MIN)
	    id[j++] = str[i++];
	  id[j] = 0;
	  if (str[i++] == C_MIN)
	    {
	      j = 0;
	      while (str[i] && str[i] != C_SPACE)
		room[j++] = str[i++];
	      room[j] = 0x00;
	    }
	  update_all(id, room, info);
	}
      i += ((str[i]) ? (1) : (0));
    }
  info->round++;
}

void	set_property_ants_all(int total, t_info *info, char *id)
{
  int	i;

  i = 0;
  while (i < total)
    {
      info->ants[i].id = xalloc(BUFF_SIZE * sizeof(char));
      sprintf(info->ants[i].id, "%d", i + 1);
      info->ants[i].room = xalloc(BUFF_SIZE * sizeof(char));
      sprintf(info->ants[i].room, "%s", id);
      i++;
    }
}

void	put_ants_room(t_info *info, int nbr)
{
  int	i;

  i = -1;
  while (++i < BUFF_SIZE)
    if (info->elem[i].id != NULL)
	if (info->elem[i].nbr_ants == nbr)
	    set_property_ants_all(info->elem[i].nbr_ants, info,
				  info->elem[i].id);
}
