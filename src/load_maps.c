/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** load_maps
*/

#include "tanks.h"

static int	nb_ennemies(char **map)
{
  int		nb;
  int		i;
  uint8_t	type;

  nb = 0;
  i = 0;
  while (map != NULL && map[i] != NULL)
  {
    type = '0';
    while (type <= '9')
    {
      nb += nb_of(map[i], type);
      ++type;
    }
    ++i;
  }
  return (nb);
}

static map_t	*add_map(const char *pathname)
{
  map_t		*map;

  map = my_calloc(sizeof(map_t));
  if (map == NULL)
    return (NULL);
  map->map = load_file(pathname);
  map->ennemies = nb_ennemies(map->map);
  return (map);
}

static int	fill(map_t ***maps, char **filenames)
{
  char		*pathname;
  int		i;

  i = 0;
  while (filenames[i] != NULL)
  {
    if (end_with(filenames[i], ".tnk") == 0)
    {
      pathname = catalloc("maps/%s", filenames[i]);
      if (pathname == NULL)
	return (-1);
      mprintf("[%sInfo%s] Loading map : %s%s%s\n", YELLOW, RESET,
	      BLUE, filenames[i], RESET);
      *maps = tab_append(*maps, add_map(pathname));
      if (*maps == NULL)
	return (-1);
      sfree(&pathname);
    }
    ++i;
  }
  return (0);
}

int		load_game_maps(map_t ***maps)
{
  char		**filenames;

  *maps = NULL;
  filenames = dir_filenames("maps", 1);
  if (filenames == NULL)
  {
    mdprintf(2, EMPTY_MAP_DIR);
    return (-1);
  }
  if (fill(maps, filenames) == -1)
  {
    mdprintf(2, MEM_ERROR);
    free_tab(&filenames);
    return (-1);
  }
  free_tab(&filenames);
  return (0);
}
