/*
** chk_path.c for chk_path in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr  8 15:23:36 2016 benjamin duhieu
** Last update Fri Apr  8 15:24:59 2016 benjamin duhieu
*/

#include "lemin.h"

t_path		**my_realloc_path(t_path **way, int nb)
{
  t_path	**cpy;
  int		i;

  i = -1;
  if (nb == 0)
    return (NULL);
  if (!(cpy = malloc(sizeof(t_path *) * nb)))
    return (NULL);
  while (++i < (nb - 1) && way && way[i])
    cpy[i] = way[i];
  while (i < nb)
    cpy[i++] = NULL;
  i = -1;
  while (way && way[++i])
    free(way[i]);
  free(way);
  return (cpy);
}

int		chk_id(t_tube *new_elem, t_tube *tube)
{
  t_tube	*elem;

  elem = tube;
  while (elem->next)
    {
      if (elem->id == new_elem->room->id)
	return (1);
      elem = elem->next;
    }
  return (0);
}

int		chk_path(t_tube *tube, t_tube *new_elem,
			 t_path **tmp , t_room *room)
{
  if (new_elem->room->last)
    {
      tmp[tmp->way]->tube = tube;
      tmp[tmp->way]->i = new_elem->nb;
      tmp[tmp->way]->branch = tube->branch;
      tmp->way++;
      if (!(tmp = my_realloc_path(tmp, tmp->way + 2)))
	return (-1);
      if (!(tmp[tmp->way] = malloc(sizeof(t_path))))
	return (-1);
      tmp[tmp->way + 1] = NULL;
      free(new_elem);
      return (1);
    }
  if (!tmp_tube->next)
    {
      free(new_elem);
      return (1);
    }
  return (0);
}

int		other_chk(t_tube *tmp_tube, t_tube *tube,
			  t_tube *new_elem)
{
  if (chk_id(tmp_tube, tube))
    {
      free(new_elem);
      return (1);
    }
  return (0);
}

int		new_path(t_tube *tube, t_tube *new_elem, t_path **tmp,
			 t_room *data)
{
  t_tube	*elem;
  t_tube	*tmp_tube;

  tmp_tube = room->tubes;
  if (other_chk(tmp_tube, tube, new_elem))
    return (1);
  while (tmp_tube)
    {
      if (tmp_tube->room)
	{
	  if (!(elem = malloc(sizeof(t_tube))))
	    return (-1);
	  new_elem->next = elem;
	  elem->room = tmp_tube->room;
	  elem->nb = new_elem->nb + 1;
	  elem->id = tmp_tube->room->id;
	  elem->next = NULL;
	  if ((all_ways(tube, elem, tmp, room)) == -1)
	    return (-1);
	}
      tmp_tube = tmp_tube->next;
      if (tmp_tube->room->first == 1)
	tube->branch++;
    }
  return (0);
}
