/*
** algo.c for algo in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr  8 15:14:52 2016 benjamin duhieu
** Last update Sun Apr 24 14:39:20 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

t_path		**fill_tab(t_larg *root, t_path **way, int nb_path)
{
  int		i;
  t_larg	*elem;

  i = -1;
  while (++i < nb_path)
    if (!(way[i] = malloc(sizeof(t_path))))
      return (my_put_error(MALLOC_ERR), NULL);
  i = -1;
  elem = root->next;
  while (way && way[++i])
    {
      way[i]->tube = elem->pile;
      elem = elem->next;
    }
  return (way);
}

int		start(t_room *room, t_ant *ant, int nb)
{
  t_path	**way;
  t_larg	*root;
  int		nb_path;

  if (!(root = malloc(sizeof(t_larg))))
    return (my_put_error(MALLOC_ERR), 1);
  root->prev = root;
  root->next = root;
  if ((nb_path = path(room, root)) == -1)
    return (1);
  if (!(way = malloc(sizeof(t_path *) * (nb_path + 1))))
    return (my_put_error(MALLOC_ERR), -1);
  way[nb_path] = NULL;
  if (!(way = fill_tab(root, way, nb_path)))
    return (1);
  if (!(ant = list_ant(way, nb)))
    return (1);
  start_ant(ant, nb_path);
  free_path(root);
  free_ant(ant, way);
  return (0);
}
