/*
** init.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Tue Apr 19 11:40:45 2016 THEIS Paul
** Last update Thu Apr 21 17:45:24 2016 THEIS Paul
*/

#include "main.h"

void	init_struct(t_info *info)
{
  info->speed = 80000;
  info->black = (SDL_Color) {0, 0, 0};
  info->white = (SDL_Color) {255, 255, 255};
  info->opt = 0;
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "Erreur à l'initialisation de la SDL : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  info->screen = SDL_SetVideoMode(W_W, W_H,
                               32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  info->round = 0;
  if(TTF_Init() == -1)
  {
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
  }
  if ((info->font = TTF_OpenFont("font/font.ttf", 35)) == NULL)
    return;
  atexit(SDL_Quit);
  SDL_WM_SetCaption("Ant Man", NULL);
}

void	init_toolbar(t_info *info)
{
  SDL_Rect pos;

  info->toolbar = SDL_CreateRGBSurface(SDL_HWSURFACE, W_W - (SPACE_1 * 2), TOOLBAR_H, 32, 0, 0, 0, 0);
  pos = set_pos(0 + SPACE_1, STATBAR_H + (SPACE_1 * 3));
  SDL_FillRect(info->toolbar, NULL, SDL_MapRGB(info->screen->format, 40, 44, 52));
  SDL_BlitSurface(info->toolbar, NULL, info->screen, &pos);
}

void	init_space(t_info *info)
{
  SDL_Rect pos;

  info->space = SDL_CreateRGBSurface(SDL_HWSURFACE, W_W - (SPACE_1 * 2), SPACE_H, 32, 0, 0, 0, 0);
  pos = set_pos(0 + SPACE_1, STATBAR_H + (SPACE_1 * 2));
  SDL_FillRect(info->space, NULL, SDL_MapRGB(info->screen->format, 40, 44, 52));
  SDL_BlitSurface(info->space, NULL, info->screen, &pos);
}
