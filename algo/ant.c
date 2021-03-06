/*
** ant.c for ant in /home/duhieu_b/CPE/CPE_2015_lemin/algo
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Apr  2 13:24:27 2016 benjamin duhieu
** Last update Wed Apr 20 22:18:32 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int		path_ant(t_room	*room)
{
  t_room	*elem;
  int		i;

  elem = room;
  i = 1;
  while (elem->tubes->next != NULL)
    {
      i++;
      elem->tubes = elem->tubes->next;
    }
  return (i);
}

int	ant_on_the_way(t_ant *ant)
{
  t_ant	*elem;

  elem = ant;
  while (elem->next != NULL)
    {
      if (!elem->finish)
	return (1);
      elem = elem->next;
    }
  return (0);
}

void	start_ant(t_ant *ant, int nb_path)
{
  t_ant	*elem;
  int	a;
  int	i;

  elem = ant;
  while (ant_on_the_way(ant))
    {
      elem = ant;
      a = -1;
      while (elem->next != NULL)
	{
	  i = -1;
	  while (++i < nb_path && elem->next != NULL)
	    {
	      aff_ant(elem, i, &a);
	      elem = elem->next;
	    }
	}
      my_printf("\n");
    }
}

t_ant	*list_ant(t_path **way, int nb)
{
  t_ant	*first;
  t_ant	*elem;
  int	i;

  if (!(first = malloc(sizeof(t_ant))))
    return (NULL);
  first->next = NULL;
  elem = first;
  i = -1;
  while (++i < nb)
    {
      elem->num = i + 1;
      elem->way = way;
      elem->act = NULL;
      elem->rank = 0;
      elem->finish = 0;
      elem->next = NULL;
      if (!(elem->next = malloc(sizeof(t_ant))))
	return (NULL);
      elem = elem->next;
    }
  elem->next = NULL;
  return (first);
}
