/*
** str4.c for minishell in ~/git/PSU/PSU_2015_minishell2/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Tue Apr  5 01:42:14 2016 THEIS Paul
** Last update Sun Apr 24 17:53:09 2016 marc brout
*/

#include "main.h"

int		my_char_pos(char *str, char c, bool ret)
{
  int		i;
  int		flag;

  if (!str)
    return (0);
  i = -1;
  flag = FALSE;
  while (str[++i] != '\0')
    {
      if (str[i] == '"')
	flag = !flag;
      if (str[i] == c && flag == FALSE)
	return (i);
    }
  return ((ret == TRUE) ? (i) : (0));
}

char		*my_strcut(char const *s, size_t a, size_t len)
{
  size_t	i;
  char		*str;

  if (!(s))
    return (NULL);
  str = xalloc(sizeof(char) * (len + 1));
  i = -1;
  while (++i < len && s[a + i] != 0x00)
    str[i] = s[a + i];
  str[i] = 0x00;
  return (str);
}

char		*my_strjoin(char *str1, char *str2)
{
  char		*str;

  if (!(str1 || str2))
    return (NULL);
  str = xalloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
  my_strcpy(str, str1);
  my_strcat(str, str2);
  return (str);
}

int		my_charcmp(char c, char *str)
{
  int		i;

  if (!(c))
    return (-1);
  i = -1;
  while (str[++i] != c && str[i]);
  if (str[i] == c)
    return (i);
  return (-1);
}

char		*my_strtrim(char *str, char grep)
{
  char		*tmp;

  tmp = strrchr(str, '\0') - 1;
  while (tmp >= str)
    {
      if (*tmp != grep)
	break;
      *tmp = '\0';
      --tmp;
    }
  return (str);
}
