/*
** EPITECH PROJECT, 2024
** my_find_prime_sup
** File description:
** my_find_prime_sup
*/
#include "my.h"

int my_find_prime_sup(int nb)
{
    if (nb <= 1) {
        return (2);
    }
    while (is_prime(nb) == 0) {
        nb++;
    }
    return (nb);
}

int is_prime(int nb)
{
    int i;

    for (i = 2; i < nb; i++) {
        if (nb % i == 0) {
            return (0);
        }
    }
    return (1);
}
