/*
** EPITECH PROJECT, 2017
** my_str_to_wordarray_delim.c
** File description:
** str_to_wordarray with a delim as argument
*/
#include "my.h"

static int	delim_words(char *str, char delim)
{
	int	result = 0;

	for (int i = 0; str[i]; ++i) {
		if (str[i] && str[i] != delim) {
			result++;
			while (str[i] && str[i] != delim)
				i++;
		}
		if (!str[i])
			break;
	}
	return (result);
}

static int	l_words(char *str, char delim)
{
	int	count = 0;

	for (int i = 0; str[i] != delim && str[i]; ++i)
		count++;
	return (count);
}

char	**my_str_to_wordtab_delim(char *str, char delim)
{
	char	**tab;
	int	nb = delim_words(str, delim);
	int	i = 0;
	int	j = 0;
	int	count = 0;

	tab = malloc(sizeof(char *) * (nb + 1));
	if (tab == NULL)
		return (NULL);
	while (j < nb) {
		while (str[i] == delim)
			i++;
		count = 0;
		tab[j] = malloc(sizeof(char) * (l_words(str + i, delim) + 1));
		while (str[i] != delim && str[i])
			tab[j][count++] = str[i++];
		tab[j++][count] = '\0';
	}
	tab[j] = NULL;
	return (tab);
}