/*
** main.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:16:42 2016 THEIS Paul
** Last update Mon Apr 25 20:01:33 2016 marc brout
*/

#include "main.h"

int		init(t_info *info)
{
  if (init_struct(info) ||
      init_toolbar(info) ||
      init_space(info))
    return (1);
  return (0);
}

char	*reverse_str(char *str)
{
  char	*rev;
  int	i;
  int	j;

  i = my_strlen(str);
  if (!(rev = malloc(i + 1)))
    return (NULL);
  rev[i] = 0;
  j = -1;
  while (str && --i >= 0)
    rev[++j] = str[i];
  free(str);
  return (rev);
}

char	*my_putnbr_char(int nb)
{
  char	*str;
  int	i;

  i = 0;
  if (!(str = malloc(sizeof(char) * 21)))
    return (NULL);
  my_bzero(str, 21, 0);
  if (nb == 0)
    str[i] = '0';
  while (nb > 0)
    {
      str[i++] = (nb % 10) + '0';
      nb = nb / 10;
    }
  if (!(str = reverse_str(str)))
    return (NULL);
  return (str);
}

int		main()
{
  SDL_Event	event;
  int		quit;
  t_info	*info;

  if (!(info = xalloc(sizeof(t_info))))
    return (1);
  my_bzero(info, sizeof(t_info), 0);
  quit = 0;
  if (init(info) ||  parse(info) || update_screen(info))
    return (1);
  while (!(quit))
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	quit = 1;
    }
  SDL_Quit();
  return (0);
}
