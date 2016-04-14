/*
** algo.c for algo in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr  8 15:14:52 2016 benjamin duhieu
** Last update Wed Apr 13 13:07:00 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "lemin.h"

void		fill_tab(t_larg *root, t_path ***way)
{
  int		i;
  t_larg	*elem;

  i = -1;
  elem = elem->next;
  while (way[0] && way[0][++i])
    {
      way[0][i] = elem->pile;
      elem = elem->next;
    }
}

int		start(t_room *room, t_ant *ant, int nb)
{
  t_path	**way;
  t_larg	*root;
  int		nb_path;

  /* nb_path = path_ant(room); */
  if (!(root = malloc(sizeof(t_larg))))
    return (my_put_error(MALLOC_ERR), 1);
  root->prev = root;
  root->next = root;
  if ((nb_path = path(room, root)) == -1)
    return (1);
  if (!(way = malloc(sizeof(t_path *) * (nb_path + 1))))
    return (my_put_error(MALLOC_ERR), -1);
  way[nb_path] = NULL;
  fill_tab(root, &way);
  if (!(ant = list_ant(way, nb)))
    return (1);
  start_ant(ant, nb_path);
  return (0);
}
