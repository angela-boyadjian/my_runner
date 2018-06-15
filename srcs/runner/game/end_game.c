/*
** EPITECH PROJECT, 2018
** end_game.c
** File description:
** function for ending game
*/
#include "runner.h"

void	check_victory(struct game *runner)
{
	struct game_object *obj = runner->screens[GAME]->prev->data;
	struct sprite		*img = (struct sprite *)obj->obj;
	sfVector2f		pos;
	struct music		*sound;

	if (runner->current_screen == GAME) {
		pos = sfSprite_getPosition(img->sprite);
		if (pos.x < -100) {
			sound = get_obj(runner, MUSIC);
			sfMusic_stop(sound->music);
			runner->current_screen = VICTORY;
		}
	}
}

void	reset_pos(struct game_object *obj, sfVector2f pos)
{
	struct sprite	*img = (struct sprite *) obj->obj;

	sfSprite_setPosition(img->sprite, pos);
}

void	reset_game(struct game *runner)
{
	struct text	*score = get_obj(runner, SCORE);
	struct sprite	*ship = get_obj(runner, SHIP);
	struct node	*head = runner->screens[GAME];
	struct node	*tmp = head;
	struct game_object *obj;
	int		i = 0;

	ship->speed = ret_vec(0.0f, 0.0f);
	sfSprite_setPosition(ship->sprite, ret_vec(250.0f, 100.0f));
	do {
		obj = (struct game_object *) tmp->data;
		if (obj->type == OBSTACLE) {
			reset_pos(obj, ret_vec(runner->tab[i].y,
				runner->tab[i].x));
			++i;
		}
		tmp = tmp->next;
	} while (tmp != head);
	score->points = 0;
}