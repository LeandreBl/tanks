/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** solo events
*/

#include "tanks.h"

int		solo_evt_close(window_t *window, sfEvent *event, void *data)
{
  (void) event;
  (void) data;
  sfRenderWindow_close(window->window);
  return (0);
}

int		solo_evt_leave(window_t *window, sfEvent *event, void *data)
{
  solo_t	*ptr;

  (void) window;
  if (event->key.code == sfKeyEscape)
  {
    ptr = (solo_t *)data;
    ptr->leave = true;
  }
  return (0);
}
