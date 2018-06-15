/*
** EPITECH PROJECT, 2018
** move.c
** File description:
** move functions
*/
#include "runner.h"

void	go_up(struct node *head)
{
	struct node		*tmp;
	struct game_object	*obj;
	struct	sprite		*img;
	sfVector2f		pos;

	tmp = head;
	do {
		obj = (struct game_object *)tmp->data;
		tmp = tmp->next;
	
	} while (tmp != head && obj->type != SHIP);
	if (obj->type == SHIP) {
		img = (struct sprite *)obj->obj;
		pos = sfSprite_getPosition(img->sprite);
		if (pos.y - 30.0f > -10.0f) {
			if (img->speed.y > -8.0f)
				img->speed.y -= 4.0f;
		}
		if (pos.y - 30.0f < -10.0f)
			img->speed.y = 0.0f;
	}
}

void	move_background(struct game_object *obj)
{
	struct sprite	*img = (struct sprite *)obj->obj;
	sfVector2f	pos = sfSprite_getPosition(img->sprite);

	if (obj->type == BACKGROUND_1 && pos.x < -2949.0f)
		sfSprite_setPosition(img->sprite, ret_vec(0.0f, 2949.0f));
	if (obj->type == BACKGROUND_2 && pos.x < -4000.0f)
		sfSprite_setPosition(img->sprite, ret_vec(0.0f, 4000));
	if (obj->type == BACKGROUND_3 && pos.x < -2048.0f)
		sfSprite_setPosition(img->sprite, ret_vec(150.0f, 2048.0f));
	sfSprite_move(img->sprite, img->speed);
}

void	move_object(struct game_object *obj)
{
	struct sprite	*img = (struct sprite *)obj->obj;

	if (img->nb_anim > 1) {
		sfSprite_setTextureRect(img->sprite,
			img->rect[img->current_anim]);
		if (++(img->current_anim) == img->nb_anim)
			img->current_anim = 0;
	}
	sfSprite_move(img->sprite, img->speed);
}

void	move_ship(struct game_object *obj)
{
	struct sprite	*img = (struct sprite *)obj->obj;
	sfVector2f	pos = sfSprite_getPosition(img->sprite);

	sfSprite_setTextureRect(img->sprite, img->rect[img->current_anim]);
	if (++(img->current_anim) == img->nb_anim)
		img->current_anim = 0;
	sfSprite_move(img->sprite, img->speed);
	if (pos.y + 70.0f < 600.0f) {
		if (img->speed.y < 5.0f)
			img->speed.y += 1.5f;
	}
	if (pos.y + 70.0f > 600.0f)
		img->speed.y = 0.0f;
}

void	move_null(struct game_object *obj)
{
	(void)obj;
}