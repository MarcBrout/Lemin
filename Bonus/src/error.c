/*
** error.c for corewar in /home/theis_p/CPE_2015_corewar/src
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Mon Feb 29 20:49:46 2016 Paul THEIS
** Last update Sun Apr 24 16:38:05 2016 benjamin duhieu
*/

#include "main.h"

/*
** Ecrit str dans la sortie d'erreur,
** Si isClose est TRUE alors quite le programme
** Return: TRUE
*/

bool	my_put_err(char *str, const bool isClose)
{
  write(2, str, my_strlen(str));
  if (isClose)
    exit(EXIT_FAILURE);
  return (TRUE);
}

/*
** Fait un malloc tout en le verifiant
** Return: p, pointeur void
*/

void	*xalloc(const size_t size)
{
  void	*p;

  p = malloc(size);
  if (p  == NULL)
    my_put_err("malloc error\n", TRUE);
  return (p);
}

/*
** Fait un realloc tout en le verifiant
** Return: p, pointeur void
*/

void	*xealloc(void *d, const size_t size)
{
  void	*p;

  p = realloc(d, size);
  if (p  == NULL)
   my_put_err("realloc error\n", TRUE);
  return (p);
}

/*
** Fait un calloc tout en le verifiant
** Return: p, pointeur void
*/

void	*xcalloc(size_t n, const size_t size)
{
  void	*p;

  p = calloc(n, size);
  if (p  == NULL)
   my_put_err("calloc error\n", TRUE);
  return (p);
}
