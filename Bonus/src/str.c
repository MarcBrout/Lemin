/*
** str.c for minishell in /home/theis_p/git/PSU/PSU_2015_minishell2/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Mar 30 19:57:04 2016 THEIS Paul
** Last update Sun Apr 24 17:51:54 2016 marc brout
*/

#include "main.h"

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  if (!(str))
    return (i);
  while (str[++i] != '\0');
  return (i);
}

char	*my_strdup(char *str)
{
  char	*rsl;

  if (str != NULL)
    {
      if ((rsl = malloc(sizeof(char) * (my_strlen(str) + 1))) != NULL)
	return (my_strcpy(rsl, str));
    }
  return (NULL);
}

char	*my_strcat(char *dest, char *src)
{
  while (*dest++);
  dest--;
  while ((*dest++ = *src++));
  return (dest);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = -1;
  while (src[++i])
    dest[i] = src[i];
  dest[i] = '\0';
  return (dest);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int   x;
  int   y;
  int   z;

  x = 0;
  y = 0;
  z = 1;
  if (n == 0)
    return (0);
  while (s1[x] && s2[y] && s1[x] == s2[y] && z < n)
    {
      x++;
      y++;
      z++;
    }
  return (s1[x] - s2[y]);
}
