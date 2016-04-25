/*
** init.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Tue Apr 19 11:40:45 2016 THEIS Paul
** Last update Mon Apr 25 19:45:54 2016 marc brout
*/

#include "main.h"

int	init_struct(t_info *info)
{
  info->speed = 50;
  info->opt = 0;
  info->round = 0;
  if (TTF_Init() == -1)
    {
      my_put_error("erreur d'init de TTF_Init\n");
      return (1);
    }
  if (!(info->screen = SDL_SetVideoMode(W_W, W_H, 32, SDL_HWSURFACE)) ||
      !(info->font = TTF_OpenFont("font/font.ttf", 35)))
    return (my_put_error("Font not found\n"), 1);
  SDL_WM_SetCaption("Ant Man", NULL);
  return (0);
}

int		init_toolbar(t_info *info)
{
  SDL_Rect	pos;

  if (!(info->toolbar = SDL_CreateRGBSurface
	(SDL_HWSURFACE, W_W - (SPACE_1 * 2),
	 TOOLBAR_H, 32, 0, 0, 0, 0)))
    return (1);
  pos = set_pos(0 + SPACE_1, SPACE_H + (SPACE_1 * 3));
  if (SDL_FillRect(info->toolbar, NULL,
		   SDL_MapRGB(info->screen->format, 40, 44, 52)) < 0 ||
      SDL_BlitSurface(info->toolbar, NULL, info->screen, &pos) < 0)
    return (1);
  return (0);
}

int		init_space(t_info *info)
{
  SDL_Rect	pos;

  if (!(info->space = SDL_CreateRGBSurface(SDL_HWSURFACE,
					   W_W - (SPACE_1 * 2),
					   SPACE_H, 32, 0, 0, 0, 0)))
    return (1);
  pos = set_pos(0 + SPACE_1, STATBAR_H + (SPACE_1 * 2));
  if (SDL_FillRect(info->space, NULL,
		   SDL_MapRGB(info->screen->format, 40, 44, 52)) < 0 ||
      SDL_BlitSurface(info->space, NULL, info->screen, &pos) < 0)
    return (1);
  return (0);
}

void	init_SDL_Rect(SDL_Rect *pos)
{
  pos->x = 0;
  pos->y = 0;
}
