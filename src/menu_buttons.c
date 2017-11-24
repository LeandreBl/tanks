/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** menu buttons ptr
*/

#include "tanks.h"

int		menu_button_solo(void *data)
{
  game_t	*ptr;

  ptr = (game_t *)data;
  (void) ptr;
  mprintf("Solo\n");
  return (0);
}

int		menu_button_coop(void *data)
{
  game_t	*ptr;

  ptr = (game_t *)data;
  (void) ptr;
  mprintf("Coop\n");
  return (0);
}

int		menu_button_multi(void *data)
{
  game_t	*ptr;

  ptr = (game_t *)data;
  (void) ptr;
  mprintf("Multijoueurs\n");
  return (0);
}

int		menu_button_back(void *data)
{
  game_t	*ptr;

  ptr = (game_t *)data;
  ptr->misc->leave = 1;
  return (0);
}
