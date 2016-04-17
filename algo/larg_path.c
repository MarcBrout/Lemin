/*
** larg_path.c for larg in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue Apr 12 14:47:52 2016 benjamin duhieu
** Last update Sun Apr 17 11:38:32 2016 marc brout
*/

#include <stdlib.h>
#include <stdbool.h>
#include "lemin.h"
#include "my.h"

void		remove_pile(t_larg *new_elem)
{
  free_pil(new_elem->pile);
  new_elem->prev->next = new_elem->next;
  new_elem->next->prev = new_elem->prev;
  free(new_elem);
}

int		chk_id(int id, t_larg *elem)
{
  t_tube	*new_elem;

  new_elem = elem->pile;
  while (new_elem)
    {
      my_printf("id : %d && elem->room->id : %d\n", id, new_elem->room->id);
      if (id == new_elem->room->id)
	return (1);
      new_elem = new_elem->next;
    }
  /* my_printf("--------------\n", id, new_elem->room->id); */
  return (0);
}

int		copy_new_pile(t_tube *tub, t_larg *act, t_larg *root)
{
  if (add_path(act, root))
    return (1);
  my_printf("BBBBBBBBBBBBBB\n");
  if (tub->room->last)
    act->valid = 1;
  if (add_elem_to_pile(tub->room, root->prev->pile))
    return (1);
  my_printf("CCCCCCCCCCCCCCC\n");
  return (0);
}

int		browse_graph(t_larg *root)
{
  t_larg	*new_elem;
  bool		pass;

  pass = true;
  while (pass)
    {
      pass = false;
      new_elem = root->next;
      while (new_elem != root)
	{
	  my_printf("valid ? %d\n", new_elem->valid);
	  if (!new_elem->valid)
	    {
	      if (add_pil(new_elem, root))
		return (1);
	      pass = true;
	    }
	  new_elem = new_elem->next;
	}
    }
  return (0);
}
