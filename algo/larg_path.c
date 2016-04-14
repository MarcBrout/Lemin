/*
** larg_path.c for larg in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue Apr 12 14:47:52 2016 benjamin duhieu
** Last update Wed Apr 13 12:35:23 2016 benjamin duhieu
*/

#include "lemin.h"

void		remove_pile(t_larg *new_elem)
{
  free_pile(new_elem->pile);
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
      if (id == new_elem->room->id)
	return (1);
      new_elem = new_elem->next;
    }
  return (0);
}

int		add_path(t_tube *tub, t_larg *act, t_larg *root)
{
  t_larg	*new;

  if (!(new = malloc(sizeof(t_larg))))
    return (1);
  new->next = root->prev;
  new->prev = root;
  root->prev->next = new;
  root->prev = new;
  new->count = act->count + 1;
  new->valid = act->valid;
  if (!(new->pile = copy_pile(act->pile)))
    return (1);
  return (0);
}

int		add_pile(t_room *room, t_tube *pile)
{
  t_tube	*elem;

  if (!(elem = malloc(sizeof(t_tube))))
    return (1);
  elem->next = pile->prev;
  elem->prev = pile;
  pile->prev->next = elem;
  pile->prev = elem;
  elem->room = room;
  return (0);
}

int		copy_new_pile(t_tube *tub, t_larg *act, t_larg *root)
{
  if (add_path(tub, act, root))
    return (1);
  if (add_pile(tub->room, root->prev->pile))
    return (1);
  return (0);
}

int		add_pile(t_larg *elem, t_larg *root)
{
  t_tube	*new_elem;
  bool		valid;

  new_elem = elem->pile->room->tubes;
  while (new_elem)
    {
      if (chk_id(new_elem->room->id, elem))
	{
	  new_elem = new_elem->next;
	  continue ;
	}
      if (copy_new_pile(new_elem, elem, root))
	return (1);
    }
  remove_pile(elem);
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
