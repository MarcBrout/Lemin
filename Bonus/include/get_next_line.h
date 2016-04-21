/*
** get_next_line.h for GetNextLine in /home/theis_p/Getnextline
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Fri Nov 20 18:44:03 2015 Paul THEIS
** Last update Wed Apr 20 18:44:57 2016 THEIS Paul
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#include <unistd.h>
#include <stdlib.h>

#include "main.h"

char            *get_next_line(const int fd);
static char     *set_line(char *line, int treat, char *buff, int *start);

#ifndef	READ_SIZE
# define READ_SIZE (42)
#endif /* !READ_SIZE */

#endif /* !GET_NEXT_LINE_H_ */
