/*
** count_way.c for way in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed Apr 13 13:02:53 2016 benjamin duhieu
** Last update Sat Apr 16 14:49:18 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "lemin.h"

int	nb_strokes(t_ant *ant, int a)
{
  int	i;
  t_ant	*elm;
  int	ret;

  ret = 0;
  while (ant_on_the_way(ant) && ++ret)
    {
      elm = ant;
      while (elm->next != NULL && (i = -1))
	{
	  while (++i < a && elm->next != NULL)
	    {
	      if (!elm->finish && !elm->way[i]->tube->next->room->ants)
		{
		  elm->way[i]->tube->room->ants = 0;
		  if (!elm->way[i]->tube->next->room->last)
		    elm->way[i]->tube->next->room->ants = 1;
		  else
		    elm->finish = 1;
		}
	      elm = elm->next;
	    }
	}
    }
  return (ret);
}

int	count_way(t_ant *ant, int nb_path)
{
  int	i;
  int	res;
  int	dir;
  int	ret;

  i = 0;
  dir = 0;
  while (++i <= nb_path)
    {
      if (i == 1)
	{
	  dir = nb_strokes(ant, i);
	  ret = i;
	}
      else
	{
	  res = nb_strokes(ant, i);
	  if (dir > res)
	    {
	      dir = res;
	      ret = i;
	    }
	}
    }
  return (ret);
}
