/*
** tri.c for lemin in /home/brout_m/RENDU/CPE/CPE_2015_Lemin/algo
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Apr 12 15:38:47 2016 marc brout
** Last update Tue Apr 12 15:57:40 2016 marc brout
*/

t_tube		*copy_pile(t_tube *pile)
{
  t_tube	*cur;
  t_tube	*tmp;
  t_tube	*first;
  t_tube	*elem;

  if (!(cur = pile))
    return (NULL);
  tmp = NULL;
  while (cur)
    {
      if (!(elem = malloc(sizeof(t_tube))))
	return (my_put_error(MALLOC_ERR), NULL);
      elem->room = cur->room;
      elem->branch = cur->branch;
      elem->nb = cur->nb;
      elem->next = NULL;
      if (tmp)
	tmp->next = elem;
      if (cur == pile)
	first = elem;
      if (cur != pile)
	tmp = elem;
    }
  return (first);
}

void		*free_pile(t_tube *pile)
{
  t_tube	*cur;
  t_tube	*tmp;

  cur = pile;
  while (cur)
    {
      tmp = cur->next;
      free(cur);
      cur = tmp;
    }
}
