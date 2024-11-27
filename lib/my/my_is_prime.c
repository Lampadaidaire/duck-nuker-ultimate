/*
** EPITECH PROJECT, 2024
** my_is_prime.c
** File description:
** my_is_prime.c
*/

int my_is_prime(int nb)
{
    int i;

    if (nb <= 1) {
        return (0);
    }
    if (nb == 2) {
        return (1);
    }
    for (i = 2; i < nb; i++) {
        if (nb % i == 0) {
            return (0);
        }
    }
    return (1);
}
