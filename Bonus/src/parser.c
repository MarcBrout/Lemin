/*
** parser.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:19:44 2016 THEIS Paul
** Last update Sun Apr 24 15:42:09 2016 THEIS Paul
*/

#include "main.h"

void	parse(t_info *info)
{
  int	fd;
  char	*tmp;

  fd = 0;
  info->current = 0;
  info->nbr_room = 0;
  tmp = xalloc(sizeof(*tmp) * (BUFF_SIZE + 1));
  while ((tmp = get_next_line(fd)) != NULL)
    {
      tread_line(tmp, info);
      info->current++;
    }
  if (tmp)
    free(tmp);
}

void		tread_line(char *str, t_info *info)
{
  SDL_Rect	pos;
  SDL_Rect	flag;

  init_SDL_Rect(&pos);
  init_SDL_Rect(&flag);
  if (strcmp(str, "##start") == 0)
    info->opt = 1;
  else if (strcmp(str, "##end") == 0)
    info->opt = 2;
  else
    {
      while (str[pos.x])
	{
	  ((str[pos.x] == C_SPACE) ? (flag.x++) : ((str[pos.x] == C_MIN) ?
	    (pos.y++) : ((is_alpha) ? (flag.y++) : (0))));
      	  pos.x++;
	}
      parse_it(flag, pos, str, info);
      info->opt = 0;
    }
}

void	parse_it(SDL_Rect flag, SDL_Rect pos, char *str, t_info *info)
{
  ((flag.x == 2 && str[0] != C_FLAG) ? (parse_decl(str, info, info->opt, 0)) :
   ((flag.x == 0 && pos.y != 0 && str[0] != C_FLAG) ?
    (parse_thread(str, info, 0, 0)) : (parse_path(str, info))));
}

void		parse_path(char *str, t_info *info)
{
  int		i;
  unsigned int	nbr;
  static int	flag = 0;

  nbr = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	nbr++;
      else
	nbr = 0;
      i++;
    }
  if (nbr == strlen(str))
    (atoi(str) >= 1023) ? (my_put_err("Error : Too much ants...\n", TRUE)) :
      (info->nbr_ants = atoi(str));
  else if (flag == 0)
    {
      put_ants_room(info, info->nbr_ants);
      flag = 1;
    }
  ants_path(str, info);
}

void		parse_decl(char *str, t_info *info, int opt, int nb)
{
  char		id[BUFF_SIZE];
  SDL_Rect	*pos1;
  SDL_Rect	*pos2;

  pos1 = xalloc(sizeof(SDL_Rect));
  init_SDL_Rect(pos1);
  pos2 = xalloc(sizeof(SDL_Rect));
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
  (info->nbr_room >= BUFF_SIZE - 1) ?
	  (my_put_err("Error : Too Much Room\n", TRUE)) : (info->nbr_room++);
  save_room(id, pos1, info, opt);
}
