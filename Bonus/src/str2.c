/*
** str2.c for minishell in ~/git/PSU/PSU_2015_minishell2/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Mar 30 20:02:33 2016 THEIS Paul
** Last update Mon Apr 25 13:10:11 2016 marc brout
*/

#include "main.h"

char		*my_strset(size_t size, char c)
{
  size_t	i;
  char		*str;

  i = 0;
  str = xalloc(sizeof(char) * (++size));
  while (i <= size)
    str[i++] = c;
  return (str);
}

char	*finder(char **env, char *grep)
{
  int	i;
  char	*path_home;
  int	size_var;

  i = 0;
  path_home = NULL;
  if (env == NULL || env[0] == NULL)
    return (NULL);
  if ((size_var = my_strlen(grep)) == 0)
    return (NULL);
  while (env && env[i] && my_strncmp(grep, env[i], size_var) != 0)
    i = i + 1;
  if (env[i])
    path_home = my_strchr(env[i], ';') + 1;
  return (path_home);
}

int	my_putstr(char *str)
{
  return (write(1, str, my_strlen(str)));
}

char	*my_char_to_string(char c)
{
  char	*str;

  str = xalloc(sizeof(char) * 2);
  str[0] = c;
  str[1] = '\0';
  return (str);
}
