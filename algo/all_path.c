/*
** all_path.c for all_path in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr  8 15:22:54 2016 benjamin duhieu
** Last update Wed Apr 20 22:10:19 2016 marc brout
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

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
  clean_paths(root);
  tri_piles_by_branch(root);
  tri_piles_by_length(root, 1);
  get_short_paths(root);
  tri_piles_by_length(root, 0);
  return (count_paths(root));
}
