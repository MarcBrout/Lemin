/*
** main.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:16:42 2016 THEIS Paul
** Last update Sat Apr 23 16:33:56 2016 THEIS Paul
*/

#include "main.h"

void		init(t_info *info)
{
  atexit(SDL_Quit);
  init_struct(info);
  init_toolbar(info);
  init_space(info);
}

int		main(int argc, char *argv[])
{
  SDL_Event	event;
  int		quit;
  t_info	*info;

  info = xalloc(sizeof(*info));
  memset(info, 0, sizeof(*info));
  quit = 0;
  init(info);
  parse(info);
  update_screen(info);
  //SDL_EnableKeyRepeat(10, 10);
  while (!(quit))
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	quit = 1;
    }
  SDL_Quit();
  return 0;
}
