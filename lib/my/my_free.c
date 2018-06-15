/*
** EPITECH PROJECT, 2017
** my_free.c
** File description:
** free
*/
#include "my.h"

void	my_free(void *ptr)
{
	if (ptr == NULL)
		rb_xerror("Cannot free NULL pointer");
	free(ptr);
}
