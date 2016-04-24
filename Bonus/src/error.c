/*
** error.c for corewar in /home/theis_p/CPE_2015_corewar/src
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Mon Feb 29 20:49:46 2016 Paul THEIS
** Last update Sun Apr 24 17:39:32 2016 marc brout
*/

#include "main.h"

bool	my_put_err(char *str, const bool isClose)
{
  write(2, str, my_strlen(str));
  if (isClose)
    exit(EXIT_FAILURE);
  return (TRUE);
}

void	*xalloc(const size_t size)
{
  void	*p;

  p = malloc(size);
  if (p  == NULL)
    my_put_err("malloc error\n", TRUE);
  return (p);
}

void	*xealloc(void *d, const size_t size)
{
  void	*p;

  p = realloc(d, size);
  if (p  == NULL)
    my_put_err("realloc error\n", TRUE);
  return (p);
}

void	*xcalloc(size_t n, const size_t size)
{
  void	*p;

  p = calloc(n, size);
  if (p  == NULL)
    my_put_err("calloc error\n", TRUE);
  return (p);
}
