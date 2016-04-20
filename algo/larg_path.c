/*
** larg_path.c for larg in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue Apr 12 14:47:52 2016 benjamin duhieu
** Last update Wed Apr 20 13:41:04 2016 benjamin duhieu
*/

#include <stdlib.h>
#include <stdbool.h>
#include "lemin.h"
#include "my.h"

void		remove_pile(t_larg *new_elem)
{
  free_pil(new_elem->pile);
  new_elem->prev->next = new_elem->next;
  new_elem->next->prev = new_elem->prev;
  free(new_elem);
}

int		chk_id(char *name, t_larg *elem)
{
  t_tube	*new_elem;

  new_elem = elem->pile;
  while (new_elem)
    {
      // my_printf("name : %s && elem->room->name : %s\n", name, new_elem->room->name);
      if (!my_strcmp(name, new_elem->room->name))
	return (1);
      new_elem = new_elem->next;
    }
  //my_printf("--------------\n");
  return (0);
}

void		verif_elem(t_larg *elem, t_tube *new_elem)
{
  t_tube *tmp;

  tmp = elem->pile;
  my_printf("||||||-count pile : %d", elem->count);
  my_printf("&& valid pile: %d\n", elem->valid);
  my_printf("id room act : %s||||||\n\n", new_elem->room->name);
  while (tmp)
    {
      my_printf("|%s|\n", tmp->room->name);
      tmp = tmp->next;
    }
  my_printf(" _ \n");
}

int		copy_new_pile(t_tube *tub, t_larg *act, t_larg *root)
{
  // my_printf("COPY\n");
  if (add_path(act, root))
    return (1);
  // my_printf("\nLAST ? %d AND ID ? %s\n", tub->room->last, tub->room->name);
  if (tub->room->last)
    {
      // my_printf("VALID\n");
      root->next->valid = 1;
    }
  //verif_elem(root->next, root->next->pile);
  if (add_elem_to_pile(tub->room, root->next->pile))
    return (1);
  //  my_printf("FINISH COPY\n");
  // my_printf("CCCCCCCCCCCCCCC\n");
  return (0);
}

int		browse_graph(t_larg *root)
{
  t_larg	*new_elem;
  t_larg	*tmp;
  bool		pass;

  pass = true;
  //my_printf("root : %p\n", root);
  while (pass)
    {
      pass = false;
      new_elem = root->next;
      //      my_printf("elem : %p\n", new_elem);
      while (new_elem != root)
	{
	  //  my_printf("valid ? %d\n", new_elem->valid);
	  //  my_printf("\nPATH LOOP: %p\n\n", new_elem->pile);
	  //	  verif_elem(new_elem, new_elem->pile);
	  if (!new_elem->valid)
	    {
	      if (add_pil(new_elem, root))
		return (1);
	      pass = true;
	      tmp = new_elem;
	      new_elem = new_elem->next;
	      remove_pile(tmp);
	    }
	  else
	    new_elem = new_elem->next;
	  //	  my_printf("elem : %p\n", new_elem);
	}
      //       my_printf("------------------\n");
    }
  return (0);
}
