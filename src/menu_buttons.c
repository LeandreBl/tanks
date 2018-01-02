/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** menu buttons ptr
*/

#include "tanks.h"

int		menu_button_solo(void *data, sfbutton_t *this)
{
  game_t	*ptr;

  (void) this;
  ptr = (game_t *)data;
  mprintf("[%sInfo%s] Solo\n", YELLOW, RESET);
  return (solo(ptr));
}

int		menu_button_coop(void *data, sfbutton_t *this)
{
  game_t	*ptr;

  (void) this;
  ptr = (game_t *)data;
  (void) ptr;
  mprintf("[%sInfo%s] Solo\n", YELLOW, RESET);  
  return (0);
}

int		menu_button_multi(void *data, sfbutton_t *this)
{
  game_t	*ptr;

  (void) this;
  ptr = (game_t *)data;
  (void) ptr;
  mprintf("[%sInfo%s] Solo\n", YELLOW, RESET);
  return (0);
}

int		menu_button_back(void *data, sfbutton_t *this)
{
  game_t	*ptr;

  (void) this;
  ptr = (game_t *)data;
  ptr->misc->leave = true;
  return (0);
}
