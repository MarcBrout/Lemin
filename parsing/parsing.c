/*
** parsing.c for lemin in ~/RENDU/CPE/CPE_2015_lemin/parsing
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Apr  1 15:54:44 2016 marc brout
** Last update Mon Apr  4 12:10:31 2016 marc brout
*/

#include <unistd.h>
#include "lemin.h"
#include "my.h"
#include "get_next_line.h"

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
  if (!str[i])
    return (my_put_room_str(ref->name, WRONG_ROOM), 2);
  if ((ref->x = my_getnbr_i(str, &i)) < 0)
    return (my_put_room_str(ref->name, WRONG_ROOM), 2);
  i++;
  if (!str[i])
    return (my_put_room_str(ref->name, WRONG_ROOM), 2);
  if ((ref->y = my_getnbr_i(str, &i)) < 0)
    return (my_put_room_str(ref->name, WRONG_ROOM), 2);
  return (0);
}

int		check_existing_room(t_room *root, char *name)
{
  t_room	*tmp;

  tmp = root->next;
  while (tmp != root)
    {
      if (!my_strcmp(tmp->name, name))
	return (my_put_room_str(name, EXISTING_ROOM), 1);
      tmp = tmp->next;
    }
  return (0);
}

int		get_one_room(t_room *root, t_room *ref)
{
  t_room	*elem;

  if (check_existing_room(root, ref->name))
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
  elem->last = ref->last;
  return (0);
}

int		get_end_room(t_data *data, int id)
{
  int		ret;
  char		*line;
  t_room	tmp;

  tmp.id = id + 1;
  tmp.last = 1;
  if ((ret = get_next_str(&line)) && (ret == 2))
    return (my_put_error(MISSING_END_ROOM), 1);
  else if (ret)
    return (1);
  if ((ret = set_new_x_y(&tmp, line)) == 2)
    return (my_put_error(MISSING_END_ROOM), 1);
  else if (ret)
    return (1);
  if (get_one_room(data->rooms, &tmp))
    return (1);
  free(line);
  return (0);
}

int		get_all_rooms(t_data *data)
{
  int		ret;
  int		ret2;
  char		*line;
  t_room	tmp;

  tmp.id = 0;
  tmp.last = 0;
  while (!(ret = get_next_str(&line)))
    {
      if (!my_strcmp(line, "##end") && tmp.id <= 1)
	return (my_put_error(MISSING_ROOM), 1);
      else if (!my_strcmp(line, "##end") && tmp.id > 1)
	return (get_end_room(data, tmp.id));
      ++tmp.id;
      if ((ret2 = set_new_x_y(&tmp, line)) == 2)
	continue ;
      else if (ret2)
	return (1);
      if (get_one_room(data->rooms, &tmp))
	return (1);
      free(line);
    }
  return (my_put_error(MISSING_END), 1);
}

int		get_first()
{
  char		*tmp;
  int		ret;

  if ((ret = get_next_str(&tmp)) && (ret == 2))
    return (my_put_error(MISSING_START), 1);
  else if (ret)
    return (1);
  if (my_strcmp(tmp, "##start"))
    return (my_put_error(MISSING_START), 1);
  return (0);
}

int		get_ants(t_data *data)
{
  char		*tmp;
  int		ret;

  if ((ret = get_next_str(&tmp)) && (ret == 2))
    return (my_put_error(WRONG_ANTS), 1);
  else if (ret)
    return (1);
  if ((data->ants = my_getnbrcst(tmp)) <= 0)
    return (my_put_error(WRONG_ANTS), 1);
  free(tmp);
  return (0);
}

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

int		link_rooms(t_room *root,
			   char *room1, char *room2)
{
  t_room	*tmp;
  t_room	*tmp2;

  if ((tmp = search_room(root, room1)) == root)
    return (my_put_room_str(room1, INVALID_ROOM), 0);
  if ((tmp2 = search_room(root, room2)) == root)
    return (my_put_room_str(room2, INVALID_ROOM), 0);
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
  if (!str || !str[0])
    return (0);
  if (!(room1 = my_getfirst_name(str, &i, '-')))
    return (1);
  i++;
  if (!str[i])
    return (my_put_error(WRONG_TUBE), 0);
  if (!(room2 = my_getfirst_name(str, &i, '-')))
    return (1);
  if (link_rooms(root, room1, room2))
    return (1);
  return (0);
}

int		link_all_rooms(t_room *root)
{
  char		*line;
  int		ret;
  int		nb_tubes;

  nb_tubes = 0;
  while (!(ret = get_next_str(&line)))
    {
      nb_tubes++;
      if (prepare_rooms(line, root))
	return (1);
    }
  if (!nb_tubes && ret == 2)
    return (my_put_error(MISSING_TUBES), 1);
  if (ret == 1)
    return (1);
  return (0);
}

int		search_one_path(t_room *root, t_room *prev)
{
  t_tube	*gotow;

  if (prev == root->prev)
    return (0);
  gotow = prev->tubes;
  while (gotow)
    {
      if (!gotow->room || gotow->room == root->next)
	return (1);
      if (search_one_path(root, gotow->room))
	gotow = gotow->next;
      else
	return (0);
    }
  return (1);
}

int		parse_input(t_data *data)
{
  if (get_ants(data) || get_first() || set_root(data) ||
      get_all_rooms(data) || link_all_rooms(data->rooms))
    return (my_put_error(ROOM_TROUBLE), 1);
  if (search_one_path(data->rooms, data->rooms->next))
    return (my_put_error(NO_PATH), 1);
  return (0);
}

int		main(int ac, char **av)
{
  t_data	data;

  if (ac > 1)
    my_put_usage(av, 1);
  if (parse_input(&data))
    return (1);
  return (0);
}
