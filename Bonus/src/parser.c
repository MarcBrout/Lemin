/*
** parser.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:19:44 2016 THEIS Paul
** Last update Mon Apr 25 17:10:39 2016 marc brout
*/

#include "main.h"

int	parse(t_info *info)
{
  int	fd;
  char	*tmp;

  fd = 0;
  info->current = 0;
  info->nbr_room = 0;
  if (!(tmp = xalloc(sizeof(*tmp) * (BUFF_SIZE + 1))))
    return (1);
  while ((tmp = get_next_line(fd)) != NULL)
    {
      if (tread_line(tmp, info))
	return (1);
      info->current++;
    }
  if (tmp)
    free(tmp);
  return (0);
}

int		tread_line(char *str, t_info *info)
{
  SDL_Rect	pos;
  SDL_Rect	flag;

  init_SDL_Rect(&pos);
  init_SDL_Rect(&flag);
  if (my_strcmp(str, "##start") == 0)
    info->opt = 1;
  else if (my_strcmp(str, "##end") == 0)
    info->opt = 2;
  else
    {
      while (str[pos.x])
	{
	  ((str[pos.x] == C_SPACE) ? (flag.x++) :
	   ((str[pos.x] == C_MIN) ?
	    (pos.y++) : ((is_alpha(str[pos.x])) ? (flag.y++) : (0))));
      	  pos.x++;
	}
      if (parse_it(flag, pos, str, info))
	return (1);
      info->opt = 0;
    }
  return (0);
}

int	parse_it(SDL_Rect flag, SDL_Rect pos, char *str, t_info *info)
{
  if (flag.x == 2 && str[0] != C_FLAG)
    return (parse_decl(str, info, info->opt, 0));
  else if (flag.x == 0 && pos.y != 0 && str[0] != C_FLAG)
    return (parse_thread(str, info));
  return (parse_path(str, info));
}

int		parse_path(char *str, t_info *info)
{
  int		i;
  unsigned int	nbr;
  static int	n = 0;

  nbr = 0;
  i = -1;
  while (str[++i])
    if (is_num(str[i]))
      nbr++;
    else
      nbr = 0;
  if (nbr == my_strlen(str))
    {
      if (my_getnbr(str) >= (BUFF_SIZE/4) - 1)
	return (my_put_error("Too much ants.\n"), 1);
      else
	info->nbr_ants = my_getnbr(str);
    }
  else if (n == 0)
    {
      if (put_ants_room(info, info->nbr_ants))
	return (1);
      n = 1;
    }
  return (ants_path(str, info));
}

int		parse_decl(char *str, t_info *info, int opt, int nb)
{
  char		id[BUFF_SIZE];
  SDL_Rect	*pos1;
  SDL_Rect	*pos2;

  if (!(pos1 = xalloc(sizeof(SDL_Rect))) ||
      !(pos2 = xalloc(sizeof(SDL_Rect))))
    return (1);
  init_SDL_Rect(pos1);
  init_SDL_Rect(pos2);
  while (str[pos2->x])
    {
      if (str[pos2->x] == C_SPACE)
    	++nb;
      else if (is_num(str[pos2->x]))
    	((nb == 1) ? (pos1->x = pos1->x * 10 + (str[pos2->x] - '0')) :
	 ((nb == 2) ? (pos1->y = pos1->y * 10 + (str[pos2->x] - '0')) :
	  (id[pos2->y++] = str[pos2->x])));
      else
	id[pos2->y++] = str[pos2->x];
      pos2->x++;
    }
  id[pos2->y] = 0;
  if (info->nbr_room >= BUFF_SIZE - 1)
    return (my_put_error("Error : Too Much Room\n"), 1);
  return (info->nbr_room++, save_room(id, pos1, info, opt));
}
