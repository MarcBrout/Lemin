/*
** add_pile.c for add_pile in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Apr 16 14:31:05 2016 benjamin duhieu
** Last update Sat Apr 16 18:57:25 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int		add_path(t_larg *act, t_larg *root)
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
  my_printf("DDDDDDDDDD\n");
  if (!(new->pile = copy_pile(act->pile)))
    return (1);
  my_printf("EEEEEEEEEEEE\n");
  return (0);
}

int		add_elem_to_pile(t_room *room, t_tube *pile)
{
  t_tube	*elem;

  if (!(elem = malloc(sizeof(t_tube))))
    return (1);
  pile->next = elem;
  elem->next = NULL;
  elem->room = room;
  return (0);
}

int		add_pil(t_larg *elem, t_larg *root)
{
  t_tube	*new_elem;

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
      my_printf("|||||\n");
      new_elem = new_elem->next;
    }
  my_printf("AAAAAAAAAAA\n");
  remove_pile(elem);
  return (0);
}
