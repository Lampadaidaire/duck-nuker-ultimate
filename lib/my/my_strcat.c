/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** str cat
*/
#include "my.h"

char *my_strcat(char *dest, char const *str)
{
    int length = my_strlen(dest);

    for (int i = 0; str[i] != 0; i++) {
        dest[length + i] = str[i];
    }
    return (dest);
}
