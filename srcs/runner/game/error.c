/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** error handling
*/
#include "runner.h"

int	errors(int ac, char **envp)
{
	if (ac < 2)
		return (84);
	if (envp[0] == NULL) {
		my_print_err("No environment\n");
		return (84);
	}
	return (0);
}