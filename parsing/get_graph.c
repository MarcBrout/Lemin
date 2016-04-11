/*
** get_graph.c for lemin in ~/RENDU/CPE/CPE_2015_Lemin/parsing
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Apr 11 14:03:02 2016 marc brout
** Last update Mon Apr 11 14:17:07 2016 marc brout
*/

#include "get_next_line.h"
#include "lemin.h"
#include "my.h"

char		*my_getfirst_name(char *str, int *i, char c)
{
  char		*tmp;
  int		j;

  if (!(tmp = malloc(1)))
    return (my_put_error(MALLOC_ERR), NULL);
  tmp[0] = 0;
  j = 0;
  while (str[*i] && str[*i] != c && str[*i] != ' ')
    {
      if (!(tmp = my_realloc(tmp, *i + 1)))
	return (my_put_error(MALLOC_ERR), NULL);
      tmp[*i + 1] = 0;
      tmp[j] = str[*i];
      ++*i;
      ++j;
    }
  tmp[*i] = 0;
  return (tmp);
}

int		set_new_x_y(t_room *ref, char *str)
{
  int		i;

  i = 0;
  if (!str || !str[0])
    return (0);
  if (!(ref->name = my_getfirst_name(str, &i, ' ')))
    return (1);
  i++;
  if ((ref->x = my_getnbr_i(str, &i)) < 0)
    return (my_put_room_str(ref->name, WRONG_ROOM), 2);
  i++;
  if ((ref->y = my_getnbr_i(str, &i)) < 0)
    return (my_put_room_str(ref->name, WRONG_ROOM), 2);
  return (0);
}

int		get_one_room(t_room *root, t_room *ref, char *next)
{
  t_room	*elem;

  if (check_existing_room(root, ref, ref->name))
    return (0);
  if (!(elem = malloc(sizeof(t_room))))
    return (my_put_error(MALLOC_ERR), 1);
  elem->name = ref->name;
  elem->next = root;
  elem->prev = root->prev;
  root->prev->next = elem;
  root->prev = elem;
  elem->tubes = NULL;
  elem->ants = 0;
  elem->x = ref->x;
  elem->y = ref->y;
  elem->id = ref->id;
  elem->last = (*next == 1) ? 1 : 0;
  elem->first = (!*next) ? 1 : 0;
  *next = -1;
  return (0);
}

int		get_this_line(t_data *data, char *next,
			      t_room *ref, char *line)
{
  int		ret;

  if ((ret = count_words(line)) == 3)
    {
      if ((ret = set_new_x_y(ref, line)) == 2)
	{
	  free(line);
	  return (0);
	}
      else if (ret)
	return (1);
      if (get_one_room(data->rooms, ref, next))
	return (1);
    }
  else if (ret == 1 && prepare_rooms(line, data->rooms))
    return (1);
  else if (ret != 1 && ret != 3)
    my_put_error(BAD_FORMAT);
  return (0);
}

int		get_all(t_data *data)
{
  char		*line;
  char		next;
  t_room	tmp;

  tmp.id = 0;
  tmp.first = 0;
  tmp.last = 0;
  next = -1;
  while (!get_next_str(&line))
    {
      if (next < 0 && (next = (!my_strcmp(line, "##end")) ? 1 :
	   (!my_strcmp(line, "##start")) ? 0 : -1) >= 0)
	{
	  free(line);
	  continue;
	}
      if (get_this_line(data, &next, &tmp, line))
	return (1);
      free(line);
    }
  if (tmp.id < 2)
    return (my_put_error(MISSING_ROOM), 1);
  return (0);
}
