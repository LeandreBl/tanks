/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** add new tank
*/

#include "tanks.h"

void		free_tank(tank_t *tank)
{
  if (tank != NULL)
  {
    sfree(&tank->name);
    sfree(&tank);
  }
}

void		free_tanks(tank_t **tanks)
{
  int		i;

  i = 0;
  while (tanks != NULL && tanks[i] != NULL)
  {
    free_tank(tanks[i]);
    ++i;
  }
}

tank_t		*add_tank(char *name, sfVector2f pos,
			  int ammo, enum team_e team)
{
  tank_t	*tank;

  tank = my_calloc(sizeof(tank_t));
  if (tank == NULL)
    return (NULL);
  tank->name = my_strdup(name);
  tank->pos = pos;
  fill_rect(pos, 30, 30, &tank->hitbox);
  tank->canon_angle = 90;
  tank->ammo = ammo;
  tank->speed = 0;
  tank->team = team;
  return (tank);
}
