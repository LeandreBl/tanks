/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** header
*/

#ifndef TANKS_H_
# define TANKS_H_

# include "csfml.h"

# include "my.h"
# include "defines.h"
# include "colors.h"

# include "struct.h"
# include "errors.h"

# define RGBA(r, g, b, a) sfColor_fromRGBA(r, g, b, a)

int	login(window_t *window, player_t *player);
void	encrypt(void *datas, int size);
void	init_login_evt_t(evtptr_t tab[]);
int	init_login_sprites(sprite_t ***sprites);

int	game_menu(window_t *window, player_t *player);
void	init_menu_evt_t(evtptr_t tab[]);

/* login pollEvent fctions */
int	login_add_char(window_t *window, sfEvent *event, void *data);
int	login_evt_close(window_t *window, sfEvent *event, void *data);
int	login_accept(window_t *window, sfEvent *event, void *data);

/* game menu pollEvent fctions */
int	menu_evt_close(window_t *window, sfEvent *event, void *data);

#endif /* !TANKS_H_ */
