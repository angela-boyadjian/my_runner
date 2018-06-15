/*
** EPITECH PROJECT, 2018
** init_defeat_screen.c
** File description:
** init defeate screen functions
*/
#include "runner.h"

void	init_background_defeat(struct node **head)
{
	struct game_object *obj;

	obj = create_sprite("utils/menu_back.jpg", BACKGROUND, 0,
		ret_int_rect(0, 0, 0, 0));
	obj->ptr_move = &move_null;
	obj->ptr_collide = &col_null;
	obj->ptr_display = &display_sprite;
	insert_end(head, obj);
}

void	init_defeat_screen(struct game *runner)
{
	screen	**head = &((runner->screens)[DEFEAT]);

	*head = NULL;
	init_background_defeat(head);
	insert_end(head, init_text(ret_vec(300, 480), 50, 1, "you suck !"));
}