/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** solo
*/

#include "tanks.h"

# define FCTIONS (6)

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
  evtptr_t		tab[FCTIONS];
  solo_t		game;
  tank_t		**tanks;

  
  if (fill(&game, data, &tanks) == -1)
    return (-1);
  init_solo_evt_t(tab);
  while (sfRenderWindow_isOpen(game.window->window)
	 && game.leave == false)
  {
    window_clear(game.window);
    ptr_pollevent(game.window, tab, FCTIONS, &game);
    window_refresh(game.window);
  }
  free_tanks(tanks);
  free_maps(game.maps);
  return (0);
}
