/*
** EPITECH PROJECT, 2017
** my_memset.c
** File description:
** my_memset function
*/
#include "my.h"

void my_memset(char *str, int size)
{
	for (int i = 0; i < size; ++i) {
		str[i] = 0;
	}
}