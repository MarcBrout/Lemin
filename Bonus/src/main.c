/*
** main.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:16:42 2016 THEIS Paul
** Last update Mon Apr 25 13:37:02 2016 marc brout
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

int		main()
{
  SDL_Event	event;
  int		quit;
  t_info	*info;

  if (!(info = xalloc(sizeof(t_info))))
    return (1);
  my_bzero(info, sizeof(t_info), 0);
  quit = 0;
  if (init(info))
    return (1);
  parse(info);
  update_screen(info);
  while (!(quit))
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	quit = 1;
    }
  SDL_Quit();
  return (0);
}
