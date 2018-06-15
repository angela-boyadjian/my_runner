/*
** EPITECH PROJECT, 2018
** check_event.c
** File description:
** chechk events functions
*/
#include "runner.h"

int	check_event(struct game *runner, sfEvent event, sfKeyCode key,
	int (*ptr)(struct game *))
{
	if (event.type == sfEvtKeyPressed && event.key.code == key) {
		ptr(runner);
		return (1);
	}
	return (0);
}

int	key_space(struct game *runner)
{
	go_up(runner->screens[GAME]);
	return (0);
}

int	key_r(struct game *runner)
{
	runner->current_screen = GAME;
	reset_game(runner);
	return (0);
}

int	key_p(struct game *runner)
{
	if (runner->current_screen == GAME)
		runner->current_screen = PAUSE;
	else if (runner->current_screen == PAUSE)
		runner->current_screen = GAME;
	return (0);
}

int	key_m(struct game *runner)
{
	struct music *sound = NULL;

	if (runner->current_screen == GAME) {
		sound = get_obj(runner, MUSIC);
		sfMusic_stop(sound->music);
	}
	runner->current_screen = MENU;
	return (0);
}