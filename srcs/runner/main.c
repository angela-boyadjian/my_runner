/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main function
*/
#include "runner.h"

int	main(int ac, char **av, char **envp)
{
	struct game	runner;

	if (errors(ac, envp) == 84 ||
		init_map(&runner, av[1]) == 84)
		return (84);
	init_game(&runner);
	while (sfRenderWindow_isOpen(runner.window)) {
		my_runner(&runner);
	}
	clean_up(&runner);
	return (0);
}