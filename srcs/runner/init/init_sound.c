/*
** EPITECH PROJECT, 2018
** init_sound.c
** File description:
** init sound functions
*/
#include "runner.h"

// For later use
void	init_sound(struct node **head, char *path)
{
	struct game_object	*obj;

	obj = create_sound(path);
	obj->ptr_move = &move_null;
	obj->ptr_collide = &col_null;
	obj->ptr_display = &play_sound;
	insert_end(head, obj);
}

void	init_music(struct node **head, char *path)
{
	struct game_object	*obj;

	obj = create_music(path);
	obj->ptr_move =	&move_null;
	obj->ptr_collide = &col_null;
	obj->ptr_display = &play_music;
	insert_end(head, obj);
}