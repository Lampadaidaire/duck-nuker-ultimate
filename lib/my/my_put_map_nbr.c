/*
** EPITECH PROJECT, 2024
** my_put_map_nbr
** File description:
** put map nbr
*/
#include "my.h"

int my_put_map_nbr(int **map, int nb_cols)
{
    for (int i = 0; map[i] != 0; i++) {
        for (int j = 0; j < nb_cols; j++) {
            my_put_nbr(map[i][j]);
        }
        my_putchar('\n');
    }
    return 0;
}
