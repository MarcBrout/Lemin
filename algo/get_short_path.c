/*
** get_short_path.c for lemin.h in ~/RENDU/CPE/CPE_2015_Lemin/algo
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Apr 13 11:28:34 2016 marc brout
** Last update Sat Apr 16 15:18:01 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "lemin.h"

int		piles_same_tube(t_tube *root1, t_tube *root2)
{
  t_tube	*cur1;
  t_tube	*cur2;

  cur1 = root1->next;
  while (cur1 != root1)
    {
      cur2 = root2->next;
      while (cur2 != root2)
	{
	  if (cur1->room->id == cur2->room->id)
	    return (1);
	  cur1 = cur2->next;
	}
      cur1 = cur1->next;
    }
  return (0);
}

int		how_many_to_remove(t_larg *one, t_larg *root)
{
  int		total;
  t_larg	*cur;

  total = 0;
  cur = root->next;
  while (cur != root)
    {
      if (cur != one &&
	  cur->pile->next->room->id != one->pile->next->room->id)
	total += piles_same_tube(one->pile, cur->pile);
      cur = cur->next;
    }
  return (total);
}

t_larg		*compare_piles(t_larg *root, t_larg *one, t_larg *sec)
{
  t_larg	*tmp;
  int		nb;
  int		nb2;

  tmp = one->prev->next;
  if ((nb = how_many_to_remove(one, root)) >
      (nb2 = how_many_to_remove(sec, root)))
    {
      tmp = one->next;
      remove_pile(one);
    }
  else if (nb2 > nb)
    remove_pile(sec);
  else
    {
      if (one->count > sec->count)
	{
	  tmp = one->next;
	  remove_pile(one);
	}
      else
	remove_pile(sec);
    }
  return (tmp);
}

void		get_short_paths(t_larg *root)
{
  char		go;
  /* int		nb; */
  /* t_larg	*to_delete; */
  t_larg	*cur;

  go = 1;
  /* nb = 0; */
  while (go)
    {
      cur = root->next;
      /* to_delete = NULL; */
      go = 0;
      while (cur != root && cur->next != root)
	{
	  if (cur->pile->next->room->id ==
	      cur->next->pile->next->room->id)
	    {
	      cur = compare_piles(root, cur, cur->next);
	      go = 1;
	    }
	  else
	    cur = cur->next;
	}
    }
}

int		count_paths(t_larg *root)
{
  int		i;
  t_larg	*cur;

  i = 0;
  cur = cur->next;
  while (cur != root)
    ++i;
  return (i);
}
