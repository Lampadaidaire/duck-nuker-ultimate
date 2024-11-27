/*
** EPITECH PROJECT, 2024
** analys_events
** File description:
** analyse event
*/
#include <SFML/Audio.h>
#include "my.h"
#include <unistd.h>
#include "hunter.h"
#include <SFML/Audio/Types.h>
#include "stdio.h"
#include <SFML/Graphics.h>

void basic_events(sfRenderWindow * window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

static void handle_bullets(display_struct_t *params, int hit_duck)
{
    if (hit_duck == 0) {
        move_rect(&params->decor[4].rect, 110, 660);
        sfSprite_setTextureRect(params->decor[4].sprites,
            params->decor[4].rect);
    } else
        params->player.amos += 1;
}

static void change_dir(duck_t *duck, images_t *image, display_struct_t *params)
{
    int new_y = 1;
    int new_x = rand_direction();

    if (duck->time_spw > 2.4)
        new_y = rand_direction();
    else
        params->orientation = 1;
    duck->dir = (sfVector2f){duck->dir.x * new_x * params->orientation,
        duck->dir.y * new_y * params->orientation};
    if (new_x * params->orientation == -1)
        sfSprite_scale(image->sprites, (sfVector2f){-1, 1});
    params->orientation *= -1;
}

static int check_if_hit(display_struct_t *params, sfMouseButtonEvent event,
    int hit_duck, int i)
{
    sfVector2u size = sfRenderWindow_getSize(params->window);
    float coef_x = (float)size.x / 1664;
    float coef_y = (float)size.y / 936;

    if (event.x <= (params->duck[i].pos.x + 60) * coef_x &&
        event.x >= (params->duck[i].pos.x - 60) * coef_x &&
        event.y <= (params->duck[i].pos.y + 50) * coef_y &&
        event.y >= (params->duck[i].pos.y - 45) * coef_y &&
        params->duck[i].can_move == 0 && params->pause.is_paused == 1) {
        hit_duck = 1;
        handle_click_death(&params->images[i + 1], &params->duck[i],
            params);
        params->player.score += 2000 / params->duck[i].time_spw + 450;
    } else if (params->duck->time_spw < 9)
        change_dir(&params->duck[i], &params->images[i + 1], params);
    if (params->player.score < 0)
        params->player.score = 0;
    return hit_duck;
}

void manage_left_click(display_struct_t *params, sfMouseButtonEvent event)
{
    int hit_duck = 0;

    sfSound_play(params->sounds.shoot1);
    params->player.score -= 50;
    params->player.amos -= 1;
    for (int i = 0; i < params->duck_nbr; i++) {
        hit_duck = check_if_hit(params, event, hit_duck, i);
    }
    handle_bullets(params, hit_duck);
}

void manage_mouse_click(sfMouseButtonEvent event, display_struct_t *params)
{
    if (event.button == sfMouseLeft && params->player.amos > 0 &&
        params->pause.is_paused == 1 && params->is_game_over == 1) {
        manage_left_click(params, event);
    }
    if (event.button == sfMouseLeft && params->is_game_over == 0 &&
        params->game_timer > 181) {
        params->should_restart = 1;
        params->game_timer = 0;
    }
    if (event.button == sfMouseLeft && params->pause.is_paused == 0)
        handle_pause_clicks(params, event);
    if (event.button == sfMouseRight && params->pause.is_paused == 1
        && params->is_game_over == 1)
        handle_nuke(params);
}

void analyse_events(display_struct_t *params, sfEvent event)
{
    basic_events(params->window, event);
    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, params);
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape &&
        params->is_game_over == 1)
        handle_pause_menu(params);
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyR &&
        params->is_game_over == 1 && params->pause.is_paused == 1 && params->
        player.amos != 5)
        handle_reload(params);
}
