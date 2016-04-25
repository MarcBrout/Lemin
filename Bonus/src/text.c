/*
** text.c for text in /home/duhieu_b/CPE/CPE_2015_Lemin/Bonus
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Apr 25 13:48:01 2016 benjamin duhieu
** Last update Mon Apr 25 15:43:08 2016 benjamin duhieu
*/

#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

char	*my_strcat(char *tmp, char *tmp2)
{
  int	i;
  int	b;
  int	a;
  bool	num;
  char	*fin;

  i = my_strlen(tmp) + my_strlen(tmp2);
  if (!(fin = malloc(i + 1)))
    return (NULL);
  fin[i] = 0;
  a = -1;
  b = -1;
  num = false;
  while (++a < i)
    {
      if (!num)
	{
	  fin[a] = tmp[++b];
	  if (b >= my_strlen(tmp) && (num = true))
	    b = -1;
	}
      else
	fin[a] = tmp[++b];
    }
  return (fin);
}

char	*concat_str_int(char *tmp, char *tmp2, char *str, int nb)
{
  if (!(tmp2 = my_strdup(str)))
    return (NULL);
  if (!(tmp = my_strcat(tmp, tmp2)))
    return (NULL);
  if (!(tmp2 = my_putnbr_char(nb)))
    return (NULL);
  if (!(tmp = my_strcat(tmp, tmp2)))
    return (NULL);
  return (tmp);
}

char	*text_round(t_info *info)
{
  char	*tmp;
  char	*tmp2;

  if (!(tmp = my_strdup("Round : ")))
    return (NULL);
  if (!(tmp2 = my_putnbr_char(info->round)))
    return (NULL);
  if (!(tmp = my_strcat(tmp, tmp2)))
    return (NULL);
  if (!(tmp = concat_str_int(tmp, tmp2, "   |    Room: ", info->nbr_room)))
    return (NULL);
  if (!(tmp = concat_str_int(tmp, tmp2, "   |    Ants: ", info->nbr_ants)))
    return (NULL);
  if (!(tmp = concat_str_int(tmp, tmp2, "{Ant Man}              Start: ",
			     get_room(info, TRUE))))
    return (NULL);
  if (!(tmp = concat_str_int(tmp, tmp2, "   |    End: ",
			     get_room(info, FALSE))))
    return (NULL);
  if (!(tmp = concat_str_int(tmp, tmp2, "   |    Between: ",
			     info->nbr_ants - (get_room(info, TRUE) +
					       get_room(info, FALSE)))))
    return (NULL);
  return (tmp);
}
