/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** game menu
*/

#include "tanks.h"

#define FCTIONS		(1)

static int		game_menu_poll_event(window_t *window, menu_t *misc)
{
  static int		calls = 0;
  static evtptr_t	tab[FCTIONS];
  sfEvent		event;
  int			i;

  if (calls == 0)
  {
    init_menu_evt_t(tab);
    calls = 1;
  }
  while (sfRenderWindow_pollEvent(window->window, &event))
  {
    i = 0;
    while (i < FCTIONS)
    {
      if (event.type == tab[i].type)
	tab[i].fction(window, &event, misc);
      ++i;
    }
  }
  return (0);
}

static void		init_menu(menu_t *misc, player_t *player)
{
  misc->sprites = NULL;
  misc->player = player;
  misc->buttons = NULL;
}

int			game_menu(window_t *window, player_t *player)
{
  menu_t		misc;

  init_menu(&misc, player);
  while (sfRenderWindow_isOpen(window->window))
  {
    window_clear(window);
    game_menu_poll_event(window, &misc);
    window_refresh(window);
  }
  return (0);
}
