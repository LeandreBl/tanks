/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** menu events
*/

#include "tanks.h"

int		menu_evt_close(window_t *window, sfEvent *event, void *data)
{
  (void) event;
  (void) data;
  sfRenderWindow_close(window->window);
  return (0);
}
