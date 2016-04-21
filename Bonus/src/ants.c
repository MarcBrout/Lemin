/*
** ants.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:20:38 2016 THEIS Paul
** Last update Wed Apr 20 13:27:11 2016 THEIS Paul
*/

#include "main.h"

void	update_all(char *id, char *room, t_info *info)
{
  del_ant_in_room(id, info, room);
  add_ant_in_room(id, room, info);
  update_screen(info);
}

void	ants_path(char *str, t_info *info, int i, int j)
{
  char	id[4096];
  char	room[4096];

  while (str[i])
    {
      j = 0;
      if (str[i] == 'P')
	{
	  i++;
	  while (str[i] != '-')
	    id[j++] = str[i++];
	  id[j] = 0;
	  if (str[i] == '-')
	    {
	      i++;
	      j = 0;
	      while (str[i] != ' ' && str[i])
		room[j++] = str[i++];
	      room[j] = 0;
	    }
	  update_all(id, room, info);
	}
      i++;
    }
  info->round++;
}

void	set_property_ants_all(int total, t_info *info, char *id)
{
  int	i;

  i = 0;
  while (i < total)
    {
      info->ants[i].id = xalloc(512 * sizeof(char));
      sprintf(info->ants[i].id, "%d", i + 1);
      info->ants[i].room = xalloc(512 * sizeof(char));
      sprintf(info->ants[i].room, "%s", id);
      i++;
    }
}

void	put_ants_room(t_info *info, int nbr)
{
  int	i;

  i = 0;
  while (i < 512)
    {
      if (info->element[i].id != NULL)
	{
	  if (info->element[i].nbr_ants == nbr)
	    {
	      set_property_ants_all(info->element[i].nbr_ants, info,
				    info->element[i].id);
	    }
	}
      i++;
    }
}
