/*
** main.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Apr 20 11:16:42 2016 THEIS Paul
** Last update Thu Apr 21 19:46:32 2016 THEIS Paul
*/

#include "main.h"

void		init(t_info *info)
{
  init_struct(info);
  init_toolbar(info);
  init_space(info);
}

void	check_nbr_ants(char *str, t_info *info)
{
  if (atoi(str) >= 1023)
    {
      printf("Error : Maximum number of ants is 1024 for Visu .. Sorry\n");
      exit (0);
    }
  else
    info->nbr_ants = atoi(str);
}

void	put_error(char *str)
{
  printf("%s", str);
  exit (-1);
}

int		main(int argc, char *argv[])
{
  SDL_Event	event;
  int		quit;
  t_info	*info;

  info = xalloc(sizeof(*info));
  memset(info, 0, sizeof(*info));
  atexit(SDL_Quit);
  quit = 0;
  init(info);
  parse(info);
  update_screen(info);
  SDL_EnableKeyRepeat(10, 10);
  while (!(quit))
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	quit = 1;
    }
  SDL_Quit();
  return 0;
}
