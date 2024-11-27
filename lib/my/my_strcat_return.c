/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** str cat
*/
#include "my.h"

char *my_strcat_return(char *dest, char const *str)
{
    int length = my_strlen(dest);
    int i = 0;

    for (i = 0; str[i] != 0; i++) {
        dest[length + i] = str[i];
    }
    dest[length + i] = '\n';
    return (dest);
}
