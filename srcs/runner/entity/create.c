/*
** EPITECH PROJECT, 2018
** create.c
** File description:
** create functions
*/
#include "runner.h"

struct game_object *create_sound(char *path)
{
	struct game_object *obj = malloc(sizeof(*obj));
	struct sound		*sound = malloc(sizeof(*sound));

	sound->buffer = sfSoundBuffer_createFromFile(path);
	obj->type = SOUND;
	sound->sound = sfSound_create();
	sfSound_setBuffer(sound->sound, sound->buffer);
	obj->obj = sound;
	return (obj);
}

struct game_object *create_music(char *path)
{
	struct game_object	*obj = malloc(sizeof(*obj));
	struct music		*sound = malloc(sizeof(*sound));

	sound->music = sfMusic_createFromFile(path);
	obj->type = MUSIC;
	sfMusic_setLoop(sound->music, sfTrue);
	obj->obj = sound;
	return (obj);
}

struct game_object *create_text(char *path, sfVector2f pos, int size, int color)
{
	struct game_object	*obj = malloc(sizeof(*obj));
	struct text		*score = malloc(sizeof(*score));

	score->font = sfFont_createFromFile(path);
	score->text = sfText_create();
	score->text_pos = pos;
	score->points = 0;
	sfText_setFont(score->text, score->font);
	sfText_setCharacterSize(score->text, size);
	set_color(score, color);
	sfText_setPosition(score->text, score->text_pos);
	obj->obj = score;
	return (obj);
}

void	create_rect_tab(struct sprite *obj, sfIntRect size)
{
	float	save = size.left;

	for (int i = 0; i < obj->nb_anim; ++i) {
		(((obj->rect)[i]).left) = size.left - save;
		(((obj->rect)[i]).top) = size.top;
		(((obj->rect)[i]).width) = size.width;
		(((obj->rect)[i]).height) = size.height;
		size.left += save;
	}
}

struct game_object	*create_sprite(char const *path_to_spritesheet,
	enum obj_type type, int nb_anim, sfIntRect size)
{
	struct sprite		*obj = malloc(sizeof(*obj));
	struct game_object	*ret = malloc(sizeof(*ret));

	ret->type = type;
	obj->sprite = sfSprite_create();
	obj->texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
	obj->nb_anim = nb_anim;
	obj->current_anim = 0;
	if (nb_anim > 0) {
		obj->rect = malloc(sizeof(*(obj->rect)) * nb_anim);
		create_rect_tab(obj, size);
	}
	sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
	ret->obj = obj;
	return (ret);
}