/*
** EPITECH PROJECT, 2024
** hunter
** File description:
** hunter
*/
#include <SFML/Audio.h>
#include <SFML/Audio/Types.h>
#include "displayer_struct.h"
#include <SFML/Graphics.h>

#ifndef HUNTER_H
    #define HUNTER_H

display_struct_t create_window(void);
int rand_direction(void);
void get_bestscore(display_struct_t *);
int rand_frame(int, int, int *);
void destroyer(display_struct_t *);
int start_game(display_struct_t *);
void draw_paused_image(display_struct_t *);
int start_menu(display_struct_t *);
void stop_sound(display_struct_t *);
char *get_time(display_struct_t *);
sfText *initialize_universel_text(text_t *);
void menu_destroyer(images_t *, sfMusic *, sfMusic *);
void get_new_bestscore(display_struct_t *);
sfSprite *initialize_universel_image(load_image_t *);
void handle_reload(display_struct_t *);
void add_background(images_t *, char *);
void add_bullets(images_t *, char *);
void add_cursor(images_t *, char *);
void add_decor(images_t *, char *);
void add_duck(images_t *, duck_t *, display_struct_t *);
void load_sound_second(display_struct_t *);
void add_game_over(images_t *, char *);
void add_lvl_txt(display_struct_t *);
void add_sec_sign(images_t *, char *);
void create_pause_images(display_struct_t *);
void handle_pause_clicks(display_struct_t *, sfMouseButtonEvent);
void add_sign(images_t *, char *);
void revive_duck(images_t *, duck_t *, display_struct_t *);
void analyse_events(display_struct_t *, sfEvent);
void basic_events(sfRenderWindow *, sfEvent);
void destroyer(display_struct_t *);
void display_lvl_txt(display_struct_t *);
void display_new_lvl(display_struct_t *);
void draw_sprites(display_struct_t *, sfRenderWindow *);
void duck_set_rect(images_t *, sfTexture *);
void handle_click_death(images_t *, duck_t *, display_struct_t *);
void handle_cursor(display_struct_t *);
void handle_duck_death(images_t *, duck_t *, display_struct_t *);
void handle_duck(display_struct_t *);
void handle_end_game(display_struct_t *);
void do_explosion(display_struct_t *);
void handle_nuke(display_struct_t *);
void handle_lvl_txt(display_struct_t *);
void handle_pause_menu(display_struct_t *);
void images_changer(images_t *, int, int);
void initialize_game(display_struct_t *);
void move_rect(sfIntRect *, int, int);
void rev_sprite(sfSprite *);
#endif /* !HUNTER */
