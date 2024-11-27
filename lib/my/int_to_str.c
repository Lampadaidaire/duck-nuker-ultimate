/*
** EPITECH PROJECT, 2024
** int_to_str
** File description:
** transform an int into char*
*/
#include "my.h"
#include "stdlib.h"

char *int_to_str(int nb)
{
    char *str = malloc(sizeof(char) * 10 + 1);
    int i = 0;

    if (nb <= 0 || nb > 2000000000)
        return "0";
    for (; nb > 0; i++) {
        str[i] = nb % 10 + 48;
        nb /= 10;
    }
    str[i] = '\0';
    return my_revstr(str);
}
