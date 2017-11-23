/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** add_event ptr
*/

#include "tanks.h"

void		add_evt(evtptr_t *index, int type, evt_t fction)
{
  index->type = type;
  index->fction = fction;
}

void		init_login_evt_t(evtptr_t tab[])
{
  add_evt(&tab[0], sfEvtTextEntered, login_add_char);
  add_evt(&tab[1], sfEvtClosed, login_evt_close);
}
