/*
** str5.c for minishell in /home/theis_p/git/PSU/PSU_2015_minishell2/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Tue Apr  5 20:21:55 2016 THEIS Paul
** Last update Wed Apr 20 11:37:32 2016 THEIS Paul
*/

#include "main.h"

/*
** Fonction qui retire les multiple espaces et remplace les tab par des espaces.
*/

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
      if ((str[i] == ' ' || str[i] == '\t' ) && str[i + 1] == '\n')
	drop_char(str, i);
      while (str[i] == '\n' && (str[i + 1] == ' ' || str[i + 1] == '\t'))
	drop_char(str, i + 1);
      if (str[i] == '\n' && str[i + 1] == '\n')
	drop_char(str, i);
    }
  return (str);
}

/*
** Fonction qui converti une string en int.
*/

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

/*
** Fonction qui revoit le reste d'une string apres le caractere SEPARATOR
*/

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

  /*
  ** Renvoie TRUE si c est un caractere d'espacement.
  */

  bool		is_char_space(char c)
    {
      if (c == ' ' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
	return (TRUE);
      return (FALSE);
    }
