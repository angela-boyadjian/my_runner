/*
** EPITECH PROJECT, 2018
** event.c
** File description:
** envent related functions
*/
#include "runner.h"

static int	manage_mouse(sfMouseButtonEvent event, struct game *runner)
{
	struct node		*head = runner->screens[runner->current_screen];
	struct node		*tmp = head;
	struct game_object	*obj;

	if (event.button == sfMouseLeft) {
		do {
			obj = (struct game_object *)tmp->data;
			if (check_play(runner, obj, event) == 1)
				return (0);
			if (check_exit(runner, obj, event) == -1)
				return (-1);
			if (check_help(runner, obj, event) == 1)
				return (0);
			if (check_back(runner, obj, event) == 1)
				return (0);
			tmp = tmp->next;
		} while (tmp != head);
	}
	return (0);
}

int	analyse_event(struct game *runner, sfEvent event)
{
	if (event.type == sfEvtClosed) {
		sfRenderWindow_close(runner->window);
		return (1);
	}
	check_event(runner, event, sfKeySpace, &key_space);
	check_event(runner, event, sfKeyR, &key_r);
	check_event(runner, event, sfKeyP, &key_p);
	check_event(runner, event, sfKeyM, &key_m);
	if (event.type == sfEvtMouseButtonPressed
	&& manage_mouse(event.mouseButton, runner) == -1)
		return (1);
	return (0);
}

int	handle_event(struct game *runner)
{
	sfEvent 	event;
	int		value;

	if (sfRenderWindow_pollEvent(runner->window, &event))
		value = analyse_event(runner, event);
	return (value);
}