/*
** EPITECH PROJECT, 2018
** init_victory_screen.c
** File description:
** int functions
*/
#include "runner.h"

static void	init_victory_bg(struct node **head)
{
	struct game_object *obj;

	obj = create_sprite("utils/victory.jpg", BACKGROUND, 0,
		ret_int_rect(0, 0, 0, 0));
	obj->ptr_move = &move_null;
	obj->ptr_collide = &col_null;
	obj->ptr_display = &display_sprite;
	insert_end(head, obj);
}

void	init_victory_screen(struct game *runner)
{
	screen	**head = &((runner->screens)[VICTORY]);

	*head = NULL;
	init_victory_bg(head);
	insert_end(head, init_text(ret_vec(300, 380), 50, 2,
		"you're awesome !"));
}