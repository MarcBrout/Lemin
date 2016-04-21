/*
** get_next_line.c for GetNextLine in /home/theis_p/Getnextline
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Fri Nov 20 18:44:03 2015 Paul THEIS
** Last update Wed Apr 20 12:00:36 2016 THEIS Paul
*/

#include        "get_next_line.h"

static char     *set_line(char *line, int flag, char *buff, int *start)
{
  char          *tmp_elem;
  int           prev_len;

  prev_len = (line) ? my_strlen(line) : (0);
  if ((tmp_elem = malloc((prev_len + flag + 1) * sizeof(*tmp_elem))) == NULL)
    return (NULL);
  my_strncpy(tmp_elem, (line) ? (line) : (""), prev_len);
  my_strncpy(tmp_elem + prev_len, buff + *start, flag);
  tmp_elem[prev_len + flag] = 0;
  if (line)
    free(line);
  *start += flag + 1;
  return (tmp_elem);
}

char            *get_next_line(const int fd)
{
  static char   buff[READ_SIZE + 1];
  static int    nbread = 0;
  static int    start;
  char          *line;
  int           flag;

  line = 0;
  flag = 0;
  while (42)
    {
      if (start >= nbread)
        {
          start = 0;
          if (!(nbread = read(fd, buff, READ_SIZE)))
            return (line);
          if (nbread == -1)
            return (NULL);
          flag = 0;
        }
      if (buff[start + flag] == '\n')
        return (line = set_line(line, flag, buff, &start));
      if (start + flag == nbread - 1)
        if ((line = set_line(line, flag + 1, buff, &start)) == NULL)
	    return (NULL);
      ++flag;
    }
}
