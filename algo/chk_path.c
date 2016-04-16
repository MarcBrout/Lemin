/*
** chk_path.c for chk_path in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr  8 15:23:36 2016 benjamin duhieu
** Last update Sat Apr 16 16:04:07 2016 benjamin duhieu
*/

/* #include <stdlib.h> */
/* #include "lemin.h" */
/* #include "my.h" */

/* t_path		**my_realloc_path(t_path **way, int nb) */
/* { */
/*   t_path	**cpy; */
/*   int		i; */

/*   i = -1; */
/*   if (nb == 0) */
/*     return (NULL); */
/*   if (!(cpy = malloc(sizeof(t_path *) * nb))) */
/*     return (NULL); */
/*   while (++i < (nb - 1) && way && way[i]) */
/*     cpy[i] = way[i]; */
/*   while (i < nb) */
/*     cpy[i++] = NULL; */
/*   i = -1; */
/*   /\* while (way && way[++i]) *\/ */
/*   /\*   free(way[i]); *\/ */
/*   /\* free(way); *\/ */
/*   return (cpy); */
/* } */

/* int		chk_id(t_tube *new_elem, t_tube *tube) */
/* { */
/*   t_tube	*elem; */

/*   elem = tube; */
/*   while (elem->next) */
/*     { */
/*       my_printf("id : %d && my_id : %d\n", elem->id, my_getnbr(new_elem->room->name)); */
/*       if (elem->id == my_getnbr(new_elem->room->name)) */
/* 	return (1); */
/*       elem = elem->next; */
/*     } */
/*   return (0); */
/* } */

/* int		chk_path(t_tube *tube, t_tube *new_elem, */
/* 			 t_path ***tmp) */
/* { */
/*   if (new_elem->room->last) */
/*     { */
/*       my_printf("NEW_PATH\n"); */
/*       /\* my_printf("((((((%d \n %p)))))))))\n", tmp[0]->way, tmp[tmp[0]->way]); *\/ */
/*       tmp[0][tmp[0][0]->way]->tube = tube; */
/*       tmp[0][tmp[0][0]->way]->i = new_elem->nb; */
/*       tmp[0][tmp[0][0]->way]->branch = tube->branch; */
/*       tmp[0][0]->way++; */
/*       if (!(tmp[0] = my_realloc_path(tmp[0], tmp[0][0]->way + 2))) */
/* 	return (-1); */
/*       if (!(tmp[0][tmp[0][0]->way] = malloc(sizeof(t_path)))) */
/*       	return (-1); */
/*       tmp[0][tmp[0][0]->way + 1] = NULL; */
/*       /\* free(new_elem); *\/ */
/*       return (1); */
/*     } */
/*   return (0); */
/* } */

/* int		other_chk(t_tube *tmp_tube, t_tube *tube, */
/* 			  UNUSED t_tube *new_elem) */
/* { */
/*   if (chk_id(tmp_tube, tube)) */
/*     { */
/*       my_printf("LOOP\n"); */
/*       /\* free(new_elem); *\/ */
/*       return (1); */
/*     } */
/*   if (!tmp_tube->room->tubes) */
/*     { */
/*       my_printf("IMPASSE\n"); */
/*       /\* free(new_elem); *\/ */

/*       return (1); */
/*     } */
/*   return (0); */
/* } */

/* int		new_path(t_tube *tube, t_tube *new_elem, t_path ***tmp, t_tube *prev) */
/* { */
/*   t_tube	*elem; */
/*   t_tube	*tmp_tube; */
/*   int		chk; */

/*   my_printf("\nID: %d\n", new_elem->id); */
/*   tmp_tube = new_elem->room->tubes; */
/*   /\* my_printf("---tmp_tube->room->id =  %d && prev->id : %d---\n", my_getnbr(tmp_tube->room->name), prev->id); *\/ */
/*   /\* if (my_getnbr(tmp_tube->room->name) == prev->id) *\/ */
/*   /\*   return (1); *\/ */
/*   /\* my_printf("ID: %d\n", new_elem->id); *\/ */
/*   /\* my_printf("ID: %d\n", new_elem->id); *\/ */
/*   while (tmp_tube) */
/*     { */
/*       my_printf("\nID: %d\n", new_elem->id); */
/*       my_printf("---tmp_tube->room->id =  %d && prev->id : %d---\n", my_getnbr(tmp_tube->room->name), prev->id); */
/*       if (tmp_tube->room && */
/* 	  my_getnbr(tmp_tube->room->name) != prev->id) */
/* 	{ */
/* 	  if (other_chk(tmp_tube, tube, new_elem)) */
/* 	    return (1); */
/* 	  if ((chk = chk_path(tube, new_elem, tmp)) == 1) */
/* 	    return (1); */
/* 	  else if (chk == -1) */
/* 	    return (-1); */
/* 	  if (tmp_tube->room->first == 1) */
/* 	    tube->branch++; */
/* 	  /\* my_printf("--------branch : %d------------\n",tube->branch++); *\/ */
/* 	  /\* my_printf("ok\n"); *\/ */
/* 	  if (!(elem = malloc(sizeof(t_tube)))) */
/* 	    return (-1); */
/* 	  new_elem->next = elem; */
/* 	  elem->room = tmp_tube->room; */
/* 	  elem->nb = new_elem->nb + 1; */
/* 	  /\* my_printf("room->name=  %s\n", tmp_tube->room->name); *\/ */
/* 	  elem->id = my_getnbr(tmp_tube->room->name); */
/* 	  elem->next = NULL; */
/* 	  /\* my_printf("elem->id=  %d\n\n\n", elem->id); *\/ */
/* 	  /\* my_printf("elem->id=  %d\n", elem->id); *\/ */
/* 	  if ((all_ways(tube, elem, tmp, new_elem)) == -1) */
/* 	    return (-1); */
/* 	} */
/*       my_printf("NEXT\n"); */
/*       /\* my_printf("--------last : %d------------", new_elem->room->last); *\/ */
/*       tmp_tube = tmp_tube->next; */
/*     } */
/*   return (0); */
/* } */
