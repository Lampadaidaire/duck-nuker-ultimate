/*
** EPITECH PROJECT, 2024
** nuke
** File description:
** handle nuke
*/
#include "hunter.h"
#include "my.h"

void do_explosion(display_struct_t *params)
{
    if (params->pause.is_paused == 0 || params->is_game_over == 0) {
        sfSound_pause(params->nuke.nuke_sound);
    }
    if (params->pause.is_paused == 1 && params->is_game_over == 1) {
        sfSprite_move(params->nuke.nuke_image.sprites, (sfVector2f){0, 3.5 *
        params->game_clock.seconds * 60});
        if (sfSound_getStatus(params->nuke.nuke_sound) == sfPaused)
            sfSound_play(params->nuke.nuke_sound);
    }
    if (sfSound_getPlayingOffset(params->nuke.nuke_sound).microseconds /
        1000000.0 > 3.2)
        params->nuke.can_display = 1;
    if (sfSound_getPlayingOffset(params->nuke.nuke_sound).microseconds /
        1000000.0 > 7.1) {
            sfRenderWindow_setMouseCursorVisible(params->window, sfTrue);
            params->should_exit = 1;
    }
}

void handle_nuke(display_struct_t *params)
{
    if (params->player.score >= 0000) {
        params->nuke.nuke_enabled = 0;
        get_new_bestscore(params);
        if (sfSound_getStatus(params->nuke.nuke_sound) != sfPlaying)
            sfSound_play(params->nuke.nuke_sound);
    } else
        sfSound_play(params->nuke.no_nuke_sound);
}
