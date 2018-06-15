/*
** EPITECH PROJECT, 2017
** my_strisalphanum.c
** File description:
** checks if char is alphanum
*/
#include "my.h"

int	is_alphanum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
	(c >= '0' && c <= '9'))
		return (1);
	return (0);
}