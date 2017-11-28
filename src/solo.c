/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** solo
*/

#include "tanks.h"

# define FCTIONS (5)

static void		free_maps(map_t **maps)
{
  int			i;

  i = 0;
  while (maps != NULL && maps[i] != NULL)
  {
    free_tab(&maps[i]->map);
    sfree(&maps[i]->name);
    sfree(&maps[i]);
    ++i;
  }
  sfree(&maps);
}

static int		init_buttons(solo_t *solo)
{
  int			i;
  sfbutton_t		*new;
  sprite_t		*scroll;

  i = 0;
  solo->buttons = NULL;
  while (solo->maps != NULL && solo->maps[i] != NULL)
  {
    new = sfbutton_create(solo->maps[i]->name, solo->sprites[0],
			  xy_vectorf(50, 50 + 110 * i), NULL);
    solo->buttons = tab_append(solo->buttons, new);
    if (solo->buttons == NULL || new == NULL)
      return (-1);
    ++i;
  }
  scroll = sprite_by_name(solo->sprites, "scroll-solo-choice.png");
  new = sfbutton_create("scroll", scroll, xy_vectorf(800, 50), NULL);
  solo->buttons = tab_append(solo->buttons, new);
  if (solo->buttons == NULL || new == NULL)
    return (-1);
  return (0);
}

static int		fill(solo_t *solo, game_t *data, tank_t ***tanks)
{
  if (load_game_maps(&solo->maps) == -1)
    return (-1);
  *tanks = NULL;
  solo->misc = data->misc;
  solo->window = data->window;
  solo->leave = false;
  if (init_sprites(&solo->sprites, "-solo-choice.png") == -1)
    return (-1);
  if (init_buttons(solo) == -1)
    return (-1);
  solo->offset = 0;
  return (0);
}

static void		display(solo_t *solo)
{
  //put_sprite(solo->window, solo->sprites[1], ORIGIN);
  sfbutton_draw_name_all(solo->window, solo->buttons, sfBlack);
}

int			solo(game_t *data)
{
  evtptr_t		tab[FCTIONS];
  solo_t		solo;
  tank_t		**tanks;

  if (fill(&solo, data, &tanks) == -1)
    return (-1);
  init_solo_choice_t(tab);
  while (sfRenderWindow_isOpen(solo.window->window)
	 && solo.leave == false)
  {
    window_clear(solo.window);
    ptr_pollevent(solo.window, tab, FCTIONS, &solo);
    display(&solo);
    window_refresh(solo.window);
  }
  free_tanks(tanks);
  free_maps(solo.maps);
  free_sprites(solo.sprites);
  free_sfbuttons(solo.buttons);
  return (0);
}
