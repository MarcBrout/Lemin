/*
** checks.c for lemin in ~/RENDU/CPE/CPE_2015_Lemin/parsing
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Apr 11 13:51:30 2016 marc brout
** Last update Thu Apr 14 16:47:16 2016 marc brout
*/

#include "lemin.h"
#include "my.h"

int		check_first_last(t_data *data)
{
  t_room	*tmp;
  int		total_first;
  int		total_last;

  tmp = data->rooms->next;
  total_first = 0;
  total_last = 0;
  while (tmp != data->rooms)
    {
      total_first += (tmp->first) ? 1 : 0;
      total_last += (tmp->last) ? 1 : 0;
      if (tmp->last && tmp->first)
	return (my_put_error(SAME_START_END), 1);
      tmp = tmp->next;
    }
  if (total_first < 1)
    return (my_put_error(MISSING_START), 1);
  if (total_last < 1)
    return (my_put_error(MISSING_END), 1);
  if (total_first > 1)
    return (my_put_error(TOO_MUCH_START), 1);
  if (total_last > 1)
    return (my_put_error(TOO_MUCH_END), 1);
  return (0);
}

int		check_room_position(t_data *data)
{
  t_room	*tmp;
  t_room	*tmp2;

  tmp = data->rooms->next;
  while (tmp != data->rooms && tmp->next != data->rooms)
    {
      tmp2 = tmp->next;
      while (tmp2 != data->rooms)
	{
	  if (tmp->x == tmp2->x && tmp->y == tmp2->y)
	    return (my_put_error(SAME_ROOM), 1);
	  tmp2 = tmp2->next;
	}
      tmp = tmp->next;
    }
  return (0);
}

int		check_existing_room(t_room *root, t_room *test,
				    char *name)
{
  t_room	*tmp;

  tmp = root->next;
  while (tmp != root)
    {
      if (!my_strcmp(tmp->name, name) ||
	  (test->x == tmp->x && test->y == tmp->y))
	return (my_put_room_str(name, EXISTING_ROOM), 1);
      tmp = tmp->next;
    }
  test->id++;
  return (0);
}
