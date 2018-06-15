/*
** EPITECH PROJECT, 2017
** my_itoa.c
** File description:
** int to char
*/
#include "my.h"

static int count_num(int i)
{
	int	nb = 0;

	while (i <= -9 || i >= 9) {
		i = i / 10;
		++nb;
	}
	nb += 1;
	return (nb);
}

static char *negate(int nb)
{
	char	*str;
	int 	d = 1;
	int 	i;
	int 	m = 10;

	str = rb_malloc(sizeof(char) * (count_num(nb) + 1));
	str[i = (count_num(nb) + 1)] = '\0';
	i -= 1;
	nb = nb * (-1);
	while (i > 0) {
		str[i] = ((nb % m) / d) + 48;
		m = m * 10;
		d = d * 10;
		i = i - 1;
	}
	str[0] = '-';
	return (str);
}

char *my_itoa(int nb)
{
	int	i;
	int	m = 10;
	int	d = 1;
	char	*str;

	if (nb < -2147483648 || nb > 2147483647)
		rb_xerror("nb is too big for an integer");
	if (nb < 0)
		return (negate(nb));
	str = rb_malloc(sizeof(char) * (count_num(nb)));
	str[i = count_num(nb)] = '\0';
	i -= 1;
	while (i >= 0) {
		str[i] = ((nb % m) / d) + 48;
		m = m * 10;
		d = d * 10;
		i = i - 1;
	}
	return (str);
}