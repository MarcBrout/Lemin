/*
** get_graph.c for lemin in ~/RENDU/CPE/CPE_2015_Lemin/parsing
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Apr 11 14:03:02 2016 marc brout
** Last update Sat Apr 23 12:23:59 2016 marc brout
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
      if (!(tmp = my_realloc(tmp, j + 1)))
	return (my_put_error(MALLOC_ERR), NULL);
      tmp[j + 1] = 0;
      tmp[j] = str[*i];
      ++*i;
      ++j;
    }
  tmp[j] = 0;
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
    return (2);
  if (!(elem = malloc(sizeof(t_room))))
    return (my_put_error(MALLOC_ERR), 1);
  elem->name = ref->name;
  elem->next = root;
  elem->prev = root->prev;
  root->prev->next = elem;
  root->prev = elem;
  elem->tubes = NULL;
  elem->ants = 0;
  elem->pass = 0;
  elem->x = ref->x;
  elem->y = ref->y;
  elem->id = ref->id;
  elem->last = (*next == 1) ? 1 : 0;
  elem->first = (!*next) ? 1 : 0;
  *next = -1;
  my_printf("%s %d %d\n", elem->name, elem->x, elem->y);
  return (0);
}

int		get_this_line(t_data *data, char *next,
			      t_room *ref, char *line)
{
  int		ret;
  static char	room_passed = 0;

  if ((ret = count_words(line)) == 3 && !room_passed)
    {
      if ((ret = set_new_x_y(ref, line)))
	{
	  free(line);
	  return (ret);
	}
      return (get_one_room(data->rooms, ref, next));
    }
  else if (line && line[0] && ret == 1)
    {
      room_passed = 1;
      return (prepare_rooms(line, data->rooms));
    }
  else
    if (line[0])
      return (my_put_error(BAD_FORMAT), 2);
  return (0);
}

int		get_all(t_data *data)
{
  char		*line;
  char		next;
  int		ret;
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
      if (next >= 0 && !my_strncmp("##", line, 1))
	return (my_put_error(MISSING_LINE), 2);
      if (my_strncmp("##", line, 1) &&
	  (ret = get_this_line(data, &next, &tmp, line)))
	return (ret);
      free(line);
    }
  return ((tmp.id < 2) ? my_put_error(MISSING_ROOM), 2 : 0);
}
