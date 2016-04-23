/*
** link_room.c for lemin in /home/brout_m/RENDU/CPE/CPE_2015_Lemin
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Apr 23 12:25:17 2016 marc brout
** Last update Sat Apr 23 12:26:38 2016 marc brout
*/

#include "lemin.h"
#include "my.h"

int		link_rooms(t_room *root,
			   char *room1, char *room2)
{
  t_room	*tmp;
  t_room	*tmp2;

  if ((tmp = search_room(root, room1)) == root)
    return (my_put_room_str(room1, INVALID_ROOM), 2);
  if ((tmp2 = search_room(root, room2)) == root)
    return (my_put_room_str(room2, INVALID_ROOM), 2);
  if (already_linked(tmp, tmp2))
      return (0);
  if (add_tube(tmp, tmp2) || add_tube(tmp2, tmp))
    return (1);
  return (0);
}

int		prepare_rooms(char *str, t_room *root)
{
  int		i;
  char		*room1;
  char		*room2;

  i = 0;
  if (!(room1 = my_getfirst_name(str, &i, '-')))
    return (1);
  i++;
  if (!str[i])
    return (my_put_error(WRONG_TUBE), 2);
  if (!(room2 = my_getfirst_name(str, &i, '-')))
    return (1);
  if (!my_strcmp(room1, room2))
    return (my_printf("%s-%s\n", room1, room2), 0);
  if ((i = link_rooms(root, room1, room2)))
    return (i);
  my_printf("%s-%s\n", room1, room2);
  free(room1);
  free(room2);
  return (0);
}
