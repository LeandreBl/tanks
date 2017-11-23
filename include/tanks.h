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

int	login(window_t *window, player_t *player);
void	encrypt(void *datas, int size);
void	init_login_evt_t(evtptr_t tab[]);
int	init_login_sprites(sprite_t ***sprites);

/* login pollEvent fctions */
int	login_add_char(window_t *window, sfEvent *event, void *data);
int	login_evt_close(window_t *window, sfEvent *event, void *data);

#endif /* !TANKS_H_ */
