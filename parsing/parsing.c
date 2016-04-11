/*
** parsing.c for lemin in ~/RENDU/CPE/CPE_2015_lemin/parsing
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Apr  1 15:54:44 2016 marc brout
** Last update Mon Apr 11 16:43:09 2016 benjamin duhieu
*/

#include <unistd.h>
#include "lemin.h"
#include "my.h"
#include "get_next_line.h"

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

int		count_words(char *str)
{
  int		i;
  int		total;

  total = 0;
  i = 0;
  while (str[i])
    {
      if ((!i && str[i] != ' ') ||
	  (i && str[i] != ' ' && str[i - 1] == ' '))
	++total;
      ++i;
    }
  return (total);
}

int		init_root(t_data *data)
{
  if (!(data->rooms = malloc(sizeof(t_room))))
    return (my_put_error(MALLOC_ERR), 1);
  data->rooms->next = data->rooms;
  data->rooms->prev = data->rooms;
  return (0);
}

void		free_tubes(t_tube *tubes)
{
  t_tube	*cur;
  t_tube	*tmp;

  cur = tubes;
  while (cur)
    {
      tmp = cur->next;
      free(cur);
      cur = tmp;
    }
}

void		free_graph(t_room *root)
{
  t_room	*cur;
  t_room	*tmp;

  cur = root->next;
  while (cur && cur != root)
    {
      tmp = cur->next;
      free(cur->name);
      free_tubes(cur->tubes);
      free(cur);
      cur = tmp;
    }
}

int		parse_input(t_data *data)
{
  if (init_root(data) || get_ants(data) || get_all(data) ||
      check_room_position(data->rooms) ||
      check_first_last(data->rooms))
    return (my_put_error(ROOM_TROUBLE), 1);
  if (solve_one_path(data->rooms))
    return (1);
  return (0);
}

int		main(int ac, char **av)
{
  t_ant		ant;
  t_data	data;
  t_room	*first;

  if (ac > 1)
    return (my_put_usage(av, 1));
  if (parse_input(&data))
    return (1);
  if ((first = find_first_room(data.rooms)))
    {
      if (start(first, &ant, data.ants))
	return (1);
      free_graph(data.rooms);
      free(data.rooms);
      return (0);
    }
  return (1);
}
