/*
** EPITECH PROJECT, 2018
** collision.c
** File description:
** collision detection functions
*/
#include "runner.h"

static bool	check_collision(sfFloatRect *rect, sfFloatRect *rect_ob)
{
	if (sfFloatRect_intersects(rect, rect_ob, NULL) == sfTrue)
		return (true);
	return (false);
}

int	col_obstacle(struct game_object *obj, struct node *head,
	struct game *runner)
{
	(void)obj;
	(void)head;
	(void)runner;
	return (0);
}

static int	check_player(struct game *runner, sfFloatRect *rect,
	sfFloatRect *rect_ob)
{
	struct music	*sound;
	
	if (check_collision(rect, rect_ob) == true) {
		sound = get_obj(runner, MUSIC);
		sfMusic_stop(sound->music);
		sfSound_play(runner->sound_effect->sound);
		runner->current_screen = DEFEAT;
		return (1);
	}
	return (0);
}

int	col_player(struct game_object *obj, struct node *head,
	struct game *runner)
{
	struct node		*tmp = head;
	struct game_object	*obj_2;
	struct sprite		*img = (struct sprite *)obj->obj;
	sfFloatRect		rect = sfSprite_getGlobalBounds(img->sprite);
	sfFloatRect		rect_ob;
	struct sprite		*img_2;

	do {
		obj_2 = (struct game_object *)tmp->data;
		if (obj_2->type == OBSTACLE) {
			img_2 = (struct sprite *) obj_2->obj;
			rect_ob = sfSprite_getGlobalBounds(img_2->sprite);
			if (check_player(runner, &rect, &rect_ob) == 1)
				return (1);
		}
		tmp = tmp->next;
	} while (tmp != head);
	return (0);
}

int	col_null(struct game_object *obj, struct node *head,
	struct game *runner)
{
	(void)obj;
	(void)head;
	(void)runner;
	return(0);
}