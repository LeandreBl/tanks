/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** main
*/

#include "tanks.h"

int		main(void)
{
  window_t	*window;
  player_t	player;

  window = init_window(720, 16.0 / 9.0, NULL, sfClose);
  if (window == NULL)
    return (-1);
  window->font = my_strdup("fonts/audims.ttf");
  if (login(window, &player) == -1)
  {
    sfree(&player.name);
    free_window(window);
    return (-1);
  }
  sfree(&player.name);
  free_window(window);
  return (0);
}
