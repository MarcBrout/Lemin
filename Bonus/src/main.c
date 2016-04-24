/*
** main.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:16:42 2016 THEIS Paul
<<<<<<< HEAD
** Last update Sat Apr 23 20:15:25 2016 benjamin duhieu
=======
** Last update Sat Apr 23 20:14:36 2016 marc brout
>>>>>>> 73b0862f14ca32db4b3470887ea057e9bee55244
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
  return 0;
}
