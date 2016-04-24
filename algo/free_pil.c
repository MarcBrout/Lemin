/*
** free_pil.c for free_pil in /home/brout_m/RENDU/CPE/CPE_2015_Lemin
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Apr 20 22:40:20 2016 marc brout
** Last update Sun Apr 24 14:22:54 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "lemin.h"

void		free_pil(t_tube *pile)
{
  t_tube	*cur;
  t_tube	*tmp;

  cur = pile;
  while (cur)
    {
      tmp = cur->next;
      free(cur);
      cur = tmp;
    }
}

void		free_ant(t_ant *ant, t_path **way)
{
  t_ant		*tmp;
  t_ant		*cur;
  int		i;

  i = -1;
  while (way && way[++i])
    free(way[i]);
  free(way);
  cur = ant;
  while (cur)
    {
      tmp = cur->next;
      free(cur);
      cur = tmp;
    }
}
