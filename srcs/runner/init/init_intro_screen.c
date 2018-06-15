/*
** EPITECH PROJECT, 2018
** init_intro_screen.c
** File description:
** init intro screen functions
*/
#include "runner.h"

void	init_intro_screen(struct game *runner)
{
	screen	**head = &((runner->screens)[INTRO]);

	*head = NULL;
	init_music(head, "utils/HexagonForce.ogg");
	init_background_intro(head);
}

void	init_background_intro(struct node **head)
{
	struct game_object *obj;
	struct sprite	*img;

	obj = create_sprite("utils/intro.png", BACKGROUND, 0,
		ret_int_rect(0, 0, 0, 0));
	img = (struct sprite *)obj->obj;
	img->speed.x = 0.0f;
	img->speed.y = -2.0f;
	obj->ptr_move = &move_background;
	obj->ptr_collide = &col_null;
	obj->ptr_display = &display_intro;
	insert_end(head, obj);
}