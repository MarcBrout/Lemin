/*
** tri.c for lemin in /home/brout_m/RENDU/CPE/CPE_2015_Lemin/algo
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Apr 12 15:38:47 2016 marc brout
** Last update Sat Apr 16 18:58:28 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "lemin.h"

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
      cur = piles;
      while (cur && cur->next)
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
      cur = piles;
      while (cur && cur->next)
	{
	  if (id && cur->pile->next->room->id ==
	      cur->next->pile->next->room->id &&
	      cur->count < cur->next->count && (go = 1))
	    swap_value(cur, cur->next);
	  else if (!id && cur->count < cur->next->count && (go = 1))
	    swap_value(cur, cur->next);
	  cur = cur->next;
	}
    }
}

t_tube		*copy_pile(t_tube *pile)
{
  t_tube	*cur;
  t_tube	*tmp;
  t_tube	*first;
  t_tube	*elem;

  if (!(cur = pile))
    return (NULL);
  tmp = NULL;
  while (cur)
    {
      if (!(elem = malloc(sizeof(t_tube))))
	return (my_put_error(MALLOC_ERR), NULL);
      elem->room = cur->room;
      elem->branch = cur->branch;
      elem->next = NULL;
      if (tmp)
	tmp->next = elem;
      if (cur == pile)
	first = elem;
      if (cur != pile)
	tmp = elem;
      cur = cur->next;
    }
  return (first);
}

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
