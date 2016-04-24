/*
** str3.c for minishell
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Mar 30 20:02:44 2016 THEIS Paul
** Last update Sun Apr 24 17:52:36 2016 marc brout
*/

#include "main.h"

char		*my_strncpy(char *dest, char *src, int n)
{
  int		i;

  i = -1;
  while (src[++i] != '\0' && i < n)
    dest[i] = src[i];
  if (n < i)
    dest[i] = '\0';
  return (dest);
}

int	count_line(char *str)
{
  int	i;
  int	x;

  i = -1;
  x = 0;
  while (str[++i])
    {
      if (str[i] == '\n')
	x++;
    }
  return (x);
}

char	sting_to_char(char *str, size_t i)
{
  return (str[i]);
}

void	drop_char(char *str, int i)
{
  --i;
  while (str[++i])
    str[i] = str[i + 1];
}
