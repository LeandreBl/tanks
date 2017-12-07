/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** solo game choice level
*/

#include "tanks.h"

int		solo_choice_close(window_t *window, sfEvent *event, void *data)
{
  (void) event;
  (void) data;
  sfRenderWindow_close(window->window);
  return (0);
}

int		solo_choice_back(window_t *window, sfEvent *event, void *data)
{
  solo_t	*solo;

  (void) window;
  solo = (solo_t *)data;
  if (event->key.code == sfKeyEscape)
    solo->leave = true;
  return (0);
}

int		solo_scroll(window_t *window, sfEvent *event, void *data)
{
  solo_t	*solo;
  double	value;

  (void) window;
  solo = (solo_t *)data;
  value = (double)event->mouseWheelScroll.delta / 2;
  if (solo->offset - value >= 0 &&
      (50.0 * (solo->offset - value) + (tablen(solo->buttons)) * 110) < 650)
    solo->offset -= value;
  return (0);
}

int		menu_choice_buttons(window_t *window, sfEvent *event, void *data)
{
  solo_t	*solo;

  solo = (solo_t *)data;
  button_poll_event(window, event, solo->buttons, data);
  return (0);
}
