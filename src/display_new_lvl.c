/*
** EPITECH PROJECT, 2024
** display struct
** File description:
** display lvl
*/
#include "hunter.h"
#include "my.h"
#include "stdlib.h"

void add_sec_sign(images_t *images, char *file)
{
    sfVector2f size = { 1.3, 1.3 };
    sfVector2f pos = { 695, 800 };

    images->textures = sfTexture_createFromFile(file, NULL);
    images->sprites = sfSprite_create();
    sfSprite_setTexture(images->sprites, images->textures, sfTrue);
    sfSprite_scale(images->sprites, size);
    sfSprite_setPosition(images->sprites, pos);
}

void add_lvl_txt(display_struct_t *params)
{
    sfVector2f lvl_pos = { 750, 840 };
    sfVector2f lvl_nbr_pos = { 910, 840 };
    sfFont *pixel_font = sfFont_createFromFile("Font/font.ttf");

    params->player.lvl_text = sfText_create();
    sfText_setPosition(params->player.lvl_text, lvl_pos);
    sfText_setFont(params->player.lvl_text, pixel_font);
    sfText_setColor(params->player.lvl_text, sfColor_fromRGB(0, 0, 0));
    sfText_setCharacterSize(params->player.lvl_text, 30);
    sfText_setStyle(params->player.lvl_text, sfTextBold);
    sfText_setString(params->player.lvl_text, "Level :");
    params->player.lvl_nbr_text = sfText_create();
    sfText_setPosition(params->player.lvl_nbr_text, lvl_nbr_pos);
    sfText_setFont(params->player.lvl_nbr_text, pixel_font);
    sfText_setColor(params->player.lvl_nbr_text, sfColor_fromRGB(0, 0, 0));
    sfText_setCharacterSize(params->player.lvl_nbr_text, 30);
    sfText_setStyle(params->player.lvl_nbr_text, sfTextBold);
    sfText_setString(params->player.lvl_nbr_text, int_to_str(params->lvl));
}

static void check_twinking(display_struct_t *params)
{
    if (params->player.twink_nbr != 0)
        params->player.time_new_lvl += params->game_clock.seconds;
    else {
        sfRenderWindow_drawText(params->window, params->player.lvl_text,
            NULL);
        sfRenderWindow_drawText(params->window, params->player.lvl_nbr_text,
            NULL);
    }
}

void display_lvl_txt(display_struct_t *params)
{
    check_twinking(params);
    if (params->player.time_new_lvl > 0.5) {
        sfRenderWindow_drawText(params->window, params->player.lvl_nbr_text,
            NULL);
        sfRenderWindow_drawText(params->window, params->player.lvl_text,
        NULL);
    }
    if (params->player.twink_nbr == 4) {
        params->player.time_new_lvl = 0;
        params->player.twink_nbr = 0;
    } else if (params->player.time_new_lvl > 1 && params->player.twink_nbr
        < 3) {
        params->player.twink_nbr += 1;
        params->player.time_new_lvl = 0;
    }
}

void handle_lvl_txt(display_struct_t *params)
{
    params->player.time_new_lvl = 0;
    params->player.twink_nbr = 1;
    sfText_setString(params->player.lvl_nbr_text, int_to_str(params->lvl));
    sfSound_play(params->sounds.lvl_up);
}
