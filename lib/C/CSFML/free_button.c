/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** destroy button
*/

#include "csfml.h"

void		free_sfbutton(sfbutton_t *button)
{
  if (button != NULL)
  {
    sfree(&button->name);
    sfree(&button);
  }
}
