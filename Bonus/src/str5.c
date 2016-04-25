/*
** str5.c for minishell in ~/theis_p/git/PSU/PSU_2015_minishell2/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Tue Apr  5 20:21:55 2016 THEIS Paul
** Last update Sun Apr 24 17:54:10 2016 marc brout
*/

#include "main.h"

char	*epur_str(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == '\t')
      	str[i] = ' ';
      while (str[0] == '\n')
	drop_char(str, 0);
      while (str[i] == '\n' && str[i + 1] == '\n')
	drop_char(str, i);
      while (str[i] == '\t' && str[i + 1] == '\t')
	drop_char(str, i);
      while (str[i] == ' ' && str[i + 1] == ' ')
	drop_char(str, i);
      if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] == '\n')
	drop_char(str, i);
      while (str[i] == '\n' && (str[i + 1] == ' ' ||
				str[i + 1] == '\t'))
	drop_char(str, i + 1);
      if (str[i] == '\n' && str[i + 1] == '\n')
	drop_char(str, i);
    }
  return (str);
}

int		my_getnbr(char *str)
{
  int		i;
  int		n;
  int		x;

  x = 0;
  n = 1;
  i = my_strlen(str);
  while (--i >= 0)
    {
      x += (n * (str[i] - 48));
      n *= 10;
    }
  return (x);
}

char		*my_strchr(char *str, char c)
{
  int		i;

  i = -1;
  if (!(str || c))
    return (NULL);
  while (str[++i])
    if (str[i] == c)
      return (str + i);
  return (NULL);
}

bool		is_char_space(char c)
{
  if (c == ' ' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
    return (TRUE);
  return (FALSE);
}
