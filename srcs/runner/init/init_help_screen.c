/*
** EPITECH PROJECT, 2018
** init_help_screen.c
** File description:
** help screen functions
*/
#include "runner.h"

void	init_help_screen(struct game *runner)
{
	screen	**head = &((runner->screens)[HELP]);

	*head = NULL;
	init_help_background(head);
	insert_end(head, init_button("utils/button.png",
	ret_vec(500.0f, 960.0f), BACK, ret_vec(0.15f, 0.15f)));
	insert_end(head, init_text(ret_vec(520, 1020), 40, 3, "back"));
}

void	init_help_background(struct node **head)
{
	struct game_object *obj;

	obj = create_sprite("utils/help_background.png",
		BACKGROUND, 0, ret_int_rect(0, 0, 0, 0));
	obj->ptr_move = &move_null;
	obj->ptr_collide = &col_null;
	obj->ptr_display = &display_sprite;
	insert_end(head, obj);
}