/*
** EPITECH PROJECT, 2018
** init_menu.c
** File description:
** init_menu fonctions
*/
#include "runner.h"

struct	game_object *init_button(char *path, sfVector2f pos,
	enum obj_type type, sfVector2f scale)
{
	struct game_object *obj;
	struct sprite	*img;

	obj = create_sprite(path, type, 0, ret_int_rect(0, 0, 0, 0));
	img = (struct sprite *)obj->obj;
	sfSprite_setScale(img->sprite, scale);
	sfSprite_setPosition(img->sprite, pos);
	obj->ptr_move = &move_null;
	obj->ptr_collide = &col_null;
	obj->ptr_display = &display_sprite;
	return (obj);
}

void	init_menu_screen(struct game *runner)
{
	screen	**head = &((runner->screens)[MENU]);

	*head = NULL;
	init_parallax(head);
	init_music(head, "utils/menuLoop.ogg");
	insert_end(head, init_button("utils/button.png",
		ret_vec(350.0f, 500.0f), PLAY, ret_vec(0.15f, 0.15f)));
	insert_end(head, init_button("utils/button.png", ret_vec(30.0f, 30.0f),
		HELP_BUTTON, ret_vec(0.15f, 0.15f)));
	insert_end(head, init_button("utils/button.png",
		ret_vec(500.0f, 500.0f), EXIT, ret_vec(0.15f, 0.15f)));
	insert_end(head, init_button("utils/title.png", ret_vec(10.0f, 440.0f),
		TITLE, ret_vec(0.55f, 0.55f)));
	insert_end(head, init_text(ret_vec(110, 520), 50, 3, "runner"));
	insert_end(head, init_text(ret_vec(370, 570), 40, 3, "play"));
	insert_end(head, init_text(ret_vec(520, 570), 40, 3, "exit"));
	insert_end(head, init_text(ret_vec(50, 100), 40, 3, "help"));
}