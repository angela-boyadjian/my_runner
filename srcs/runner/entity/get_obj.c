/*
** EPITECH PROJECT, 2018
** get_obj.c
** File description:
** function to get obj
*/
#include "runner.h"

void	*get_obj(struct game *runner, enum obj_type type)
{
	struct node *head = runner->screens[runner->current_screen];
	struct node *tmp = head;
	struct game_object	*obj;

	do {
		obj = (struct game_object *)tmp->data;
		if (obj->type == type)
			return (obj->obj);
		tmp = tmp->next;
	} while (tmp != head);
	return (NULL);
}