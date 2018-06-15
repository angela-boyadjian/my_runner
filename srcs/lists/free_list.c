/*
** EPITECH PROJECT, 2017
** free_list.c
** File description:
** function to free the list
*/
#include "list.h"

//Frees the list.
void	free_list(struct node *list, void (*ptr)(void *data))
{
	struct node	*tmp = list;

	tmp = tmp->next;
	while (tmp->next != list) {
		ptr(tmp->prev->data);
		free(tmp->prev);
		tmp = tmp->next;
	}
}