/*
** main.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:16:42 2016 THEIS Paul
** Last update Sun Apr 24 17:17:37 2016 marc brout
*/

#include "main.h"

void		init(t_info *info)
{
  atexit(SDL_Quit);
  init_struct(info);
  init_toolbar(info);
  init_space(info);
}

int		main()
{
  SDL_Event	event;
  int		quit;
  t_info	*info;

  info = xalloc(sizeof(t_info));
  memset(info, 0, sizeof(t_info));
  quit = 0;
  init(info);
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
