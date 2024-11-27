/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** str cat
*/
#include "my.h"

char *my_strncat(char *dest, char const *str, int nb)
{
    int length = my_strlen(dest);

    for (int i = 0; str[i] != 0; i++) {
        if (nb != 0) {
            dest[length + i] = str[i];
        }
        nb--;
    }
    return (dest);
}
