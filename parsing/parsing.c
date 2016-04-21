/*
** parsing.c for lemin in ~/RENDU/CPE/CPE_2015_lemin/parsing
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Apr  1 15:54:44 2016 marc brout
** Last update Thu Apr 21 17:16:20 2016 marc brout
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
    return (my_put_error(WRONG_ANTS), 2);
  else if (ret)
    return (1);
  if ((data->ants = my_getnbrcst(tmp)) <= 0)
    return (my_put_error(WRONG_ANTS), 2);
  my_printf("%d\n", data->ants);
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
  if (!(data->rooms = malloc(sizeof(t_room))) ||
      !(data->tabf = malloc(sizeof(void *) * 4)))
    return (my_put_error(MALLOC_ERR), 1);
  data->rooms->next = data->rooms;
  data->rooms->prev = data->rooms;
  data->tabf[0] = &get_ants;
  data->tabf[1] = &get_all;
  data->tabf[2] = &check_room_position;
  return (0);
}

int		parse_input(t_data *data)
{
  int		i;
  int		ret;

  if (init_root(data))
    return (1);
  i = 0;
  while (i < 3 && !(ret = data->tabf[i](data)))
    ++i;
  if (ret == 1)
    return (1);
  if (check_first_last(data))
    return (1);
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
      free(data.tabf);
      return (0);
    }
  return (1);
}
