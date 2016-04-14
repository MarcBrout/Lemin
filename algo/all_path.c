/*
** all_path.c for all_path in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr  8 15:22:54 2016 benjamin duhieu
** Last update Thu Apr 14 13:17:42 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

/* int		all_ways(t_tube *tube, t_tube *new_elem, */
/* 			 t_path ***tmp, t_tube *prev) */
/* { */
/*   int		chk; */

/*   if ((chk = new_path(tube, new_elem, tmp, prev)) == 1) */
/*     return (0); */
/*   else if (chk == -1) */
/*     return (-1); */
/*   /\* free(new_elem); *\/ */
/*   return (0); */
/* } */


int		path(t_room *prem, t_larg *root)
{
  t_larg	*first;

  if (!(first = malloc(sizeof(t_larg))))
    return (my_put_error(MALLOC_ERR), -1);
  first->next = root->prev;
  first->prev = root;
  root->prev->next = first;
  root->prev = first;
  first->count = 1;
  first->valid = 0;
  if (!(first->pile = malloc(sizeof(t_tube))))
    return (my_put_error(MALLOC_ERR), -1);
  first->pile->next = first->pile;
  first->pile->prev = first->pile;
  first->pile->room = prem;
  if (browse_graph(root))
    return (my_put_error(MALLOC_ERR), -1);
  /* if ((nb_path = shorts_path(&way, nb_path)) == -1) */
  /*   return (my_put_error(MALLOC_ERR), -1); */
  /* my_printf("|||lolpppp : %p ||||-\n", way[0]); */
  /* return (nb_path); */
  return (2);
}
