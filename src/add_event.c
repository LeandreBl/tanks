/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** add_event ptr
*/

#include "tanks.h"

void		init_login_evt_t(evtptr_t tab[])
{
  add_evt(&tab[0], sfEvtTextEntered, login_add_char);
  add_evt(&tab[1], sfEvtClosed, login_evt_close);
  add_evt(&tab[2], sfEvtKeyPressed, login_accept);
}

void		init_menu_evt_t(evtptr_t tab[])
{
  add_evt(&tab[0], sfEvtClosed, menu_evt_close);
  add_evt(&tab[1], sfEvtMouseButtonPressed, buttons_events);
  add_evt(&tab[2], sfEvtMouseMoved, menu_evt_move);
  add_evt(&tab[3], sfEvtKeyPressed, menu_evt_escape);
}

void		init_solo_evt_t(evtptr_t tab[])
{
  add_evt(&tab[0], sfEvtClosed, solo_evt_close);
  add_evt(&tab[1], sfEvtKeyPressed, solo_evt_leave);
  add_evt(&tab[2], sfEvtKeyPressed, solo_move_up);
  add_evt(&tab[3], sfEvtKeyPressed, solo_move_down);
  add_evt(&tab[4], sfEvtKeyPressed, solo_move_left);
  add_evt(&tab[5], sfEvtKeyPressed, solo_move_right);
}

void		init_solo_choice_t(evtptr_t tab[])
{
  add_evt(&tab[0], sfEvtClosed, solo_choice_close);
  add_evt(&tab[1], sfEvtKeyPressed, solo_choice_back);
  add_evt(&tab[2], sfEvtMouseButtonPressed, menu_choice_buttons);
  add_evt(&tab[3], sfEvtMouseMoved, solo_scroll_button);
  add_evt(&tab[4], sfEvtMouseButtonReleased, solo_scroll_button);
}
