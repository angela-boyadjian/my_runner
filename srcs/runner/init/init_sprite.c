/*
** EPITECH PROJECT, 2018
** init_sprite.c
** File description:
** init sprite functions
*/
#include "runner.h"

void	init_missile(struct node **head, sfVector2f pos)
{
	struct game_object	*obj;
	struct sprite		*img;

	obj = create_sprite("utils/missile.png", OBSTACLE, 4,
		ret_int_rect(0, 350, 350, 80));
	img = (struct sprite *)obj->obj;
	sfSprite_setScale(img->sprite, ret_vec(0.5f, 0.5f));
	sfSprite_setPosition(img->sprite, pos);
	sfSprite_setTextureRect(img->sprite, img->rect[0]);
	img->speed = ret_vec(0.0f, -5.5f);
	obj->ptr_move = &move_object;
	obj->ptr_display = &display_sprite;
	obj->ptr_collide = &col_obstacle;
	insert_end(head, obj);
}

void	init_player(struct node **head)
{
	struct game_object	*obj;
	struct sprite		*img;

	obj = create_sprite("utils/ship2.png", SHIP, 16,
		ret_int_rect(0, 63, 63, 60));
	img = (struct sprite *)obj->obj;
	sfSprite_setPosition(img->sprite, ret_vec(250.0f, 100.0f));
	sfSprite_setTextureRect(img->sprite, img->rect[0]);
	img->speed.x = 0.0f;
	img->speed.y = -0.3f;
	obj->ptr_move = &move_ship;
	obj->ptr_display = &display_sprite;
	obj->ptr_collide = &col_player;
	insert_end(head, obj);
}

struct game_object *init_background(sfVector2f pos, char *path,
	sfVector2f speed, enum obj_type type)
{
	struct game_object *obj;
	struct sprite	*img;

	obj = create_sprite(path, type, 0, ret_int_rect(0, 0, 0, 0));
	img = (struct sprite *)obj->obj;
	sfSprite_setPosition(img->sprite, pos);
	if (type == BACKGROUND_3)
		sfSprite_setScale(img->sprite, ret_vec(0.5f, 0.5f));
	img->speed = speed;
	obj->ptr_move = &move_background;
	obj->ptr_collide = &col_null;
	obj->ptr_display = &display_sprite;
	return (obj);
}