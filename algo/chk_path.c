/*
** chk_path.c for chk_path in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr  8 15:23:36 2016 benjamin duhieu
** Last update Mon Apr 11 16:24:48 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

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
  /* while (way && way[++i]) */
  /*   free(way[i]); */
  /* free(way); */
  return (cpy);
}

int		chk_id(t_tube *new_elem, t_tube *tube)
{
  t_tube	*elem;

  elem = tube;
  while (elem->next)
    {
      if (elem->id == my_getnbr(new_elem->room->name))
	return (1);
      elem = elem->next;
    }
  return (0);
}

int		chk_path(t_tube *tube, t_tube *new_elem,
			 t_path **tmp)
{
  if (new_elem->room->last)
    {
      tmp[tmp[0]->way]->tube = tube;
      my_printf("((((((%p)))))))))\n", tmp[tmp[0]->way]->tube);
      tmp[tmp[0]->way]->i = new_elem->nb;
      tmp[tmp[0]->way]->branch = tube->branch;
      tmp[0]->way++;
      if (!(tmp = my_realloc_path(tmp, tmp[0]->way + 2)))
	return (-1);
      if (!(tmp[tmp[0]->way] = malloc(sizeof(t_path))))
	return (-1);
      tmp[tmp[0]->way + 1] = NULL;
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
  if (!tmp_tube->room->tubes)
    {
      free(new_elem);
      return (1);
    }
  return (0);
}

int		new_path(t_tube *tube, t_tube *new_elem, t_path **tmp,
			 t_room *room)
{
  t_tube	*elem;
  t_tube	*tmp_tube;

  tmp_tube = room->tubes;
  if (other_chk(tmp_tube, tube, new_elem))
    return (1);
  while (tmp_tube)
    {
      if (tmp_tube->room->first == 1)
	tube->branch++;
      /* my_printf("--------branch : %d------------\n",tube->branch++); */
      if (tmp_tube->room)
	{
	  if (!(elem = malloc(sizeof(t_tube))))
	    return (-1);
	  new_elem->next = elem;
	  elem->room = tmp_tube->room;
	  elem->nb = new_elem->nb + 1;
	  elem->id = my_getnbr(tmp_tube->room->name);
	  elem->next = NULL;
	  my_printf("elem->id=  %d\n", elem->id);
	  /* my_printf("elem->id=  %d\n", elem->id); */
	  if ((all_ways(tube, elem, tmp, room)) == -1)
	    return (-1);
	}
      /* my_printf("--------last : %d------------", new_elem->room->last); */
      tmp_tube = tmp_tube->next;
    }
  my_printf("kok\n");
  return (0);
}
