/*
** EPITECH PROJECT, 2018
** clean_up.c
** File description:
** clean up functions
*/
#include "runner.h"

static void	clean_up_music(struct game *runner)
{
	struct music *sound;

	for (int i = 0; i < SCREEN_SIZE; ++i) {
		runner->current_screen = i;
		if ((sound = get_obj(runner, MUSIC)) != NULL)
			sfMusic_destroy(sound->music);
	}
	sfSound_destroy(runner->sound_effect->sound);
	sfSoundBuffer_destroy(runner->sound_effect->buffer);
}

void	clean_up(struct game *runner)
{
	clean_up_music(runner);
}