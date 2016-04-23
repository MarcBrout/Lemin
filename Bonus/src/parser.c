/*
** parser.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:19:44 2016 THEIS Paul
** Last update Thu Apr 21 19:27:42 2016 THEIS Paul
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
  free(tmp);
}

void		tread_line(char *str, t_info *info)
{
  SDL_Rect	pos;
  SDL_Rect	flag;

  iniSDL_Rect(&pos);
  iniSDL_Rect(&flag);
  if (strcmp(str, "##start") == 0)
    info->opt = 1;
  else if (strcmp(str, "##end") == 0)
    info->opt = 2;
  else
    {
      while (str[pos.x])
	{
	  if (str[pos.x] == ' ')
	    flag.x++;
	  else if (str[pos.x] == '-')
	    pos.y++;
	  else if ((str[pos.x] >= 'a' && str[pos.x] <= 'z') ||
		   (str[pos.x] >= 'A' && str[pos.x] <= 'Z'))
	    flag.y++;
	  pos.x++;
	}
      decision(flag, pos, str, info);
      info->opt = 0;
    }
}

void	decision(SDL_Rect flag, SDL_Rect pos, char *str, t_info *info)
{
  if (flag.x == 2 && str[0] != 'P')
    {
      parse_decl(str, info, info->opt, 0);
    }
  else if (flag.x == 0 && pos.y != 0 && str[0] != 'P')
    {
      parse_thread(str, info, 0, 0);
    }
  else
    {
      parse_path(str, info);
    }
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
    check_nbr_ants(str, info);
  else if (flag == 0)
    {
      put_ants_room(info, info->nbr_ants);
      flag = 1;
    }
  ants_path(str, info);
}

void	parse_thread(char *str, t_info *info, int i, int j)
{
  char	id2[BUFF_SIZE];
  char	id1[BUFF_SIZE];
  int	flag;
  int	k;

  k = 0;
  flag = 0;
  while (str[i])
    {
      if (str[i] == '-')
	flag++;
      else if (flag == 0)
	id1[j++] = str[i];
      else
	id2[k++] = str[i];
      i++;
    }
  id1[j] = 0;
  id2[k] = 0;
  draw_tunel(id1, id2, info);
}
