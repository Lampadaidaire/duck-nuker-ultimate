/*
** EPITECH PROJECT, 2024
** main
** File description:
** main function
*/
#include <SFML/Audio.h>
#include "my.h"
#include "hunter.h"
#include "time.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value - offset) {
        rect->left += offset;
    } else {
        rect->left = 0;
    }
}

/*Struct load image_t order : file, size, origin, images_t, pos*/
void create_images(images_t *images, duck_t *duck, display_struct_t *params)
{
    params->duck_texture = sfTexture_createFromFile("Images/duck.png", NULL);
    params->dead_texture = sfTexture_createFromFile("Images/blood.png", NULL);
    add_background(&images[0], "Images/background.jpg");
    add_duck(&images[1], &duck[0], params);
    params->duck_nbr = 1;
    add_decor(&params->decor[0], "Images/cloud.png");
    add_sign(&params->decor[1], "Images/sign.png");
    add_cursor(&params->decor[2], "Images/cursor.png");
    add_game_over(&params->decor[3], "Images/game_over.png");
    add_bullets(&params->decor[4], "Images/bullet.png");
    add_sec_sign(&params->decor[5], "Images/sign2.png");
    create_pause_images(params);
}

static void load_sounds(display_struct_t *params)
{
    params->sounds.music = sfMusic_createFromFile("Sounds/music.ogg");
    params->sounds.explo_buf1 = sfSoundBuffer_createFromFile(
        "Sounds/blood.ogg");
    params->sounds.explo_buf2 = sfSoundBuffer_createFromFile(
        "Sounds/blood2.ogg");
    params->sounds.lvl_up_buf = sfSoundBuffer_createFromFile(
        "Sounds/lvl_up.ogg");
    params->sounds.exploding1 = sfSound_create();
    params->sounds.exploding2 = sfSound_create();
    params->sounds.lvl_up = sfSound_create();
    sfSound_setBuffer(params->sounds.exploding1, params->sounds.explo_buf1);
    sfSound_setBuffer(params->sounds.exploding2, params->sounds.explo_buf2);
    sfSound_setBuffer(params->sounds.lvl_up, params->sounds.lvl_up_buf);
    sfMusic_setLoop(params->sounds.music, sfTrue);
    sfMusic_play(params->sounds.music);
    sfSound_setVolume(params->sounds.exploding2, 100);
    sfSound_setVolume(params->sounds.exploding2, 60);
    load_sound_second(params);
}

static void lvl_handler(display_struct_t *params)
{
    params->lvl_clock.seconds += params->game_clock.seconds;
    if (params->player.score > params->player.next_lvl && params->lvl < 10 &&
        params->lvl_clock.seconds > 1) {
        params->lvl += 1;
        params->player.next_lvl += 15000 * params->duck_nbr / 2.5 + 9000;
        params->duck_nbr += 1;
        add_duck(&params->images[params->duck_nbr],
            &params->duck[params->duck_nbr - 1], params);
        handle_lvl_txt(params);
        params->lvl_clock.seconds = 0;
    }
}

static void initialize_text(display_struct_t *params)
{
    sfVector2f score_pos = { 110, 825 };
    sfVector2f score_nbr_pos = { 110, 860 };
    sfFont *pixel_font = sfFont_createFromFile("Font/font.ttf");

    params->player.score_text = initialize_universel_text(&(text_t){
        "Score", 30, sfColor_fromRGB(92, 64, 61), pixel_font,
        params->player.score_text, sfTextBold, score_pos});
    params->player.timer = initialize_universel_text(&(text_t){
        get_time(params), 42, sfColor_fromRGB(0, 0, 0), pixel_font,
        params->player.timer, sfTextBold, (sfVector2f){775, 20}});
    params->player.score_nbr_text = initialize_universel_text(&(text_t){
        "0", 30, sfColor_fromRGB(92, 64, 61), pixel_font,
        params->player.score_nbr_text, sfTextBold, score_nbr_pos});
    params->restart_txt = initialize_universel_text(&(text_t){
        "Click to restart", 50, sfColor_fromRGB(255, 255, 255), pixel_font,
        params->restart_txt, sfTextBold, (sfVector2f){590, 730}});
    add_lvl_txt(params);
}

static void print_text(display_struct_t *params)
{
    if (params->player.score < 0)
        params->player.score = 0;
    sfRenderWindow_drawText(params->window, params->player.score_text, NULL);
    sfText_setString(params->player.score_nbr_text, int_to_str(params->
        player.score));
    sfRenderWindow_drawText(params->window, params->player.score_nbr_text,
        NULL);
    sfText_setString(params->player.timer, get_time(params));
    sfRenderWindow_drawText(params->window, params->player.timer, NULL);
    display_lvl_txt(params);
}

static void window_displayer(display_struct_t *params)
{
    while (sfRenderWindow_isOpen(params->window) &&
        params->should_restart == 0 && params->should_exit == 0) {
        while (sfRenderWindow_pollEvent(params->window, &params->event))
            analyse_events(params, params->event);
        sfRenderWindow_clear(params->window, sfWhite);
        params->game_clock.seconds = sfClock_restart(params->
            game_clock.clock).microseconds / 1000000.0;
        handle_cursor(params);
        if (params->nuke.can_display == 0) {
            draw_sprites(params, params->window);
            print_text(params);
        }
        if (params->pause.is_paused == 0)
            draw_paused_image(params);
        handle_duck(params);
        lvl_handler(params);
        handle_end_game(params);
        sfRenderWindow_display(params->window);
    }
    destroyer(params);
}

void initialize_game(display_struct_t *params)
{
    params->game_clock.clock = sfClock_create();
    params->lvl_clock.seconds = 0;
    params->player.score = 0;
    srand(time(0));
    params->player.next_lvl = 5000;
    params->player.amos = 5;
    params->lvl = 1;
    params->is_game_over = 1;
    params->should_exit = 0;
    params->player.twink_nbr = 0;
    params->player.reload_time = 0;
    params->player.time_new_lvl = 0;
    params->game_timer = 0;
    params->should_restart = 0;
    params->pause.is_paused = 1;
    params->orientation = 1;
    params->nuke.nuke_enabled = 1;
    params->nuke.can_display = 0;
    initialize_text(params);
    sfRenderWindow_setMouseCursorVisible(params->window, sfFalse);
}

int start_game(display_struct_t *params)
{
    params->images = malloc(sizeof(images_t) * 16);
    params->duck = malloc(sizeof(duck_t) * 15);
    params->decor = malloc(sizeof(images_t) * 10);
    create_images(params->images, params->duck, params);
    initialize_game(params);
    load_sounds(params);
    window_displayer(params);
    free(params->images);
    free(params->duck);
    free(params->decor);
    if (params->should_restart == 1)
        start_game(params);
    if (params->should_exit == 1)
        start_menu(params);
    return 0;
}
