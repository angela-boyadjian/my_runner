/*
** EPITECH PROJECT, 2018
** map.c
** File description:
** map handling
*/
#include "runner.h"

char	**read_map(char const *filename)
{
	FILE	*file;
	char	*buffer = NULL;
	size_t	bufsize = 0;
	char 	**tab = malloc(sizeof(char *) * OBJ_MAX);
	int	i;

	file = fopen(filename, "r");
	if (file == NULL)
		return (NULL);
	for (i = 0; getline(&buffer, &bufsize, file) != -1; ++i) {
		tab[i] = buffer;
		if (tab[i][my_strlen(tab[i]) - 1] == '\n')
			tab[i][my_strlen(tab[i]) - 1] = 0;
		buffer = NULL;
		bufsize = 0;
	}
	tab[i] = 0;
	fclose(file);
	return (tab);
}

static void	free_wordtab(char **tab)
{
	for (int i = 0; tab[i]; ++i)
		free(tab[i]);
	free(tab);
}

struct map	*parse_map(char **map)
{
	char		**obj;
	struct map	*tab = malloc(sizeof(*tab) * my_strarraylen(map) + 1);
	int		i;

	for (i = 0; map[i]; ++i) {
		obj = my_str_to_wordtab_delim(map[i], ';');
		tab[i].type = my_getnbr(obj[0]);
		tab[i].y = my_getnbr(obj[1]);
		tab[i].x = my_getnbr(obj[2]);
		free_wordtab(obj);
	}
	tab[i].type = LAST;
	return (tab);
}

void	init_obstacles(struct game *runner)
{
	struct node *head = runner->screens[GAME];

	for (int i = 0; (runner->tab[i]).type != LAST; ++i) {
		init_missile(&head, ret_vec((runner->tab[i]).y,
			(runner->tab[i]).x));
	}
}

int	init_map(struct game *runner, char *str)
{
	char	**tab;

	tab = read_map(str);
	if (tab == NULL)
		return (84);
	runner->tab = parse_map(tab);
	return (0);
}