/*
** EPITECH PROJECT, 2018
** math.c
** File description:
** math functions
*/
#include "runner.h"

bool	check_click(sfFloatRect *rect, float x, float y)
{
	if (sfFloatRect_contains(rect, x, y) == sfTrue)
		return (true);
	return (false);
}

bool	get_click(struct game_object *obj, float x, float y)
{
	struct sprite	*img = (struct sprite *)obj->obj;
	sfFloatRect	rect = sfSprite_getGlobalBounds(img->sprite);

	if (check_click(&rect, x, y) == true)
		return (true);
	return (false);
}

sfIntRect	ret_int_rect(float top, float left, float width, float height)
{
	sfIntRect	rect;

	rect.top = top;
	rect.left = left;
	rect.width = width;
	rect.height = height;
	return (rect);
}

sfVector2f	ret_vec(float y, float x)
{
	sfVector2f	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}