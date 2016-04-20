/*
** aff_ant.c for aff_ant in /home/duhieu_b/CPE/CPE_2015_Lemin
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed Apr 20 22:05:33 2016 benjamin duhieu
** Last update Wed Apr 20 22:17:26 2016 benjamin duhieu
*/

#include "lemin.h"
#include "my.h"

void	first_ant(t_ant *elem, UNUSED int i, int *first)
{
  *first += 1;
  elem->rank++;
  if (elem->way[i]->tube->next->room->last)
    {
      elem->finish = 1;
      elem->act = elem->way[i]->tube->next;
    }
  else
    {
      elem->act = elem->way[i]->tube->next;
      elem->act->ants = 1;
    }
  if (*first != 0)
    my_printf(" ");
  my_printf("P%d-%s", elem->num, elem->act->room->name);
}

void	other_ants(t_ant *elem, UNUSED int i, int *first)
{
  *first += 1;
  elem->act->ants = 0;
  if (elem->act->next->room->last)
    {
      elem->act = elem->act->next;
      elem->finish = 1;
    }
  else
    {
      elem->act = elem->act->next;
      elem->act->ants = 1;
    }
  if (*first != 0)
    my_printf(" ");
  my_printf("P%d-%s", elem->num, elem->act->room->name);
}

void	aff_ant(t_ant *elem, int i, int *first)
{
  if (!elem->rank && !elem->way[i]->tube->next->ants)
    first_ant(elem, i, first);
  else if (elem->rank && !elem->finish && !elem->act->next->ants)
    other_ants(elem, i, first);
}
