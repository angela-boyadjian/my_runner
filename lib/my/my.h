/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header lib
*/
#ifndef MY_H_
# define MY_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <sys/sysmacros.h>
#include <stdbool.h>
#include <dirent.h>
#include <time.h>
#include "printf.h"

char	**my_str_to_wordtab_delim(char *str, char delim);
int	my_printf(char const *str, ...);
void	my_memset(char *str, int size);
void	my_putchar(char);
void	my_swap(int *, int *);
void	my_sort_int_array(int *, int);
void	my_free(void *);
void	my_print_err(char *);
void	*rb_malloc(int);
void	my_putstr(char const *);
int	my_isneg(int);
int	my_put_nbr(int);
int	my_strlen(char const *);
int	my_strarraylen(char **);
int	rb_xerror(char *);
int	my_getnbr(char const *);
int	my_compute_power_rec(int, int);
int	my_compute_square_root(int);
int	my_is_prime(int);
int	my_find_prime_sup(int);
int	my_strcmp(char const *, char const *);
int	my_strncmp(char const *, char const *, int);
int	my_str_isalpha(char const *);
int	my_str_isupper(char const *);
int	my_str_isnum(char const *);
int	my_str_islower(char const *);
int	my_str_isprintable(char const *);
int	my_putnbr_base(int, char const *);
int	my_showstr(char const *);
int	my_showmem(char const *, int);
int	my_show_word_array(char * const *);
int     my_atoi(char *);
char	*my_strcpy(char *, char const *);
char	*my_strncpy(char *, char const *, int);
char	*my_revstr(char *);
char	*my_strstr(char *, char const*);
char	*my_strupcase(char *);
char	*my_strlowcase(char *);
char	*my_strcapitalize(char *);
char	*my_strcat(char *, char const *);
char	*my_strncat(char *, char const *, int);
char	*my_itoa(int);
int	my_char_is_num(char c);
char	*my_strdup(char const*);
char	*my_strndup(char const*, int n);
int	my_char_is_alphanum(char c);
int	*my_tab_to_int(char **tab, int ac);
int	*my_realloc_nb(int *nb, int size);

#endif