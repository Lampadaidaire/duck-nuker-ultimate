/*
** EPITECH PROJECT, 2024
** handle end game
** File description:
** en game handler
*/
#include "hunter.h"
#include "my.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "stdio.h"

char *get_time(display_struct_t *params)
{
    char *time = malloc(sizeof(char) * 5);
    int rev_timer = 180 - params->game_timer;
    char *end = "0:00";

    while (params->game_timer < 180) {
        time[0] = rev_timer / 60 + 48;
        time[1] = ':';
        time[2] = rev_timer / 10 % 6 + 48;
        time[3] = rev_timer % 10 + 48;
        time[4] = '\0';
        return time;
    }
    return end;
}

void add_game_over(images_t *images, char *file)
{
    sfVector2f size = {1.3, 1.3};
    sfVector2f pos = {310, 100};

    images->textures = sfTexture_createFromFile(file, NULL);
    images->sprites = sfSprite_create();
    sfSprite_setTexture(images->sprites, images->textures, sfTrue);
    sfSprite_scale(images->sprites, size);
    sfSprite_setPosition(images->sprites, pos);
}

static void display_restart_txt(display_struct_t *params)
{
    params->player.time_restart += params->game_clock.seconds;
    if (params->player.time_restart > 0.5 && params->game_timer > 181)
        sfRenderWindow_drawText(params->window, params->restart_txt, NULL);
    if (params->player.time_restart > 1)
        params->player.time_restart = 0;
}

void get_new_bestscore(display_struct_t *params)
{
    FILE *fd = fopen("Save/save", "r+");

    if (params->player.score > params->bestscore + 1) {
        params->bestscore = params->player.score;
        params->bestscore_char = int_to_str(params->bestscore);
        fwrite(params->bestscore_char, my_strlen(params->bestscore_char),
            1, fd);
        sfText_setString(params->best_score_txt, params->bestscore_char);
    }
    fclose(fd);
}

static void display_bestscore(display_struct_t *params)
{
    get_new_bestscore(params);
    sfRenderWindow_drawText(params->window, params->bestscore_fix, NULL);
    sfRenderWindow_drawText(params->window, params->best_score_txt, NULL);
}

void display_final_screen(display_struct_t *params)
{
    sfVector2f size = {1, 1};
    sfVector2f nul = {0, 0};
    sfVector2f text_pos = {680, 440};
    sfVector2f pos = {515, 337};
    sfText *nbr_score = sfText_copy(params->player.score_nbr_text);
    sfSprite *panel = sfSprite_copy(params->decor[1].sprites);

    sfSprite_setScale(panel, size);
    sfSprite_setPosition(panel, pos);
    sfText_setCharacterSize(nbr_score, 60);
    sfText_setPosition(nbr_score, text_pos);
    sfRenderWindow_drawSprite(params->window, panel, NULL);
    sfSprite_scale(params->decor[2].sprites, nul);
    sfRenderWindow_drawSprite(params->window, params->decor[3].sprites, NULL);
    sfRenderWindow_drawText(params->window, nbr_score, NULL);
    display_bestscore(params);
    display_restart_txt(params);
}

void handle_end_game(display_struct_t *params)
{
    if (params->pause.is_paused == 1)
        params->game_timer += params->game_clock.seconds;
    if (params->nuke.nuke_enabled == 0)
        do_explosion(params);
    if (params->game_timer > 180) {
        params->is_game_over = 0;
        params->player.amos = 0;
        for (int i = 0; i < params->duck_nbr; i++)
            params->duck[i].can_move = 0;
        sfMusic_stop(params->sounds.music);
        sfRenderWindow_setMouseCursorVisible(params->window, sfTrue);
        display_final_screen(params);
    }
}
