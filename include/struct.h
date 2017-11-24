/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** struct header file
*/

#ifndef STRUCT_H_
# define STRUCT_H_

enum	team_e
{
  ally,
  ennemy,
};

typedef struct	tank_s
{
  char		*name;
  sfVector2f	pos;
  sfIntRect	hitbox;
  double	canon_angle;
  double	tank_angle;
  int		ammo;
  double	speed;
  enum team_e	team;
}		tank_t;

typedef struct	save_pkt_s
{
  int		len;
  char		*name;
  int		level;
}		save_pkt_t;

typedef struct  player_s
{
  int           len;
  char          *name;
  int           level;
  int           socket;
}               player_t;

typedef struct	menu_misc_s
{
  sprite_t	**sprites;
  sfbutton_t	**buttons;
  player_t	*player;
  bool		leave;
}		menu_t;

typedef struct	game_s
{
  window_t	*window;
  menu_t	*misc;
}		game_t;

typedef struct	map_s
{
  int		ennemies;
  char		**map;
}		map_t;

typedef struct	solo_s
{
  sprite_t	**sprites;
  sfbutton_t	**buttons;
  map_t		**maps;
  menu_t	*misc;
  window_t	*window;
  bool		leave;
}		solo_t;

typedef int (* evt_t)(window_t *window, sfEvent *event, void *data);

typedef struct	evtptr_s
{
  sfEventType	type;
  evt_t		fction;
}		evtptr_t;

#endif /* !STRUCT_H_ */
