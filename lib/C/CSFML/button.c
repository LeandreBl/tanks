/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** Creation of a generic button
*/

#include "csfml.h"

sfbutton_t	*sfbutton_create(const char *name, sprite_t *sprite,
				 const sfIntRect *hitbox,
				 int (*fction)(void *data))
{
  sfbutton_t	*button;
  sfVector2u	size;

  button = my_calloc(sizeof(sfbutton_t));
  if (button == NULL)
    return (NULL);
  button->name = my_strdup(name);
  button->sprite = sprite;
  if (hitbox == NULL && sprite != NULL)
  {
    size = sfTexture_getSize(sprite->texture);
    button->pos = sfSprite_getPosition(sprite->sprite);
    button->size.x = size.x;
    button->size.y = size.y;
  }
  else
  {
    button->pos = xy_vectorf(hitbox->left, hitbox->top);
    button->size = xy_vectorf(hitbox->width, hitbox->height);
  }
  button->fction = fction;
  sfSprite_setPosition(sprite->sprite, button->pos);
  return (button);
}

int		sfbutton_ispressed(sfbutton_t *button, sfVector2i pos)
{
  sfIntRect	rect;

  fill_rect(button->pos, button->size.x, button->size.y, &rect);
  if (in_rect(pos, &rect))
    return (1);
  return (0);
}

void		sfbutton_draw(window_t *window, sfbutton_t *button)
{
  pos_mouse(window);
  if (sfbutton_ispressed(button, window->mouse))
  {
    sfSprite_setColor(button->sprite->sprite, sfColor_fromRGB(100, 100, 100));
    put_sprite(window, button->sprite, button->pos);
    sfSprite_setColor(button->sprite->sprite, sfWhite);
  }
  else
    put_sprite(window, button->sprite, button->pos);
}

void		sfbutton_draw_name(window_t *window, sfbutton_t *button,
				   sfColor color)
{
  sfVector2f	pos;
  sfVector2f	size;

  size.x = my_strlen(button->name) * 12;
  size.y = (nb_of(button->name, '\n') + 1) * 24;
  pos.x = button->pos.x + (button->size.x - size.x) / 2;
  pos.y = button->pos.y + (button->size.y - size.y) / 2;
  sfbutton_draw(window, button);
  put_word(button->name, pos, window, color);
}

int		sfbutton_exec(sfbutton_t *button, sfVector2i pos, void *data)
{
  if (sfbutton_ispressed(button, pos))
    return (button->fction(data));
  return (-1);
}
