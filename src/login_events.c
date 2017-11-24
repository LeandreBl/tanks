/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** login events
*/

#include "tanks.h"

int		login_accept(window_t *window, sfEvent *event, void *data)
{
  player_t	*ptr;

  ptr = (player_t *)data;
  if (event->key.code == sfKeyReturn
      && my_strlen(ptr->name) > 0)
  {
    return (game_menu(window, ptr));
  }
  return (0);
}

int		login_evt_close(window_t *window, sfEvent *event, void *data)
{
  (void) event;
  (void) data;
  sfRenderWindow_close(window->window);
  return (0);
}

int		login_add_char(window_t *window, sfEvent *event, void *data)
{
  player_t	*ptr;

  (void) window;
  ptr = (player_t *)data;
  if (event->text.unicode >= ' ' && event->text.unicode < 127)
  {
    ptr->name = catalloc("%S%c", ptr->name, event->text.unicode);
  }
  if (event->text.unicode == '\b')
    shift_right(ptr->name, 1);
  if (event->text.unicode == '\04' && my_strlen(ptr->name) == 0)
    login_evt_close(window, event, data);
  return (0);
}
