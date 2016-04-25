/*
** refresh.c for bonus in ~/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:21:24 2016 THEIS Paul
** Last update Mon Apr 25 15:29:04 2016 marc brout
*/

#include "main.h"

int		put_ant_screen(int x, int y, t_info *info)
{
  SDL_Rect	pos;
  SDL_Surface	*ant;
  SDL_Surface	*tmp;

  pos = set_pos(x - 50 + (76 / 2), y - 50);
  if (!(tmp = IMG_Load("img/ant.png")))
    return (my_put_error("ant.png not found\n"), 1);
  if (!(ant = rotozoomSurface(tmp, 0, 0.5, 1)) ||
      0 > SDL_BlitSurface(ant, NULL, info->screen, &pos) ||
      0 > SDL_Flip(info->screen))
    return (1);
  free(tmp);
  free(ant);
  return (0);
}

void	find_max(t_info *info)
{
  int	i;

  i = -1;
  info->spacer.x = 1;
  info->spacer.y = 1;
  while (++i < BUFF_SIZE)
    {
      if (info->elem[i].id != NULL)
	{
	  if (info->elem[i].pos.x > info->spacer.x)
	    info->spacer.x = info->elem[i].pos.x;
	  if (info->elem[i].pos.y > info->spacer.y)
  	    info->spacer.y = info->elem[i].pos.y;
	}
    }
  info->spacer.x = (W_W - 100) / info->spacer.x;
  info->spacer.y = (W_H - TOOLBAR_H - 100) / info->spacer.y;
}

int	anim_ant(int id_room_start, int id_room_end, t_info *info)
{
  int	i;
  int	c_x;
  int	c_y;

  find_max(info);
  c_x = (info->elem[id_room_end].pos.x -
	 info->elem[id_room_start].pos.x) *
    info->spacer.x / info->speed;
  c_y = (info->elem[id_room_end].pos.y -
	 info->elem[id_room_start].pos.y) *
    info->spacer.y / info->speed;
  i = -1;
  while (++i <= info->speed)
    {
      update_screen(info);
      if (put_ant_screen(info->elem[id_room_start].pos.x *
			 info->spacer.x + (i * c_x) + 50,
			 info->elem[id_room_start].pos.y *
			 info->spacer.y +
			 (i * c_y) + 50, info))
	return (1);
      usleep(info->speed);
    }
  return ((SDL_Flip(info->screen) < 0) ? 1 : 0);
}

int	del_ant_in_room(char *id_del, t_info *info, char *room)
{
  int	id;
  int	id_room;
  int	id_room_target;

  if (0 > (id = verif_id_ant(info, id_del)) ||
      0 > (id_room_target = verif_id(info, room)) ||
      0 > (id_room = verif_id(info, info->ants[id].room)))
    return (1);
  info->elem[id_room].nbr_ants -= 1;
  return (anim_ant(id_room, id_room_target, info));
}

int	add_ant_in_room(char *id_add, char *room, t_info *info)
{
  int	id;
  int	id_room;

  if (0 > (id_room = verif_id(info, room)) ||
      0 > (id = verif_id_ant(info, id_add)) ||
      !(info->ants[id].room = my_strdup(room)))
    return (1);
  info->elem[id_room].nbr_ants += 1;
  if (update_screen(info))
    return (1);
  return ((SDL_Flip(info->screen) < 0) ? 1 : 0);
}
