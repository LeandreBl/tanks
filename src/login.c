/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** login
*/

#include "tanks.h"

#define FCTIONS		(3)

static void		display(window_t *window, player_t *player, sprite_t **sprites)
{
  sfVector2f		pos;
  sfColor		color;

  pos.x = 415;
  pos.y = 377;
  put_sprite(window, sprites[0], ORIGIN);
  if (my_strlen(player->name) == 0)
  {
    color = RGBA(50, 50, 50, 150);
    put_word("<enter name here>", pos, window, color);
  }
  else
  {
    color = sfBlack;
    put_word(player->name, pos, window, color);
  }
}

static void		init_players_values(player_t *player)
{
  player->name = NULL;
  player->len = 0;
  player->level = 0;
  player->socket = -1;
}

int			login(window_t *window, player_t *player)
{
  sprite_t		**sprites;
  evtptr_t		tab[FCTIONS];

  init_players_values(player);
  if (init_sprites(&sprites, "-login.png") == -1)
    return (-1);
  init_login_evt_t(tab);
  while (sfRenderWindow_isOpen(window->window))
  {
    window_clear(window);
    ptr_pollevent(window, tab, FCTIONS, player);
    display(window, player, sprites);
    window_refresh(window);
  }
  free_sprites(sprites);
  return (0);
}
