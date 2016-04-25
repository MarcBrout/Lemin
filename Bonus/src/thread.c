/*
** thread.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:24:04 2016 THEIS Paul
** Last update Mon Apr 25 15:48:22 2016 marc brout
*/

#include "main.h"

int	aff_info_all(t_info *info)
{
  int	i;

  i = 0;
  find_max(info);
  while (i < BUFF_SIZE)
    {
      if (info->elem[i].id != NULL)
	{
	  if (aff_info(info->elem[i].id, info->elem[i].pos.x *
		       info->spacer.x
		       + 50,
		       info->elem[i].pos.y * info->spacer.y + 50, info))
	    return (1);
	  if (info->elem[i].nbr_ants >= 1)
	    if (put_ant_screen(info->elem[i].pos.x *
			       info->spacer.x + 50,
			       info->elem[i].pos.y *
			       info->spacer.y + 50, info))
	      return (1);
	}
      i++;
    }
  return (0);
}

int	parse_thread(char *str, t_info *info)
{
  char	id2[BUFF_SIZE];
  char	id1[BUFF_SIZE];
  int	flag;
  int	k;
  int	i;
  int	j;

  k = 0;
  flag = 0;
  i = -1;
  j = 0;
  while (str[++i])
    ((str[i] == C_MIN) ? (++flag) : ((flag == 0) ? id1[j++] = str[i] :
				     (id2[k++] = str[i])));
  id1[j] = 0;
  id2[k] = 0;
  if (draw_tunel(id1, id2, info))
    return (1);
  return (0);
}
