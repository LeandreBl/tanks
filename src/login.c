/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** login
*/

#include "tanks.h"

#define FCTIONS		(2)

static void		log_poll_evt(window_t *window, player_t *player)
{
  static int		calls = 0;
  static evtptr_t	tab[FCTIONS];
  sfEvent		event;
  int			i;

  if (calls == 0)
  {
    init_login_evt_t(tab);
    calls = 1;
  }
  while (sfRenderWindow_pollEvent(window->window, &event))
  {
    i = 0;
    while (i < FCTIONS)
    {
      if (event.type == tab[i].type)
	tab[i].fction(window, &event, player);
      ++i;
    }
  }
}

static void		display(window_t *window, player_t *player, t_sprite **sprites)
{
  sfVector2f		pos;
  char			*format;

  format = catalloc("Enter login : %s", player->name);
  pos.x = (window->width - my_strlen(format) * 12) / 2;
  pos.y = window->height / 2 - 12;
  put_word(format, pos, window, sfBlack);
  sfree(&format);
}

int			login(window_t *window, player_t *player)
{
  player->name = NULL;
  player->len = 0;
  player->level = 0;
  player->socket = -1;
  while (sfRenderWindow_isOpen(window->window))
  {
    window_clear(window);
    log_poll_evt(window, player);
    display(window, player);
    window_refresh(window);
  }
  return (0);
}
