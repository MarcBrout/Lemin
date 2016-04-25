/*
** error.c for corewar in /home/theis_p/CPE_2015_corewar/src
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Mon Feb 29 20:49:46 2016 Paul THEIS
** Last update Mon Apr 25 13:20:12 2016 marc brout
*/

#include "main.h"

void	my_put_error(char *str)
{
  write(2, str, my_strlen(str));
}

void	*xalloc(const size_t size)
{
  void	*p;

  p = malloc(size);
  if (p == NULL)
    my_put_error("malloc error\n");
  return (p);
}
