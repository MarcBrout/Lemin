/*
** solve_one_path.c for lemin in ~/RENDU/CPE/CPE_2015_Lemin
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun Apr 10 19:16:00 2016 marc brout
** Last update Mon Apr 11 17:16:08 2016 marc brout
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

t_tube		*remove_from_the_pile(t_tube *root)
{
  t_tube	*tmp;

  tmp = root->next;
  if (tmp)
    root->next = tmp->next;
  return (tmp);
}

int		add_one_to_the_pile(t_tube *root,
				    t_tube *tube)
{
  t_tube	*cur;
  t_tube	*elem;

  cur = root;
  while (cur->next)
    cur = cur->next;
  if (!(elem = malloc(sizeof(t_tube))))
    return (my_put_error(MALLOC_ERR), 1);
  elem->next = NULL;
  elem->room = tube->room;
  cur->next = elem;
  return (0);
}

int		add_all_to_the_pile(t_tube *root,
				    t_tube *tubes)
{
  t_tube	*cur;

  cur = tubes;
  while (cur)
    {
      if (add_one_to_the_pile(root, cur))
	return (1);
      cur = cur->next;
    }
  return (0);
}

t_room		*find_first_room(t_room *root)
{
  t_room	*first;

  first = root->next;
  while (first != root)
    {
      if (first->first)
	return (first);
      first = first->next;
    }
  return (NULL);
}

int		solve_one_path(t_room *root)
{
  t_tube	root_tube;
  t_tube	*tmp;
  t_room	*first;

  first = find_first_room(root);
  root_tube.next = NULL;
  if (add_all_to_the_pile(&root_tube, first->tubes))
    return (1);
  while (root_tube.next)
    {
      tmp = remove_from_the_pile(&root_tube);
      if (add_all_to_the_pile(&root_tube, tmp->room->tubes))
	return (1);
      if (tmp->room->last)
	return (free(tmp), free_pile(&root_tube), 0);
      free(tmp);
    }
  return (my_put_error(NO_PATH), 1);
}
