/*
** all_path.c for all_path in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr  8 15:22:54 2016 benjamin duhieu
** Last update Wed Apr 20 21:24:32 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

/* void		verif_elem(t_larg *elem, t_tube *new_elem) */
/* { */
/*   t_tube *tmp; */

/*   tmp = elem->pile; */
/*   my_printf("||||||-count pile : %d", elem->count); */
/*   my_printf("&& valid pile: %d\n", elem->valid); */
/*   my_printf("id room act : %s||||||\n\n", new_elem->room->name); */
/*   while (tmp) */
/*     { */
/*       my_printf("|%s|\n", tmp->room->name); */
/*       tmp = tmp->next; */
/*     } */
/*   my_printf(" _ \n"); */
/* } */

void		chk_list(t_larg *root)
{
  t_larg	*elem;

  elem = root->next;
  while (elem != root)
    {
      verif_elem(elem, elem->pile);
      elem = elem->next;
    }
}

int		path(t_room *prem, t_larg *root)
{
  t_larg	*first;

  if (!(first = malloc(sizeof(t_larg))))
    return (my_put_error(MALLOC_ERR), -1);
  first->next = root->next;
  first->prev = root;
  root->next->prev = first;
  root->next = first;
  first->count = 1;
  first->valid = 0;
  if (!(first->pile = malloc(sizeof(t_tube))))
    return (my_put_error(MALLOC_ERR), -1);
  first->pile->next = NULL;
  first->pile->room = prem;
  if (browse_graph(root))
    return (my_put_error(MALLOC_ERR), -1);
  //   my_printf("aaaaaaaa\n");
  tri_piles_by_branch(root);
  my_printf("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n");
  chk_list(root);
  tri_piles_by_length(root, 1);
  my_printf("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC\n");
  chk_list(root);
  get_short_paths(root);
  //  my_printf("ddddddd\n");
  tri_piles_by_length(root, 0);
  /* my_printf("eeeeeee\n"); */
  chk_list(root);
  return (count_paths(root));
}
