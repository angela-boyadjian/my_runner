/*
** EPITECH PROJECT, 2017
** realloc_nb.c
** File description:
** reallocs an int
*/
#include "my.h"

int	*my_realloc_nb(int *nb, int size)
{
	int	*new;

	new = rb_malloc(sizeof(char) * (size + 1));
	new = nb;
	my_free(nb);
	return (new);
}
