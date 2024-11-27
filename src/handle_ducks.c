/*
** EPITECH PROJECT, 2024
** handle_duck
** File description:
** handle_duck
*/
#include <SFML/Audio.h>
#include "my.h"
#include "hunter.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

void images_changer(images_t *images, int x, int y)
{
    move_rect(&images->rect, x, y);
    sfSprite_setTextureRect(images->sprites, images->rect);
}

static void count_duck_time(duck_t *duck, images_t *image, display_struct_t
    *params)
{
    duck->time_sprite += params->game_clock.seconds;
    if (duck->time_sprite > 0.12) {
        images_changer(image, 115, 916);
        duck->time_sprite = 0;
    }
}

void handle_escape(display_struct_t *params, duck_t *duck)
{
    duck->time_pos += params->game_clock.seconds;
    duck->time_spw += params->game_clock.seconds;
    if (duck->time_pos > 2 / params->lvl + 0.8) {
        duck->can_escape = 1;
    } else
        duck->can_escape = 0;
    if (duck->time_spw > 9)
        duck->time_escape = 1;
    else
        duck->time_escape = 0;
    if (duck->time_spw > 9 && (duck->pos.x > 1700 || duck->pos.x < -20) &&
        (duck->pos.y > 900 || duck->pos.y < 20)) {
            sfSound_play(params->sounds.quack);
            duck->can_move = 1;
            duck->is_alive = 1;
            duck->time_pos = 0;
            duck->time_sprite = 0;
        params->player.score -= 1000;
    }
}

void move_duck(duck_t *duck, images_t *images, display_struct_t *params)
{
    sfVector2f dir = duck->dir;
    sfVector2f move_dir = dir;

    dir.x *= (1 + (float)params->lvl * 0.2);
    dir.y *= (1 + (float)params->lvl * 0.2);
    duck->pos = sfSprite_getPosition(images->sprites);
    if ((duck->pos.x > 1544 || duck->pos.x < 110) && duck->time_escape == 0) {
        dir.x *= -1;
        rev_sprite(images->sprites);
    }
    handle_escape(params, duck);
    if ((duck->pos.y > 710 || duck->pos.y < 55) && duck->can_escape == 1 &&
    duck->time_escape == 0) {
        dir.y *= -1;
    }
    duck->dir.x = dir.x / (1 + (float)params->lvl * 0.2);
    duck->dir.y = dir.y / (1 + (float)params->lvl * 0.2);
    move_dir.x = dir.x * params->game_clock.seconds * 60;
    move_dir.y = dir.y * params->game_clock.seconds * 60;
    sfSprite_move(images->sprites, move_dir);
}

void handle_duck(display_struct_t *params)
{
    for (int i = 0; i < params->duck_nbr; i++) {
        if (params->pause.is_paused == 0)
            break;
        if (params->duck[i].can_move == 0 && params->is_game_over == 1) {
            move_duck(&params->duck[i], &params->images[i + 1], params);
            count_duck_time(&params->duck[i], &params->images[i + 1], params);
        }
        if (params->duck[i].is_alive == 1)
            handle_duck_death(&params->images[i + 1], &params->duck[i],
                params);
    }
}
