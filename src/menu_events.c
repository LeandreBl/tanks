/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** menu events
*/

#include "tanks.h"

int		buttons_events(window_t *window, sfEvent *event, void *data)
{
  game_t	block;
  menu_t	*misc;

  misc = (menu_t *)data;
  block.window = window;
  block.misc = misc;
  return (button_poll_event(window, event, misc->buttons, &block));
}

int		menu_evt_close(window_t *window, sfEvent *event, void *data)
{
  (void) event;
  (void) data;
  sfRenderWindow_close(window->window);
  return (0);
}

int		menu_evt_move(window_t *window, sfEvent *event, void *data)
{
 (void) data;
 window->mouse.x = event->mouseMove.x;
 window->mouse.y = event->mouseMove.y;
 return (0);
}

int		menu_evt_escape(window_t *window, sfEvent *event, void *data)
{
  menu_t	*ptr;

  (void) window;
  if (event->key.code == sfKeyEscape)
  {
    ptr = (menu_t *)data;
    ptr->leave = 1;
  }
  return (0);
}
