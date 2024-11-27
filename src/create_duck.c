/*
** EPITECH PROJECT, 2024
** create duck
** File description:
** add duck
*/
#include <SFML/Audio.h>
#include "my.h"
#include "hunter.h"
#include <SFML/Graphics.h>


void duck_set_rect(images_t *images, sfTexture *duck_texture)
{
    images->rect.left = 0;
    images->rect.top = 0;
    images->rect.width = 110;
    images->rect.height = 110;
    sfSprite_setTexture(images->sprites, duck_texture, sfTrue);
    sfSprite_setTextureRect(images->sprites, images->rect);
}

static void set_duck_properties(duck_t *duck)
{
    duck->can_move = 0;
    duck->is_alive = 0;
    duck->can_escape = 0;
    duck->time_pos = 0;
    duck->time_sprite = 0;
    duck->time_spw = 0;
    duck->time_escape = 0;
    duck->can_move = 0;
    duck->is_alive = 0;
    duck->can_escape = 0;
}

void add_duck(images_t *images, duck_t *duck, display_struct_t
    *params)
{
    sfVector2f pos = {rand_frame(250, 1000, &params->last_spawn), 830};
    sfVector2f dir = {5.5 * rand_direction(), -3};
    sfVector2f origin = {55, 55};
    sfVector2f scale = {-1, 1};

    images->sprites = sfSprite_create();
    set_duck_properties(duck);
    duck->pos = pos;
    duck->dir = dir;
    duck_set_rect(images, params->duck_texture);
    sfSprite_scale(images->sprites, scale);
    sfSprite_setOrigin(images->sprites, origin);
    sfSprite_setPosition(images->sprites, duck->pos);
    if (dir.x < 0)
        rev_sprite(images->sprites);
}
