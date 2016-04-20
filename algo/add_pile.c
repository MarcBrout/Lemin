/*
** add_pile.c for add_pile in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Apr 16 14:31:05 2016 benjamin duhieu
** Last update Tue Apr 19 21:09:50 2016 benjamin duhieu
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
  //my_printf("FIRST OF PILE : %s\n", act->pile->room->name);
  if (!(new->pile = copy_pile(act->pile)))
    return (1);
  /* my_printf("EEEEEEEEEEEE\n"); */
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
  elem->room = room;
  return (0);
}

t_tube		*last_elem_pile(t_larg *elem)
{
  t_tube	*tmp;

  tmp = elem->pile;
  while (tmp->next)
    tmp = tmp->next;
  //my_printf("\nCHECK ROOM : %s\n\n", tmp->room->name);
  return (tmp->room->tubes);
}

int		add_pil(t_larg *elem, t_larg *root)
{
  t_tube	*new_elem;
  int		i = 0;

  new_elem = last_elem_pile(elem);
  while (new_elem)
    {
      //  my_printf("NEXT ROOM : %s\n\n", new_elem->room->name);
      if (chk_id(new_elem->room->name, elem))
	{
	  //	  my_printf("LOOP\n");
	  new_elem = new_elem->next;
	  continue ;
	}
      if (copy_new_pile(new_elem, elem, root))
	return (1);
      //  my_printf("|||||\n");
      new_elem = new_elem->next;
      i++;
    }
  // my_printf("AAAAAAAAAAA\n");
  return (0);
}
