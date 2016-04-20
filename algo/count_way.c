/*
** count_way.c for way in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed Apr 13 13:02:53 2016 benjamin duhieu
** Last update Tue Apr 19 18:56:31 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int	nb_strokes(t_ant *ant, int a)
{
  int	i;
  t_ant	*elm;
  int	ret;

  ret = 0;
  while (ant_on_the_way(ant) && ++ret)
    {
      elm = ant;
      my_printf("BEGIN\n");
      while (elm->next != NULL && (i = -1))
	{
	  while (++i < a && elm->next != NULL)
	    {
	      my_printf("NUM : %d && finish ? %d && ROOM : %s\n", elm->num, elm->finish, elm->way[i]->tube->room->name);
	      if (!elm->act && !elm->finish && !elm->way[i]->tube->next->ants)
		{
		  if (elm->way[i]->tube->next->room->last)
		    elm->finish = 1;
		  else
		    {
		      elm->act = elm->way[i]->tube->next;
		      elm->way[i]->tube->next->ants = 1;
		    }
		}
	      else if (!elm->finish && !elm->way[i]->tube->next->ants)
		{
		  elm->way[i]->tube->ants = 0;
		  if (!elm->way[i]->tube->next->room->last)
		    {
		      elm->act = elm->way[i]->tube->next;
		      elm->way[i]->tube->next->ants = 1;
		    }
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
	  my_printf("CAA\n");
	  dir = nb_strokes(ant, i);
	  my_printf("CAB\n");
	  ret = i;
	}
      else
	{
	  my_printf("CAC\n");
	  res = nb_strokes(ant, i);
	  my_printf("CAD\n");
	  if (dir > res)
	    {
	      dir = res;
	      ret = i;
	    }
	}
    }
  return (ret);
}
