/*
** all_path.c for all_path in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr  8 15:22:54 2016 benjamin duhieu
** Last update Mon Apr 11 16:25:58 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int		all_ways(t_tube *tube, t_tube *new_elem,
			 t_path **tmp , t_room *room)
{
  int		chk;

  if ((chk = chk_path(tube, new_elem, tmp)) == 1)
    return (0);
  else if (chk == -1)
    return (-1);
  if ((chk = new_path(tube, new_elem, tmp, room)) == 1)
    {
      my_printf("ok\n");
      return (0);
    }
  else if (chk == -1)
    return (-1);
  my_printf("ko\n");
  free(new_elem);
  return (0);
}


int		path(t_room *room, t_path **way, int nb_path)
{
  t_tube	*elem;
  t_tube	*new_elem;
  t_room	*tmp_room;

  if (!(way[0] = malloc(sizeof(t_path))))
    return (my_put_error(MALLOC_ERR), -1);
  way[1] = NULL;
  if (!(elem = malloc(sizeof(t_tube))))
    return (my_put_error(MALLOC_ERR), -1);
  elem->room = room->next;
  elem->branch = 0;
  new_elem = elem;
  new_elem->nb = 1;
  new_elem->id = my_getnbr(room->next->name);
  my_printf("elem->id=  %d\n", new_elem->id);
  new_elem->next = NULL;
  tmp_room = room->next;
  way[0]->i = 0;
  way[0]->way = 0;
  if ((all_ways(elem, new_elem, way, tmp_room)) == -1)
    return (my_put_error(MALLOC_ERR), -1);
  /* my_printf("---lolpppp : %p ---\n", way[0]); */
  /* my_printf("((((((%p)))))))))\n", way[0]->tube); */
  /* if (!way[0]->tube) */
  /*   return (-1); */
  if ((nb_path = shorts_path(&way, nb_path)) == -1)
    return (my_put_error(MALLOC_ERR), -1);
  /* my_printf("|||lolpppp : %p ||||-\n", way[0]); */
  return (nb_path);
}
