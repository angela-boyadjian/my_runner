/*
** EPITECH PROJECT, 2017
** sorting_linked_list.c
** File description:
** bubble sort for linked list
*/
#include "list.h"

//Returns the size of the list.
static	int get_size_list(struct node *head)
{
	int		i = 1;
	struct node	*tmp = head;

	if (tmp == NULL)
		return (0);
	while (tmp->next != head) {
		++i;
		tmp = tmp->next;
	}
	return (i);
}

//Swaps the content of two nodes.
static	void my_sort_swap(struct node *node_1, struct node *node_2)
{
	void	*tmp = node_1->data;

	node_1->data = node_2->data;
	node_2->data = tmp;

}

//Bubble sort for linked list.
void	my_sort_list(struct node *list, int (*ptr)(void *data, void *data_2))
{
	int		i;
	int	 	size = get_size_list(list);
	int		swap = 1;
	struct node	*tmp;

	while (swap != 0) {
		swap = 0;
		i = 0;
		tmp = list;
		while (tmp->next != list && i + 1 < size) {
			if (ptr(tmp->data, tmp->next->data) == 1) {
				my_sort_swap(tmp, tmp->next);
				++swap;
			}
			tmp = tmp->next;
			++i;
		}
	}
}