/*
** EPITECH PROJECT, 2017
** my_tab_to_int.c
** File description:
** gets a char tab into int tab
*/
#include "my.h"

int	*my_tab_to_int(char **tab, int ac)
{
	int	i = 1;
	int	j = 0;
	int	*nb = malloc(sizeof(int) * ac);

	while (tab[i] != NULL) {
		nb[j] = my_atoi(tab[i]);
		i++;
		j++;
	}
	return (nb);
}