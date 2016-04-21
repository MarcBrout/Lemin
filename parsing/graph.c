/*
** graph.c for lemin in ~/RENDU/CPE/CPE_2015_Lemin/parsing
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Apr 11 13:56:58 2016 marc brout
** Last update Thu Apr 21 17:09:49 2016 marc brout
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int		set_root(t_data *data)
{
  if (!(data->rooms = malloc(sizeof(t_room))))
    return (my_put_error(MALLOC_ERR), 1);
  data->rooms->next = data->rooms;
  data->rooms->prev = data->rooms;
  return (0);
}

int		add_tube(t_room *base, t_room *target)
{
  t_tube	*elem;
  t_tube	*tmp;

  if (!(elem = malloc(sizeof(t_tube))))
    return (my_put_error(MALLOC_ERR), 1);
  tmp = base->tubes;
  while (tmp && tmp->next)
    tmp = tmp->next;
  if (!tmp)
    base->tubes = elem;
  else
    tmp->next = elem;
  elem->room = target;
  elem->next = NULL;
  return (0);
}

t_room		*search_room(t_room *root, char *room)
{
  t_room	*tmp;

  tmp = root->next;
  while (tmp != root)
    {
      if (!my_strcmp(tmp->name, room))
	return (tmp);
      tmp = tmp->next;
    }
  return (tmp);
}

int		already_linked(t_room *room1, t_room *room2)
{
  t_tube	*cur;

  cur = room2->tubes;
  while (cur)
    {
      if (room1->id == cur->room->id)
	return (1);
      cur = cur->next;
    }
  return (0);
}

int		link_rooms(t_room *root,
			   char *room1, char *room2)
{
  t_room	*tmp;
  t_room	*tmp2;

  if ((tmp = search_room(root, room1)) == root)
    return (my_put_room_str(room1, INVALID_ROOM), 0);
  if ((tmp2 = search_room(root, room2)) == root)
    return (my_put_room_str(room2, INVALID_ROOM), 0);
  if (already_linked(tmp, tmp2))
      return (0);
  if (add_tube(tmp, tmp2) || add_tube(tmp2, tmp))
    return (1);
  return (0);
}

int		prepare_rooms(char *str, t_room *root)
{
  int		i;
  char		*room1;
  char		*room2;

  i = 0;
  if (!(room1 = my_getfirst_name(str, &i, '-')))
    return (1);
  i++;
  if (!str[i])
    return (my_put_error(WRONG_TUBE), 2);
  if (!(room2 = my_getfirst_name(str, &i, '-')))
    return (1);
  if (!my_strcmp(room1, room2))
    return (my_printf("%s-%s\n", room1, room2), 0);
  if (link_rooms(root, room1, room2))
    return (1);
  my_printf("%s-%s\n", room1, room2);
  free(room1);
  free(room2);
  return (0);
}
