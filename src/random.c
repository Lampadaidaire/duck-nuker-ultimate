/*
** EPITECH PROJECT, 2024
** random
** File description:
** random
*/
#include <stdlib.h>
#include "hunter.h"
#include <SFML/Graphics.h>
#include <time.h>

void rev_sprite(sfSprite *sprite)
{
    sfVector2f rev = {-1, 1};

    sfSprite_scale(sprite, rev);
}

int rand_direction(void)
{
    int rd = 1;

    srand(time(0));
    rd = rand();
    if (rd % 2 == 1) {
        return -1;
    }
    if (rd % 2 == 0)
        return 1;
    return 1;
}

int rand_frame(int min, int max, int *last_spawn)
{
    int nb = 1;

    nb = min + rand() / (RAND_MAX / (max - min + 1) + 1);
    if (*last_spawn == 0) {
        *last_spawn += 1;
        return nb;
    }
    if (*last_spawn == 1) {
        *last_spawn += 1;
        return 360 - rand() % 100;
    }
    if (*last_spawn == 2) {
        *last_spawn += 1;
        return nb + 400;
    } else if (*last_spawn == 3) {
        *last_spawn = 0;
        return 1343;
    }
    *last_spawn = 0;
    return nb;
}
