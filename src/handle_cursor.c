/*
** EPITECH PROJECT, 2024
** handle_cursor
** File description:
** change cursor
*/
#include <SFML/Graphics.h>
#include "my.h"
#include "hunter.h"
#include "stdio.h"

void handle_reload(display_struct_t *params)
{
    params->decor[4].rect = (sfIntRect){580, 112, 110, 220};
    sfSprite_setTextureRect(params->decor[4].sprites, params->decor[4].
            rect);
    params->player.amos = 0;
    if (params->player.reload_time == 0)
        sfSound_play(params->sounds.reload);
    params->player.reload_time += params->game_clock.seconds;
    if (params->player.reload_time > 3.6) {
        params->decor[4].rect = (sfIntRect){30, 112, 110, 220};
        sfSprite_setTextureRect(params->decor[4].sprites, params->decor[4].
            rect);
        params->player.amos = 5;
        params->player.reload_time = 0;
    }
}

void handle_cursor(display_struct_t *params)
{
    sfVector2f pos;
    float coef_x;
    float coef_y;
    sfVector2u size = sfRenderWindow_getSize(params->window);

    pos.x = (float){sfMouse_getPositionRenderWindow(params->window).x};
    pos.y = (float){sfMouse_getPositionRenderWindow(params->window).y};
    coef_x = (float)size.x / 1664;
    coef_y = (float)size.y / 936;
    pos.x /= coef_x;
    pos.y /= coef_y;
    sfSprite_setPosition(params->decor[2].sprites, pos);
    if (params->player.amos == 0 && params->is_game_over == 1 && params->pause
        .is_paused == 1)
        handle_reload(params);
}
