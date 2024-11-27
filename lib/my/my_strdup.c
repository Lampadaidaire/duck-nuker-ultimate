/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** strdup
*/
#include <stdlib.h>
#include "my.h"
char *my_strdup(char const *src)
{
    char *to_ret = malloc(sizeof(char) * my_strlen(src) + 1);

    my_strcpy(to_ret, src);
    return (to_ret);
}
