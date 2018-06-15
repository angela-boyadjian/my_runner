/*
** EPITECH PROJECT, 2017
** runner.h
** File description:
** runner header file
*/
#ifndef RUNNER_H_
#define RUNNER_H_

#include "my.h"
#include "menu.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <stddef.h>
#include "list.h"
typedef struct node screen;
typedef struct node obj_list;

#define OBJ_MAX 200

enum obj_type {
	SHIP,
	OBSTACLE,
	BACKGROUND,
	BACKGROUND_1,
	BACKGROUND_2,
	BACKGROUND_3,
	TITLE,
	SCORE,
	PLAY,
	EXIT,
	BACK,
	HELP_BUTTON,
	TEXT,
	MUSIC,
	SOUND,
	LAST
};

enum screen_type {
	INTRO,
	MENU,
	GAME,
	VICTORY,
	DEFEAT,
	PAUSE,
	HELP,
	SCREEN_SIZE
};

struct	music {
	sfMusic		*music;
};

struct sound {
	sfSoundBuffer	*buffer;
	sfSound		*sound;
};

struct	text {
	sfText		*text;
	sfVector2f	text_pos;
	sfFont		*font;
	char		*string;
	int		points;
};

struct	sprite {
	sfSprite	*sprite;
	sfVector2f	speed;
	sfTexture	*texture;
	sfIntRect	*rect;
	int		current_anim;
	int		nb_anim;
};

struct map {
	enum obj_type	type;
	float		y;
	float		x;
};

struct game {
	screen		*screens[SCREEN_SIZE];
	enum screen_type current_screen;
	sfClock		*clock;
	sfRenderWindow	*window;
	struct sound	*sound_effect;
	struct map	*tab;
};

struct game_object {
	void		*obj;
	enum obj_type	type;
	void		(*ptr_move)(struct game_object *obj);
	int		(*ptr_collide)(struct game_object *obj,
		struct node *head, struct game *runner);
	void		(*ptr_display)(struct game_object *obj,
	struct game *runner);
};

// Initialisation
void			init_player(struct node **head);
void			init_missile(struct node **head, sfVector2f pos);
void			init_game(struct game *runner);
void			init_menu(struct node **head, struct game *runner);
void			init_music(struct node **head, char *path);
void			increment_score(struct game_object *obj);
struct game_object	*init_text(sfVector2f pos, int size,
	int color, char *text);
void			init_points(struct node **head);
void			set_obstacle(struct node **head, float y, float x);
void			writing(struct game *runner, sfRenderWindow *window);
struct			game_object *init_button(char *path, sfVector2f pos,
			enum obj_type type, sfVector2f scale);
void			init_background_defeat(struct node **head);
void			init_defeat_screen(struct game *runner);
void			init_pause_screen(struct game *runner);
void			init_help_screen(struct game *runner);
void			init_help_background(struct node **head);
void			init_background_intro(struct node **head);
void			init_intro_screen(struct game *runner);
void			init_obstacles(struct game *runner);
void			init_victory_screen(struct game *runner);
struct game_object	*init_background(sfVector2f pos, char *path,
			sfVector2f speed, enum obj_type type);
void			init_parallax(struct node **head);
void			init_menu_screen(struct game *runner);


// Create
sfRenderWindow		*create_my_window(int width, int height);
struct game_object	*create_object(char const *path_to_spritesheet,
	sfVector2f pos, sfIntRect rect, enum obj_type type);
struct game_object	*create_text(char *path, sfVector2f pos,
	int size, int color);
struct menu		*create_menu(char *path, sfVector2f pos,
	sfIntRect rect);
struct game_object 	*create_music(char *path);
struct game_object	*create_sprite(char const *path_to_spritesheet,
			enum obj_type type, int nb_anim, sfIntRect size);
struct game_object	*create_sound(char *path);

// Move
void			move_background(struct game_object * obj);
void			move_ship(struct game_object *obj);
void			move_null(struct game_object *obj);
void			move_object(struct game_object *obj);

// Display
void			display_sprite(struct game_object *obj,
	struct game *runner);
void			display_text(struct game_object *obj,
	struct game *runner);
void			play_music(struct game_object *obj,
	struct game *runner);
void			set_color(struct text *score, int color);
void			play_sound(struct game_object *obj,
	struct game *runner);
void			display_intro(struct game_object *obj,
	struct game *runner);

// Collide
int			collide(struct game_object *obj, struct node *head,
	struct game *runner);
int			col_obstacle(struct game_object *obj, struct node *head,
	struct game *runner);
int			col_player(struct game_object *obj, struct node *head,
	struct game *runner);
int			col_null(struct game_object *obj, struct node *head,
	struct game *runner);

// Events
void			go_up(struct node *head);
int			handle_event(struct game *runner);
int			analyse_event(struct game *runner, sfEvent event);
bool			get_click(struct game_object *obj, float x, float y);
void			*get_obj(struct game *runner, enum obj_type type);
void			check_victory(struct game *runner);
int			check_event(struct game *runner, sfEvent event,
			sfKeyCode key, int (*ptr)(struct game *));
int			key_space(struct game *runner);
int			key_r(struct game *runner);
int			key_p(struct game *runner);
int			key_m(struct game *runner);
int			check_play(struct game *runner,
			struct game_object *obj, sfMouseButtonEvent event);
int			check_exit(struct game *runner,
			struct game_object *obj, sfMouseButtonEvent event);
int			check_help(struct game *runner,
			struct game_object *obj, sfMouseButtonEvent event);
int			check_back(struct game *runner,
			struct game_object *obj, sfMouseButtonEvent event);

// Maths
sfVector2f		ret_vec(float y, float x);
sfIntRect		ret_int_rect(float top, float left,
			float width, float height);

// Clean-up
void			destroy_object(struct game_object *obj);
void			end_game(sfRenderWindow *window, struct game *runner);
void			reset_game(struct game *runner);
void			clean_up(struct game *runner);

// Main loop
int			my_runner(struct game *runner);
int			menu(sfRenderWindow *window, struct node *head,
			struct game *runner);

// Map
char		**read_map(char const *filename);
struct map	*parse_map(char **tab);
int		init_map(struct game *runner, char *str);

// Error
int	errors(int ac, char **envp);

#endif /* !RUNNER_H_ */