/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** struct header file
*/

#ifndef STRUCT_H_
# define STRUCT_H_

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
}		menu_t;

typedef int (* evt_t)(window_t *window, sfEvent *event, void *data);

typedef struct	evtptr_s
{
  sfEventType	type;
  evt_t		fction;
}		evtptr_t;

#endif /* !STRUCT_H_ */
