/*
** str3.c for minishell
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Mar 30 20:02:44 2016 THEIS Paul
** Last update Sun Apr 24 16:51:55 2016 benjamin duhieu
*/

#include "main.h"

/* Fonction identique a strcpy, sauf que seuls les n
**       premiers octets de src sont copiés.
*/

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

/*
** Fonction qui return le nombre de ligne ('\n') dans une string
*/

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

/*
** Revoie le Char de Str a la pos i
*/

char	sting_to_char(char *str, size_t i)
{
  return (str[i]);
}

/*
** Permet de décaler une string de i char.
*/

void	drop_char(char *str, int i)
{
  --i;
  while (str[++i])
    str[i] = str[i + 1];
}
