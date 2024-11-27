/*
** EPITECH PROJECT, 2024
** displayer_struct
** File description:
** displayer_struct
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#ifndef DISPLAYER_STRUCT_H
    #define DISPLAYER_STRUCT_H
typedef struct clocks {
    sfClock *clock;
    sfTime time;
    float seconds;
} clocks_t;
typedef struct images {
    sfIntRect rect;
    sfTexture *textures;
    sfSprite *sprites;
} images_t;
typedef struct duck {
    sfVector2f pos;
    sfVector2f dir;
    float time_sprite;
    float time_pos;
    float time_spw;
    sfRectangleShape *hitbox;
    int can_move;
    int can_escape;
    int time_escape;
    int is_alive;
} duck_t;
typedef struct sounds {
    sfMusic* music;
    sfSoundBuffer *shoot1_buf;
    sfSound* shoot1;
    sfSoundBuffer *quack_buf;
    sfSound* quack;
    sfSoundBuffer *explo_buf1;
    sfSoundBuffer *explo_buf2;
    sfSound* exploding2;
    sfSound* exploding1;
    sfSoundBuffer *lvl_up_buf;
    sfSound *lvl_up;
    sfSoundBuffer *reload_buf;
    sfSound *reload;
} sounds_t;
typedef struct player {
    float score;
    int next_lvl;
    int amos;
    float reload_time;
    sfText *score_text;
    sfText *score_nbr_text;
    sfText *lvl_text;
    float time_new_lvl;
    float time_restart;
    int twink_nbr;
    sfText *timer;
    sfText *lvl_nbr_text;
} player_t;
typedef struct pause {
    int is_paused;
    images_t pause_img;
    images_t resum_img;
    images_t exit_img;
} pause_t;
typedef struct nuke {
    images_t nuke_image;
    sfSoundBuffer *nuke_buf;
    sfSound *nuke_sound;
    sfSound *no_nuke_sound;
    sfSoundBuffer *no_nuke_buf;
    int nuke_enabled;
    int can_display;
} nuke_t;
typedef struct display_struct {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    images_t *images;
    sfTexture *duck_texture;
    sfTexture *dead_texture;
    images_t *decor;
    int duck_nbr;
    int last_spawn;
    int orientation;
    int should_restart;
    int should_exit;
    int is_game_over;
    float game_timer;
    int lvl;
    nuke_t nuke;
    player_t player;
    pause_t pause;
    duck_t *duck;
    sounds_t sounds;
    clocks_t game_clock;
    clocks_t lvl_clock;
    sfText *restart_txt;
    sfText *best_score_txt;
    sfText *bestscore_fix;
    char *bestscore_char;
    int bestscore;
} display_struct_t;
typedef struct text {
    char *str;
    int font_size;
    sfColor color;
    sfFont *font;
    sfText *text;
    sfUint32 style;
    sfVector2f pos;
} text_t;
typedef struct load_image {
    char *file;
    sfVector2f size;
    sfVector2f origin;
    images_t tex_spr;
    sfVector2f pos;
} load_image_t;
typedef struct load_sound {
    char *file;
    sfSoundBuffer *sound_buf;
    sfSound *sound;
} load_sound_t;
#endif
