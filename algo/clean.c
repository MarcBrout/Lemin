/*
** clean.c for lemin in /home/brout_m/RENDU/CPE/CPE_2015_Lemin/algo
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Apr 20 21:24:42 2016 marc brout
** Last update Wed Apr 20 21:33:44 2016 marc brout
*/

#include <stdlib.h>
#include "lemin.h"

void		clean_paths(t_larg *root)
{
  t_larg	*cur;

  cur = root->next;
  while (cur != root)
    {
      if (!cur->valid)
	remove_pile(cur);
      cur = cur->next;
    }
}