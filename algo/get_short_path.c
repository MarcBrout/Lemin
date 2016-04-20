/*
** get_short_path.c for lemin.h in ~/RENDU/CPE/CPE_2015_Lemin/algo
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Apr 13 11:28:34 2016 marc brout
** Last update Wed Apr 20 21:11:39 2016 marc brout
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int		piles_same_tube(t_tube *root1, t_tube *root2)
{
  t_tube	*cur1;
  t_tube	*cur2;

  cur1 = root1->next;
  while (cur1)
    {
      cur2 = root2->next;
      while (cur2)
	{
	  if (cur1->room->id == cur2->room->id)
	    return (1);
	  cur2 = cur2->next;
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
  my_printf("combien à enlever?\n");
  while (cur != root)
    {
      if (cur != one &&
	  cur->pile->next->room->id != one->pile->next->room->id)
	total += piles_same_tube(one->pile, cur->pile);
      cur = cur->next;
    }
  my_printf("Finit de compter combien à enlever : total = %d\n", total);
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
      my_printf("on enlève la première\n");
      tmp = one->next;
      remove_pile(one);
    }
  else if (nb2 > nb)
    my_printf("on enlève la seconde\n"), remove_pile(sec);
  else
    {
      if (one->count > sec->count)
	{
	  my_printf("2 on enlève la première\n");
	  tmp = one->next;
	  remove_pile(one);
	}
      else
	my_printf("on enlève la seconde\n"), remove_pile(sec);
    }
  return (tmp);
}

void		get_short_paths(t_larg *root)
{
  char		go;
  t_larg	*cur;

  go = 1;
  my_printf("C'EST PARTIT POUR LA RECHERCHE\n");
  while (go)
    {
      cur = root->next;
      go = 0;
      my_printf("on lance une boucle\n");
      while (cur != root && cur->next != root)
	{
	  verif_elem(cur, cur->pile);
	  verif_elem(cur->next, cur->next->pile);
	  if (cur->pile->next->room->id ==
	      cur->next->pile->next->room->id)
	    {
	      my_printf("on compare\n");
	      cur = compare_piles(root, cur, cur->next);
	      go = 1;
	    }
	  else
	    my_printf("go next cur\n"), cur = cur->next;
	}
    }
  my_printf("C'EST FINIT\n");
}

int		count_paths(t_larg *root)
{
  int		i;
  t_larg	*cur;

  i = 0;
  cur = root->next;
  while (cur != root)
    {
      i++;
      cur = cur->next;
    }
  return (i);
}
