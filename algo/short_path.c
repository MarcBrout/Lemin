/*
** short_path.c for short_path in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr  8 15:16:30 2016 benjamin duhieu
** Last update Fri Apr  8 20:06:55 2016 marc brout
*/

#include "lemin.h"
#include "my.h"

int		same_way(t_path *actu, t_path **way, int i)
{
  t_tube	*elem;
  t_tube	*elem2;
  int		a;

  a = -1;
  while (++a < i && way[a])
    {
      if (actu->branch == way[a]->branch)
	return (1);
      elem2 = actu->tube;
      while (!elem2->next)
	{
	  elem = way[a]->tube;
	  while (!elem->next)
	    {
	      if (elem2->room->id == elem->room->id)
		return (1);
	      elem = elem->next;
	    }
	  elem2 = elem2->next;
	}
    }
  return (0);
}

int		first(int j, int *tmp, int place, t_path *way)
{
  if (j == 0)
    {
      *tmp = way->i;
      place = j;
    }
  else
    {
      if (*tmp > way->i)
	{
	  *tmp = way->i;
	  place = j;
	}
    }
  return (place);
}

int		swap(int place, int *i, t_path **way)
{
  t_tube	*tempo;

  if (place != -1)
    {
      tempo = way[*i]->tube;
      way[*i]->tube = way[place]->tube;
      way[place]->tube = tempo;
      return (0);
    }
  *i -= 1;
  return (-1);
}

int		shorts_path(t_path ***way, int nb_path)
{
  t_tree	t;

  t.i = -1;
  t.bool = 0;
  t.place = -1;
  t.path = nb_path;
  while (++t.i < nb_path)
    {
      t.j = -1 + t.i;
      while (way[0] && way[0][++t.j])
	if (t.i == 0)
	  t.place = first(t.j, &t.tmp, t.place, way[0][t.j]);
	else if (!t.bool)
	  {
	    if (!(same_way(way[0][t.j], way[0], t.i)))
	      t.tmp = way[0][t.j]->i, t.place = t.j, t.bool = 1;
	  }
	else if (t.bool)
	  if (!(same_way(way[0][t.j], way[0], t.i)) && t.tmp > way[0][t.j]->i)
	    t.tmp = way[0][t.j]->i, t.place = t.j;
      t.path += swap(t.place, &t.i, way[0]);
    }
  my_printf("0000lolpppp : %p\n", *way);
  if (!(way[0] = my_realloc_path(way[0], t.path + 1)))
    return (-1);
  my_printf("11111lolpppp : %p\n", *way);
  return (t.path);
}
