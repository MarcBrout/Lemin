/*
** algo.c for algo in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr  8 15:14:52 2016 benjamin duhieu
** Last update Fri Apr  8 15:15:30 2016 benjamin duhieu
*/

#include "lemin.h"

int		start(t_room *room, t_ant *ant, int nb)
{
  t_path	**way;
  int		nb_path;

  nb_path = path_ant(room);
  if (!(way = malloc(sizeof(t_path *) * 2)))
    return (1);
  way[1] = NULL;
  if ((nb_path = path(room, way, nb_path)) == -1)
    return (1);
  if (!(ant = list_ant(way, nb)))
    return (1);
  start_ant(way, ant, nb_path);
  return (0);
}
