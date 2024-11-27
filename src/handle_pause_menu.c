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

void draw_paused_image(display_struct_t *params)
{
    sfRenderWindow_drawSprite(params->window,
        params->pause.pause_img.sprites, NULL);
    sfRenderWindow_drawSprite(params->window,
        params->pause.resum_img.sprites, NULL);
    sfRenderWindow_drawSprite(params->window,
        params->pause.exit_img.sprites, NULL);
}

void handle_pause_clicks(display_struct_t *params, sfMouseButtonEvent event)
{
    sfFloatRect resum_rect = sfSprite_getGlobalBounds(
        params->pause.resum_img.sprites);
    sfFloatRect exit_rect = sfSprite_getGlobalBounds(
        params->pause.exit_img.sprites);
    sfVector2u size = sfRenderWindow_getSize(params->window);
    float coef_x = (float)size.x / 1664;
    float coef_y = (float)size.y / 936;

    if (sfFloatRect_contains(&resum_rect, (float)event.x / coef_x,
        (float)event.y / coef_y))
        handle_pause_menu(params);
    if (sfFloatRect_contains(&exit_rect, (float)event.x / coef_x,
        (float)event.y / coef_y))
        params->should_exit = 1;
}

void handle_pause_menu(display_struct_t *params)
{
    if (params->pause.is_paused == 0) {
        sfSprite_setScale(params->decor[2].sprites, (sfVector2f){0.15, 0.15});
        sfRenderWindow_setMouseCursorVisible(params->window, sfFalse);
        params->pause.is_paused = 1;
        return;
    }
    sfSprite_setScale(params->decor[2].sprites, (sfVector2f){0, 0});
    sfRenderWindow_setMouseCursorVisible(params->window, sfTrue);
    params->pause.is_paused = 0;
}
