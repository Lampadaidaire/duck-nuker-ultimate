/*
** EPITECH PROJECT, 2024
** handle_duck_death
** File description:
** handle duck death
*/
#include "hunter.h"
#include <math.h>
#include "my.h"
#include <stdio.h>

void count_revive_time(duck_t *duck, images_t *image, display_struct_t
    *params)
{
    sfVector2f pos = {rand_frame(250, 1000, &params->last_spawn), 830};

    duck->time_pos += params->game_clock.seconds;
    if (duck->time_pos < 0.1)
        sfSprite_setPosition(image->sprites, pos);
    if (duck->time_pos > 0.1) {
        sfSprite_setScale(image->sprites, (sfVector2f){1, 1});
        sfSprite_setRotation(image->sprites, 0);
        duck->dir = (sfVector2f){5.5 * rand_direction(), -3};
        if (duck->dir.x > 0)
            rev_sprite(image->sprites);
        duck->can_move = 0;
        duck->is_alive = 0;
        duck->time_pos = 0;
        duck->time_spw = 0;
    }
}

void revive_duck(images_t *image, duck_t *duck, display_struct_t *params)
{
    duck_set_rect(image, params->duck_texture);
    count_revive_time(duck, image, params);
}

static void move_rect_death(images_t *image, duck_t *duck, display_struct_t
    *params)
{
    int offset = 8 * 13 * 1.25;
    int max_value = offset * 4;

    if (image->rect.left < max_value - offset && image->rect.top > 132 *
        1.25) {
        image->rect.left += offset + 8 * 3 * 1.25;
        return;
    }
    if (image->rect.left < max_value - offset && image->rect.top == 132 * 1.25)
        image->rect.left += offset;
    else if (image->rect.top == 132 * 1.25) {
        image->rect.left = 0;
        image->rect.top += offset + 8 * 3 * 1.25;
    } else {
        revive_duck(image, duck, params);
    }
}

static void duck_set_rect_death(images_t *images, duck_t *duck,
    display_struct_t *params)
{
    images->rect.left = 24 * 1.25;
    images->rect.top = 132 * 1.25;
    images->rect.width = 112 * 1.25;
    images->rect.height = 112 * 1.25;
    duck->time_sprite = 0;
    if (duck->dir.y > 0) {
        sfSprite_scale(images->sprites, (sfVector2f){-1, 1});
        sfSprite_setRotation(images->sprites, 180 + atanf(duck->dir.x /
            duck->dir.y));
    }
    if (duck->dir.y < 0)
        sfSprite_setRotation(images->sprites, atanf(duck->dir.x /
            duck->dir.y));
    sfSprite_setTexture(images->sprites, params->dead_texture, sfTrue);
    sfSprite_setTextureRect(images->sprites, images->rect);
}

void handle_duck_death(images_t *image, duck_t *duck, display_struct_t *params)
{
    duck->time_sprite += params->game_clock.seconds;
    if (duck->time_sprite > 0.06) {
        move_rect_death(image, duck, params);
        sfSprite_setTextureRect(image->sprites, image->rect);
        duck->time_sprite = 0;
    }
}

void handle_click_death(images_t *image, duck_t *duck, display_struct_t
    *params)
{
    duck->can_move = 1;
    duck->is_alive = 1;
    if (rand_direction() == 1)
        sfSound_play(params->sounds.exploding1);
    else
        sfSound_play(params->sounds.exploding2);
    duck->time_pos = 0;
    duck->time_sprite = 0;
    duck_set_rect_death(image, duck, params);
}
