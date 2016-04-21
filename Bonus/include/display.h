/*
** display.h for corewar in /home/theis_p/CPE_2015_corewar/src
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Mon Feb 29 21:02:04 2016 Paul THEIS
** Last update Sun Apr 10 00:00:30 2016 THEIS Paul
*/

#ifndef DISLAY_H_
# define DISPLAY_H_

# include "main.h"

/*
** Allocation opttions
*/

void    *xalloc(const size_t);
void    *xealloc(void *, const size_t);
void    *xcalloc(size_t, const size_t);

/*
** Output opttions
*/

bool    my_put_err(char *, const bool);
int	my_putstr(char *);

#endif /* !DISPLAY_H_ */
