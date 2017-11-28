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

int		solo_scroll_button(window_t *window, sfEvent *event, void *data)
{
  solo_t	*solo;
  sfbutton_t	*scroll;
  static bool	press = false;
  static int	from;

  (void) window;
  solo = (solo_t *)data;
  scroll = button_by_name(solo->buttons, "scroll");
  if (event->type == sfEvtMouseButtonPressed)
  {
    press = true;
    from = event->mouseButton.y;
  }
  if (event->type == sfEvtMouseButtonReleased)
    press = false;
  if (press == true)
  {
    if (event->type == sfEvtMouseButtonPressed)
      scroll->pos.y += (event->mouseButton.y - from - scroll->pos.y);
    if (event->type == sfEvtMouseMoved)
      scroll->pos.y += (event->mouseMove.y - from - scroll->pos.y);
    solo->offset = scroll->pos.y;
  }
  return (0);
}

int		menu_choice_buttons(window_t *window, sfEvent *event, void *data)
{
  solo_t	*solo;
  sfbutton_t	*scroll;
  sfVector2i	pos;

  solo = (solo_t *)data;
  scroll = button_by_name(solo->buttons, "scroll");
  button_poll_event(window, event, solo->buttons, data);
  if (event->type == sfEvtMouseMoved)
    pos = xy_vectori(event->mouseMove.x, event->mouseMove.y);
  else
    pos = xy_vectori(event->mouseButton.x, event->mouseButton.y);
  if (sfbutton_ispressed(scroll, pos))
    solo_scroll_button(window, event, data);
  return (0);
}
