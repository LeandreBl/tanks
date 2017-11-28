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
  mprintf("[%sInfo%s] Solo\n", YELLOW, RESET);
  return (solo(ptr));
}

int		menu_button_coop(void *data)
{
  game_t	*ptr;

  ptr = (game_t *)data;
  (void) ptr;
  mprintf("[%sInfo%s] Solo\n", YELLOW, RESET);  
  return (0);
}

int		menu_button_multi(void *data)
{
  game_t	*ptr;

  ptr = (game_t *)data;
  (void) ptr;
  mprintf("[%sInfo%s] Solo\n", YELLOW, RESET);
  return (0);
}

int		menu_button_back(void *data)
{
  game_t	*ptr;

  ptr = (game_t *)data;
  ptr->misc->leave = true;
  return (0);
}
