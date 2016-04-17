/*
** all_path.c for all_path in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr  8 15:22:54 2016 benjamin duhieu
** Last update Sat Apr 16 18:55:26 2016 benjamin duhieu
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
  first->pile->next = NULL;
  /* first->pile->prev = first->pile; */
  first->pile->room = prem;
  my_printf("a\n");
  if (browse_graph(root))
    return (my_put_error(MALLOC_ERR), -1);
  my_printf("b\n");
  tri_piles_by_branch(root);
  my_printf("c\n");
  tri_piles_by_length(root, 0);
  my_printf("d\n");
  get_short_paths(root);
  my_printf("e\n");
  tri_piles_by_length(root, 1);
  my_printf("f\n");
  /* if ((nb_path = shorts_path(&way, nb_path)) == -1) */
  /*   return (my_put_error(MALLOC_ERR), -1); */
  /* my_printf("|||lolpppp : %p ||||-\n", way[0]); */
  /* return (nb_path); */
  return (count_paths(root));
}
