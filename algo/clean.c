/*
** clean.c for lemin in /home/brout_m/RENDU/CPE/CPE_2015_Lemin/algo
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Apr 20 21:24:42 2016 marc brout
** Last update Thu Apr 21 17:40:11 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

void		clean_paths(t_larg *root)
{
  t_larg	*cur;
  t_larg	*tmp;

  cur = root->next;
  while (cur != root)
    {
      tmp = cur->next;
      if (!cur->valid)
	remove_pile(cur);
      cur = tmp;
    }
}

int		compare_common(t_tube *first, t_tube *second)
{
  t_tube	*first_elem;
  t_tube	*second_elem;

  first_elem = first;
  while (first_elem)
    {
      second_elem = second;
      while (second_elem)
	{
	  if (!second_elem->room->first && !second_elem->room->last &&
	      !(my_strcmp(first_elem->room->name,
			  second_elem->room->name)))
	    return (1);
	  second_elem = second_elem->next;
	}
      first_elem = first_elem->next;
    }
  return (0);
}

void		tri_by_common(t_larg *root)
{
  t_larg	*elem;
  t_larg	*cur;
  t_larg	*tmp;

  elem = root->next;
  while (elem != root)
    {
      cur = elem->next;
      while (cur != root)
	{
	  if (compare_common(elem->pile, cur->pile))
	    {
	      tmp = cur;
	      cur = cur->next;
	      remove_pile(tmp);
	    }
	  else
	    cur = cur->next;
	}
      elem = elem->next;
    }
}
