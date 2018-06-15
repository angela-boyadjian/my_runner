/*
** EPITECH PROJECT, 2017
** rb_malloc.c
** File description:
** malloc function
*/
#include "my.h"

void	*rb_malloc(int size)
{
	void	*str = malloc(size);

	if (str == NULL)
		return (NULL);
	return (str);
}