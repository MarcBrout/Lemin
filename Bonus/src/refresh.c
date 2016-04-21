/*
** refresh.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:21:24 2016 THEIS Paul
** Last update Thu Apr 21 19:58:08 2016 THEIS Paul
*/

#include "main.h"

void		update_screen(t_info *info)
{
  SDL_Rect	pos;

  pos.x = 0 + SPACE_1;
  pos.y = 0 + SPACE_1;
  SDL_FillRect(info->screen, NULL, convert_color(0, 0, 0));
  SDL_BlitSurface(info->space, NULL, info->screen, &pos);
  init_toolbar(info);
  aff_round(info);
  aff_info_all(info);
}

void		put_ant_screen(int x, int y, t_info *info)
{
  SDL_Rect	pos;
  SDL_Surface	*ant;
  SDL_Surface	*tmp;

  pos = set_pos(x + (76 / 2), y);
  tmp = IMG_Load("img/ant.png");
  ant = rotozoomSurface(tmp, 0, 0.5, 1);
  SDL_BlitSurface(ant, NULL, info->screen, &pos);
  SDL_Flip(info->screen);
  free(tmp);
  free(ant);
}

void	anim_ant(int id_room_start, int id_room_end, t_info *info)
{
  int	x;
  int	y;
  int	i;
  int	c_x;
  int	c_y;

  c_x = (info->elem[id_room_end].x - info->elem[id_room_start].x) / 10;
  c_y = (info->elem[id_room_end].y - info->elem[id_room_start].y) / 10;
  x = 0;
  y = 0;
  while (i  <= 10)
    {
      update_screen(info);
      put_ant_screen(info->elem[id_room_start].x + (i * c_x),
		     info->elem[id_room_start].y + (i * c_y), info);
      usleep(info->speed);
      i++;
  }
  SDL_Flip(info->screen);
}

void	del_ant_in_room(char *id_del, t_info *info, char *room)
{
  int	id;
  int	id_room;
  int	id_room_target;

  id = sort_id_ant(info, id_del);
  id_room_target = sort_id(info, room);
  id_room = sort_id(info, info->ants[id].room);
  info->elem[id_room].nbr_ants -= 1;
  anim_ant(id_room, id_room_target, info);
}

void	add_ant_in_room(char *id_add, char *room, t_info *info)
{
  int	id;
  int	id_room;

  id_room = sort_id(info, room);
  id = sort_id_ant(info, id_add);
  sprintf(info->ants[id].room, "%s", room);
  info->elem[id_room].nbr_ants += 1;
  update_screen(info);
  SDL_Flip(info->screen);
}
