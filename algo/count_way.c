/*
** count_way.c for way in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed Apr 13 13:02:53 2016 benjamin duhieu
** Last update Wed Apr 13 13:09:44 2016 benjamin duhieu
*/

#include "lemin.h"

int	nb_strokes(t_ant *ant, int a)
{
  int	i;
  int	ret;

  ret = 0;
  while (ant_on_the_way(ant) && ++ret)
    {
      elem = ant;
      while (elem->next != NULL)
	{
	  i = -1;
	  while (++i < a && elem->next != NULL)
	    {
	      if (!elem->finish && !elem->way[i]->room->next->ants)
		{
		  elem->way[i]->room->ants = 0;
		  if (!elem->way->room->next->last)
		    elem->way->room->next->ants = 1;
		  else
		    elem->finish = 1;
		}
	      elem = elem->next;
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
