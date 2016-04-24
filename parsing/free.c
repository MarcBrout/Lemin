/*
** free.c for lemin in ~/RENDU/CPE/CPE_2015_Lemin
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Apr 11 17:13:12 2016 marc brout
** Last update Sun Apr 24 13:27:27 2016 marc brout
*/

#include <stdlib.h>
#include "lemin.h"

void		free_tubes(t_tube *tubes)
{
  t_tube	*cur;
  t_tube	*tmp;

  cur = tubes;
  while (cur)
    {
      tmp = cur->next;
      free(cur);
      cur = tmp;
    }
}

void		free_graph(t_room *root)
{
  t_room	*cur;
  t_room	*tmp;

  cur = root->next;
  while (cur && cur != root)
    {
      tmp = cur->next;
      free(cur->name);
      free_tubes(cur->tubes);
      free(cur);
      cur = tmp;
    }
}

void		free_pile(t_tube *root)
{
  t_tube	*cur;
  t_tube	*tmp;

  cur = root->next;
  while (cur && cur != root)
    {
      tmp = cur->next;
      free(cur);
      cur = tmp;
    }
}

void		free_path(t_larg *root)
{
  t_larg	*tmp;
  t_larg	*cur;

  cur = root->next;
  while (cur && cur != root)
    {
      tmp = cur->next;
      free_tubes(cur->pile);
      free(cur);
      cur = tmp;
    }
  free(root);
}
