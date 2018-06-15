/*
** EPITECH PROJECT, 2017
** display_list.c
** File description:
** displas list
*/
#include "list.h"

//Displays the list.
void	display_list(struct node *head, void (*ptr)(void *data))
{
	struct node	*tmp = head;

	do {
		ptr(tmp->data);
		tmp = tmp->next;
	} while (tmp != head);
}

//Displays the list in reverse order.
void	display_reverse(struct node *head, void (*ptr)(void *data))
{
	struct node	*tmp = head->prev;

	do {
		ptr(tmp->data);
		tmp = tmp->prev;
	} while (tmp != head);
}