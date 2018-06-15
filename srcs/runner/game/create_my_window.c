/*
** EPITECH PROJECT, 2018
** create_my_window.c
** File description:
** function to create the window
*/
#include "runner.h"

sfRenderWindow	*create_my_window(int width, int height)
{
	sfRenderWindow	*window;
	sfVideoMode	video_mode;

	video_mode.width = width;
	video_mode.height = height;
	video_mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(video_mode, "MY_RUNNER",
		sfDefaultStyle, NULL);
	return (window);
}