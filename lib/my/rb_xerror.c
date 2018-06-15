/*
** EPITECH PROJECT, 2017
** rb_xerror.c
** File description:
** xerror
*/
#include "my.h"

int rb_xerror(char *c)
{
	my_print_err("Error: ");
	my_putstr(c);
	my_putchar('\n');
	return (84);
}
