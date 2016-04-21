/*
** misc.c for lemin in /home/brout_m/RENDU/CPE/CPE_2015_lemin
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Apr  1 19:24:56 2016 marc brout
** Last update Thu Apr 21 18:12:55 2016 marc brout
*/

#include <unistd.h>
#include "lemin.h"
#include "get_next_line.h"
#include "my.h"

int		get_next_str(char **str)
{
  char		*tmp;
  char		*clean_tmp;
  char		go;

  go = 1;
  while (go && (tmp = get_next_line(0)))
    {
      go = 0;
      if (!(clean_tmp = epur_str(tmp)))
	return (my_put_error(MALLOC_ERR), 1);
      if (is_it_a_comment(clean_tmp))
	{
	  go = 1;
	  free(tmp);
	  free(clean_tmp);
	}
    }
  if (!tmp)
    return (2);
  free(tmp);
  *str = clean_tmp;
  return (0);
}

int		anymore_letters(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (1);
      ++i;
    }
  return (0);
}

char		*epur_str(char *str)
{
  char		*tmp;
  int		i;
  int		j;

  if (!(tmp = malloc(my_strlen(str) + 1)))
    return (NULL);
  my_bzero(tmp, my_strlen(str) + 1, 0);
  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	tmp[j] = str[i], ++j;
      else if (i && (str[i] == ' ' || str[i] == '\t') &&
	       str[i - 1] != ' ' && str[i - 1] != '\t' &&
	       anymore_letters(&str[i]))
	tmp[j] = ' ', ++j;
      ++i;
    }
  return (tmp);
}

int		is_it_a_comment(char *str)
{
  if (!my_strncmp(str, "##", 1))
    {
      my_printf("%s\n", str);
      return (0);
    }
  if (!my_strncmp(str, "#", 0))
    return (1);
  return (0);
}
