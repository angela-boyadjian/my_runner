/*
** EPITECH PROJECT, 2018
** text.c
** File description:
** functions handling text
*/
#include "runner.h"

void	set_color(struct text *score, int color)
{
	if (color == 1)
		sfText_setColor(score->text, sfRed);
	else if (color == 2)
		sfText_setColor(score->text, sfBlue);
	else
		sfText_setColor(score->text, sfBlack);
}

void	increment_score(struct game_object *obj)
{
	struct text	*score = (struct text *)(obj->obj);

	score->points += 1;
	sfText_setString(score->text, my_itoa(score->points));

}

struct	game_object *init_text(sfVector2f pos, int size, int color, char *text)
{
	struct game_object	*obj;
	struct text		*score;

	obj = create_text("utils/font.ttf", pos, size, color);
	score = (struct text *)obj->obj;
	sfText_setString(score->text, text);
	obj->type = TEXT;
	obj->ptr_move = &move_null;
	obj->ptr_display = &display_text;
	obj->ptr_collide = &col_null;
	return (obj);
}

void	init_points(struct node **head)
{
	struct game_object	*obj;
	struct text		*score;

	obj = create_text("utils/font.ttf", ret_vec(10, 120), 30, 1);
	score = (struct text *)obj->obj;
	sfText_setString(score->text, my_itoa(score->points));
	obj->type = SCORE;
	obj->ptr_move = &increment_score;
	obj->ptr_display = &display_text;
	obj->ptr_collide = &col_null;
	insert_end(head, obj);
}