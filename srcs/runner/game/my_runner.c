/*
** EPITECH PROJECT, 2018
** my_runner.c
** File description:
** functions for the game
*/
#include "runner.h"

static float	handle_time(sfClock *clock, float framerate)
{
	sfTime	time = sfClock_getElapsedTime(clock);
	return (time.microseconds / framerate);
}

static void	handle_display(struct game *runner)
{
	sfRenderWindow_display(runner->window);
	sfClock_restart(runner->clock);
	check_victory(runner);
}

int	my_runner(struct game *runner)
{
	struct node	*tmp;
	struct node	*head;
	struct game_object *obj;

	if (handle_event(runner) == 1)
		return (1);
	if (handle_time(runner->clock, 1000000.0f) > 0.05f) {
		head = (runner->screens)[runner->current_screen];
		tmp = head;
		do {
			obj = (struct game_object *)tmp->data;
			obj->ptr_display(obj, runner);
			obj->ptr_move(obj);
			if (obj->ptr_collide(obj, head, runner) == 1)
				break;
			tmp = tmp->next;
		} while (tmp != head);
		handle_display(runner);
	}
	return (0);
}