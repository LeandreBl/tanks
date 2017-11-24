/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** login sprites
*/

#include "tanks.h"

static int	add_each_sprite(sprite_t ***sprites, char **files,
				const char *endwith)
{
  char		*pathname;
  sprite_t	*new;
  int		i;

  i = 0;
  while (files[i] != NULL)
  {
    if (end_with(files[i], endwith) == 0)
    {
      pathname = catalloc("sprites/%s", files[i]);
      new = create_sprite(pathname);
      if (new == NULL)
      {
	mdprintf(2, MEM_ERROR);
	sfree(&pathname);
	return (-1);
      }
      *sprites = tab_append(*sprites, new);
      sfree(&pathname);
    }
    ++i;
  }
  return (0);
}

int		init_sprites(sprite_t ***sprites, const char *endwith)
{
  char		**files;

  *sprites = NULL;
  files = dir_filenames("sprites/", 1);
  if (files == NULL)
  {
    mdprintf(2, EMPTY_DIR);
    free_tab(&files);
    return (-1);
  }
  add_each_sprite(sprites, files, endwith);
  free_tab(&files);
  return (0);
}
