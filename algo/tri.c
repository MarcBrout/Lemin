/*
** tri.c for lemin in /home/brout_m/RENDU/CPE/CPE_2015_Lemin/algo
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Apr 12 15:38:47 2016 marc brout
** Last update Wed Apr 20 22:46:15 2016 marc brout
*/

#include <stdlib.h>
#include <stdbool.h>
#include "lemin.h"
#include "my.h"

void		swap_value(t_larg *pile1, t_larg *pile2)
{
  t_larg	tmp;

  tmp.count = pile1->count;
  tmp.pile = pile1->pile;
  pile1->count = pile2->count;
  pile1->pile = pile2->pile;
  pile2->count = tmp.count;
  pile2->pile = tmp.pile;
}

void		tri_piles_by_branch(t_larg *piles)
{
  char		go;
  t_larg	*cur;

  go = 1;
  while (go)
    {
      go = 0;
      cur = piles->next;
      while (cur && cur->next != piles)
	{
	  if (cur->pile->next->room->id <
	      cur->next->pile->next->room->id)
	    {
	      swap_value(cur, cur->next);
	      go = 1;
	    }
	  cur = cur->next;
	}
    }
}

void		tri_piles_by_length(t_larg *piles, char id)
{
  char		go;
  t_larg	*cur;

  go = 1;
  while (go)
    {
      go = 0;
      cur = piles->next;
      while (cur && cur->next != piles)
	{
	  if (id && cur->pile->next->room->id ==
	      cur->next->pile->next->room->id &&
	      cur->count > cur->next->count && (go = 1))
	    swap_value(cur, cur->next);
	  else if (!id && cur->count > cur->next->count && (go = 1))
	    swap_value(cur, cur->next);
	  cur = cur->next;
	}
    }
}

t_tube		*copy_maillon(t_tube *cur, t_tube **tmp, bool *i)
{
  t_tube	*first;

  if (!(first = malloc(sizeof(t_tube))))
    return (my_put_error(MALLOC_ERR), NULL);
  first->next = NULL;
  first->room = cur->room;
  first->ants = cur->ants;
  *tmp = first;
  *i = true;
  return (first);
}

t_tube		*copy_pile(t_tube *pile)
{
  t_tube	*cur;
  t_tube	*tmp;
  t_tube	*first;
  bool		i;
  t_tube	*elem;

  cur = pile;
  i = false;
  while (cur)
    {
      if (!i)
	{
	  if (!(first = copy_maillon(cur, &tmp, &i)))
	    return (NULL);
	}
      else
	{
	  if (!(elem = malloc(sizeof(t_tube))))
	    return (my_put_error(MALLOC_ERR), NULL);
	  elem->next = NULL, elem->room = cur->room;
	  elem->ants = cur->ants, tmp->next = elem, tmp = elem;
	}
      cur = cur->next;
    }
  return (first);
}
