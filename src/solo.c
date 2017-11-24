/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** solo
*/

#include "tanks.h"

# define FCTIONS (2)

static void		free_maps(map_t **maps)
{
  int			i;

  i = 0;
  while (maps != NULL && maps[i] != NULL)
  {
    free_tab(&maps[i]->map);
    sfree(&maps[i]);
    ++i;
  }
  sfree(&maps);
}

static void		solo_poll_event(solo_t *game)
{
  static bool		calls = false;
  static evtptr_t	tab[FCTIONS];
  sfEvent		event;
  int			i;

  if (calls == false)
  {
    init_solo_evt_t(tab);
    calls = true;
  }
  while (sfRenderWindow_pollEvent(game->window->window, &event))
  {
    i = 0;
    while (i < FCTIONS)
    {
      if (event.type == tab[i].type)
	tab[i].fction(game->window, &event, game);
      ++i;
    }
  }
}

static int		fill(solo_t *game, game_t *data, tank_t ***tanks)
{
  if (load_game_maps(&game->maps) == -1)
    return (-1);
  *tanks = NULL;
  game->misc = data->misc;
  game->window = data->window;
  game->leave = false;
  game->buttons = NULL;
  game->sprites = NULL;
  return (0);
}

int			solo(game_t *data)
{
  solo_t	game;
  tank_t	**tanks;

  if (fill(&game, data, &tanks) == -1)
  {
    mdprintf(2, MEM_ERROR);
    return (-1);
  }
  while (sfRenderWindow_isOpen(game.window->window)
	 && game.leave == false)
  {
    window_clear(game.window);
    solo_poll_event(&game);
    window_refresh(game.window);
  }
  free_tanks(tanks);
  free_maps(game.maps);
  return (0);
}
