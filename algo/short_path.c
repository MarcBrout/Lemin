/*
** short_path.c for short_path in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr  8 15:16:30 2016 benjamin duhieu
** Last update Fri Apr  8 15:20:41 2016 benjamin duhieu
*/

#include "lemin.h"

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

int		shorts_path(t_path **way, int nb_path)
{
  t_tree	tree;

  tree.i = -1;
  tree.bool = 0;
  tree.place = -1;
  tree.path = nb_path;
  while (++tree.i < nb_path)
    {
      tree.j = -1 + tree.i;
      while (way && way[++tree.j])
	if (tree.i == 0)
	  tree.place = first(tree.j, &tree.tmp, tree.place, way[j]);
	else if (!tree.bool)
	  {
	    if (!(same_way(way[j], way, tree.i)))
	      tree.tmp = way[j]->i, tree.place = tree.j, tree.bool = 1;
	  }
	else if (tree.bool)
	  if (!(same_way(way[j], way, tree.i)) && tree.tmp > way[j]->i)
	    tree.tmp = way[j]->i, tree.place = tree.j;
      tree.path += swap(tree.place, &tree.i, way);
    }
  if (!(way = my_realloc_path(way, tree.path + 1)))
    return (-1);
  return (tree.path);
}
