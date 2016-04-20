/*
** free_pil.c for free_pil in /home/brout_m/RENDU/CPE/CPE_2015_Lemin
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Apr 20 22:40:20 2016 marc brout
** Last update Wed Apr 20 22:45:57 2016 marc brout
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
