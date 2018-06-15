/*
** EPITECH PROJECT, 2018
** init_game.c
** File description:
** init game function
*/
#include "runner.h"

void	init_parallax(struct node **head)
{
	insert_end(head, init_background(ret_vec(0, 0), "utils/background.png",
		ret_vec(0, -0.5f), BACKGROUND_1));
	insert_end(head, init_background(ret_vec(0, 0), "utils/planets.png",
		ret_vec(0, -1.5f), BACKGROUND_2));
	insert_end(head, init_background(ret_vec(150, 0),
		"utils/asteroids.png", ret_vec(0, -3.5f), BACKGROUND_3));
	insert_end(head, init_background(ret_vec(0, 2949),
		"utils/background.png", ret_vec(0, -0.5f), BACKGROUND_1));
	insert_end(head, init_background(ret_vec(0, 4000), "utils/planets.png",
		ret_vec(0, -1.5f), BACKGROUND_2));
	insert_end(head, init_background(ret_vec(150, 2048),
		"utils/asteroids.png", ret_vec(0, -3.5f), BACKGROUND_3));
}

void	init_game_screen(struct game *runner)
{
	screen	**head = &((runner->screens)[GAME]);

	*head = NULL;
	runner->sound_effect = malloc(sizeof(*(runner->sound_effect)));
	runner->sound_effect->buffer =
		sfSoundBuffer_createFromFile("utils/explode.ogg");
	runner->sound_effect->sound = sfSound_create();
	sfSound_setBuffer(runner->sound_effect->sound,
		runner->sound_effect->buffer);
	init_parallax(head);
	init_player(head);
	insert_end(head, init_text(ret_vec(10, 10), 30, 1, "score: "));
	init_points(head);
	init_music(head, "utils/BackOnTrack.ogg");
}

void	init_pause_screen(struct game *runner)
{
	screen	**head = &((runner->screens)[PAUSE]);

	*head = NULL;
	insert_end(head, init_text(ret_vec(300, 500), 60, 2, "pause"));
}

void	init_game(struct game *runner)
{
	runner->window = create_my_window(1200, 600);
	sfRenderWindow_setFramerateLimit(runner->window, 80);
	runner->clock = sfClock_create();
	sfRenderWindow_setMouseCursorVisible(runner->window, sfTrue);
	runner->current_screen = INTRO;
	init_game_screen(runner);
	init_menu_screen(runner);
	init_defeat_screen(runner);
	init_pause_screen(runner);
	init_help_screen(runner);
	init_intro_screen(runner);
	init_obstacles(runner);
	init_victory_screen(runner);
}