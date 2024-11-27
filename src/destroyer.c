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
#include <unistd.h>

static void images_destroyer(display_struct_t *display_params)
{
    sfTexture_destroy(display_params->duck_texture);
    sfTexture_destroy(display_params->dead_texture);
    for (int i = 0; i < display_params->duck_nbr; i++) {
        sfSprite_destroy(display_params->images[i].sprites);
    }
    for (int i = 0; i < 5; i++) {
        sfTexture_destroy(display_params->decor[i].textures);
        sfSprite_destroy(display_params->decor[i].sprites);
    }
    sfSprite_destroy(display_params->pause.pause_img.sprites);
    sfSprite_destroy(display_params->pause.exit_img.sprites);
    sfSprite_destroy(display_params->pause.resum_img.sprites);
    sfSprite_destroy(display_params->nuke.nuke_image.sprites);
}

void sound_destroyer(display_struct_t *display_params)
{
    sfMusic_destroy(display_params->sounds.music);
    sfSoundBuffer_destroy(display_params->sounds.shoot1_buf);
    sfSound_destroy(display_params->sounds.shoot1);
    sfSoundBuffer_destroy(display_params->sounds.explo_buf1);
    sfSoundBuffer_destroy(display_params->sounds.explo_buf2);
    sfSound_destroy(display_params->sounds.exploding1);
    sfSound_destroy(display_params->sounds.exploding2);
    sfSoundBuffer_destroy(display_params->sounds.lvl_up_buf);
    sfSound_destroy(display_params->sounds.lvl_up);
    sfSoundBuffer_destroy(display_params->sounds.reload_buf);
    sfSound_destroy(display_params->sounds.reload);
    sfSoundBuffer_destroy(display_params->sounds.quack_buf);
    sfSound_destroy(display_params->sounds.quack);
}

void text_destroyer(display_struct_t *display_params)
{
    sfText_destroy(display_params->player.score_text);
    sfText_destroy(display_params->player.score_nbr_text);
    sfText_destroy(display_params->player.lvl_nbr_text);
    sfText_destroy(display_params->player.lvl_text);
    sfText_destroy(display_params->restart_txt);
    sfText_destroy(display_params->player.timer);
}

void stop_sound(display_struct_t *display_params)
{
    sfSound_stop(display_params->nuke.nuke_sound);
    sfSound_stop(display_params->sounds.quack);
    sfSound_stop(display_params->sounds.reload);
    sfSound_stop(display_params->sounds.exploding1);
    sfSound_stop(display_params->sounds.exploding2);
    sfSound_stop(display_params->sounds.lvl_up);
    sfSound_stop(display_params->sounds.shoot1);
    sfSound_stop(display_params->nuke.no_nuke_sound);
}

void destroyer(display_struct_t *display_params)
{
    stop_sound(display_params);
    sfClock_destroy(display_params->game_clock.clock);
    images_destroyer(display_params);
    sound_destroyer(display_params);
    text_destroyer(display_params);
}

void menu_destroyer(images_t *menu_images, sfMusic *menu, sfMusic *quack)
{
    sfSprite_destroy(menu_images[0].sprites);
    for (int i = 0; i < 2; i++) {
        sfTexture_destroy(menu_images[i].textures);
        sfSprite_destroy(menu_images[i + 1].sprites);
    }
    sfMusic_destroy(menu);
    sfMusic_destroy(quack);
    free(menu_images);
}
