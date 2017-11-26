/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** game menu
*/

#include "tanks.h"

#define FCTIONS		(4)

static int		add_buttons(sfbutton_t ***buttons, sprite_t **sprites)
{
  sfbutton_t		*new;

  new = sfbutton_create("Solo", sprites[0], ORIGIN, menu_button_solo);
  *buttons = tab_append(*buttons, new);
  new = sfbutton_create("Coop", sprites[0], ORIGIN, menu_button_coop);
  *buttons = tab_append(*buttons, new);
  new = sfbutton_create("Multiplayer", sprites[0], ORIGIN, menu_button_multi);
  *buttons = tab_append(*buttons, new);
  new = sfbutton_create("<< Back", sprites[0], ORIGIN, menu_button_back);
  *buttons = tab_append(*buttons, new);
  return (0);
}

static int		init_menu(menu_t *misc, player_t *player)
{
  if (init_sprites(&misc->sprites, "-menu.png") == -1)
  {
    mdprintf(2, MEM_ERROR);
    return (-1);
  }
  misc->player = player;
  misc->buttons = NULL;
  misc->leave = 0;
  if (add_buttons(&misc->buttons, misc->sprites) == -1)
  {
    mdprintf(2, MEM_ERROR);
    return (-1);
  }
  return (0);
}

static void		display(window_t *window, player_t *player, menu_t *misc)
{
  int			i;
  sfColor		color;
  sfVector2f		pos;
  char			*format;

  i = 0;
  color = sfWhite;
  pos.x = 100;
  put_sprite(window, misc->sprites[1], ORIGIN);
  while (misc->buttons[i] != NULL)
  {
    pos.y = 100 + i * 75;
    sfbutton_draw_name(window, misc->buttons[i], pos, color);
    ++i;
  }
  format = catalloc("[%s]\n[level %d]\n\n\n[%S]\n",
		    player->name, player->level, get_ip(NULL));
  put_word(format, xy_vectorf(800, 500), window, sfBlack);
  sfree(&format);
}

int			game_menu(window_t *window, player_t *player)
{
  menu_t		misc;
  evtptr_t		tab[FCTIONS];

  if (init_menu(&misc, player) == -1)
    return (-1);
  init_menu_evt_t(tab);
  while (sfRenderWindow_isOpen(window->window)
    && misc.leave == false)
  {
    window_clear(window);
    ptr_pollevent(window, tab, FCTIONS, &misc);
    display(window, player, &misc);
    window_refresh(window);
  }
  free_sprites(misc.sprites);
  free_sfbuttons(misc.buttons);
  return (0);
}
