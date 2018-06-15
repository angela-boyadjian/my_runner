/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** display functions
*/
#include "runner.h"

void	display_sprite(struct game_object *obj, struct game *runner)
{
	struct sprite	*img = (struct sprite *)obj->obj;

	sfRenderWindow_drawSprite(runner->window, img->sprite, NULL);
}

void	display_text(struct game_object *obj, struct game *runner)
{
	struct text	*score = (struct text *)obj->obj;

	sfRenderWindow_drawText(runner->window, score->text, NULL);
}

void	play_music(struct game_object *obj, struct game *runner)
{
	struct music	*sound = (struct music *)obj->obj;

	(void)runner;
	if (sfMusic_getStatus(sound->music) == sfStopped)
		sfMusic_play(sound->music);
}

void	display_intro(struct game_object *obj, struct game *runner)
{
	struct sprite	*img = (struct sprite *)obj->obj;
	sfVector2f	pos = sfSprite_getPosition(img->sprite);
	struct music	*sound;

	if (pos.y < -950.0f) {
		sound = get_obj(runner, MUSIC);
		sfMusic_stop(sound->music);
		runner->current_screen = MENU;
	}
	sfRenderWindow_drawSprite(runner->window, img->sprite, NULL);
}

void	play_sound(struct game_object *obj, struct game *runner)
{
	struct sound	*sound = (struct sound *)obj->obj;

	(void)runner;
	sfSound_play(sound->sound);
}