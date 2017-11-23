/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** login events
*/

#include "tanks.h"

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
  return (0);
}
