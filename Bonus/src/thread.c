/*
** thread.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:24:04 2016 THEIS Paul
** Last update Sat Apr 23 17:30:19 2016 THEIS Paul
*/

#include "main.h"

void	aff_info_all(t_info *info)
{
  int	i;

  i = 0;
  while (i < BUFF_SIZE)
    {
      if (info->elem[i].id != NULL)
	{
	  aff_info(info->elem[i].id, info->elem[i].pos.x,
		   info->elem[i].pos.y, info);
	  if (info->elem[i].nbr_ants >= 1)
	    put_ant_screen(info->elem[i].pos.x, info->elem[i].pos.y, info);
	}
      i++;
    }
}

void	parse_thread(char *str, t_info *info, int i, int j)
{
  char	id2[BUFF_SIZE];
  char	id1[BUFF_SIZE];
  int	flag;
  int	k;

  k = 0;
  flag = 0;
  --i;
  while (str[++i])
      ((str[i] == C_MIN) ? (++flag) : ((flag == 0) ? id1[j++] = str[i] :
	(id2[k++] = str[i])));
  id1[j] = 0;
  id2[k] = 0;
  draw_tunel(id1, id2, info);
}
