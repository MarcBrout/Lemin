/*
** add_pile.c for add_pile in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Apr 16 14:31:05 2016 benjamin duhieu
** Last update Wed Apr 20 22:48:11 2016 marc brout
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int		add_path(t_larg *act, t_larg *root)
{
  t_larg	*new;

  if (!(new = malloc(sizeof(t_larg))))
    return (1);
  new->next = root->next;
  new->prev = root;
  root->next->prev = new;
  root->next = new;
  new->count = act->count + 1;
  new->valid = act->valid;
  if (!(new->pile = copy_pile(act->pile)))
    return (1);
  return (0);
}

int		add_elem_to_pile(t_room *room, t_tube *pile)
{
  t_tube	*tmp;
  t_tube	*elem;

  tmp = pile;
  while (tmp->next)
    tmp = tmp->next;
  if (!(elem = malloc(sizeof(t_tube))))
    return (1);
  tmp->next = elem;
  elem->next = NULL;
  elem->ants = 0;
  elem->room = room;
  return (0);
}

t_tube		*last_elem_pile(t_larg *elem)
{
  t_tube	*tmp;

  tmp = elem->pile;
  while (tmp->next)
    tmp = tmp->next;
  return (tmp->room->tubes);
}

int		add_pil(t_larg *elem, t_larg *root)
{
  t_tube	*new_elem;

  new_elem = last_elem_pile(elem);
  while (new_elem)
    {
      if (chk_id(new_elem->room->name, elem))
	{
	  new_elem = new_elem->next;
	  continue ;
	}
      if (copy_new_pile(new_elem, elem, root))
	return (1);
      new_elem = new_elem->next;
    }
  return (0);
}
