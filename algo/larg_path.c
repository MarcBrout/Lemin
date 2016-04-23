/*
** larg_path.c for larg in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue Apr 12 14:47:52 2016 benjamin duhieu
** Last update Sat Apr 23 12:25:01 2016 marc brout
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

int		chk_id(char *name, t_larg *elem)
{
  t_tube	*new_elem;

  new_elem = elem->pile;
  while (new_elem)
    {
      if (!my_strcmp(name, new_elem->room->name))
	return (1);
      new_elem = new_elem->next;
    }
  return (0);
}

int		copy_new_pile(t_tube *tub, t_larg *act,
			      t_larg *root)
{
  if (add_path(act, root))
    return (1);
  if (tub->room->last)
    {
      root->next->valid = 1;
    }
  if (add_elem_to_pile(tub->room, root->next->pile))
    return (1);
  return (0);
}

int		browse_graph(t_larg *root)
{
  t_larg	*new_elem;
  t_larg	*tmp;
  bool		pass;

  pass = true;
  while (pass && !(pass = false) && (new_elem = root->next))
    {
      while (new_elem != root)
	{
	  if (count_paths(root) > 30000)
	    return (0);
	  if (!new_elem->valid)
	    {
	      if (add_pil(new_elem, root))
		return (1);
	      pass = true;
	      tmp = new_elem;
	      new_elem = new_elem->next;
	      remove_pile(tmp);
	    }
	  else
	    new_elem = new_elem->next;
	}
    }
  return (0);
}
