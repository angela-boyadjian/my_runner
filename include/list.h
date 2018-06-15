/*
** EPITECH PROJECT, 2017
** list.h
** File description:
** Header file for linked lists
*/

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>

struct node {
	struct node	*next;
	struct node	*prev;
	void		*data;
};

void	free_list(struct node *list, void (*ptr)(void *data));
void	display_reverse(struct node *head, void (*ptr)(void *data));
void	display_list(struct node *head, void (*ptr)(void *data));
void	my_sort_list(struct node *list, int (*ptr)(void *data, void *data_2));
void	insert_end(struct node **head, void *data);

#endif /* !LIST_H_ */