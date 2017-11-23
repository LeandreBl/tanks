/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** login sprites
*/

#include "tanks.h"

int		init_login_sprites(sprite_t ***sprites)
{
  char		**files;
  char		*pathname;
  sprite_t	*new;
  int		i;

  i = 0;
  *sprites = NULL;
  files = dir_filenames("sprites/", 1);
  while (files[i] != NULL)
  {
    if (end_with(files[i], "-login.png") == 0)
    {
      pathname = catalloc("sprites/%s", files[i]);
      new = create_sprite(pathname);
      if (new == NULL)
	return (-1);
      *sprites = tab_append(*sprites, new);
      sfree(&pathname);
    }
    ++i;
  }
  free_tab(&files);
  return (0);
}
