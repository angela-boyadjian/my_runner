/*
** EPITECH PROJECT, 2018
** check_mouse.c
** File description:
** check mouse functions
*/
#include "runner.h"

int	check_play(struct game *runner, struct game_object *obj,
	sfMouseButtonEvent event)
{
	struct music	*sound;

	if (obj->type == PLAY && get_click(obj, event.x, event.y) == true) {
		sound = get_obj(runner, MUSIC);
		sfMusic_stop(sound->music);
		runner->current_screen = GAME;
		return (1);
	}
	return (0);
}

int	check_exit(struct game *runner, struct game_object *obj,
	sfMouseButtonEvent event)
{
	if (obj->type == EXIT && get_click(obj, event.x, event.y) == true) {
		sfRenderWindow_close(runner->window);
		return (-1);
	}
	return (0);
}

int	check_help(struct game *runner, struct game_object *obj,
	sfMouseButtonEvent event)
{
	if (obj->type == HELP_BUTTON && get_click(obj, event.x, event.y)
		== true) {
		runner->current_screen = HELP;
		return (1);
	}
	return (0);
}

int	check_back(struct game *runner, struct game_object *obj,
	sfMouseButtonEvent event)
{
	if (obj->type == BACK && get_click(obj, event.x, event.y) == true) {
		runner->current_screen = MENU;
		return (1);
	}
	return (0);
}