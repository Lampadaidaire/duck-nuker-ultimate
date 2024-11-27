/*
** EPITECH PROJECT, 2024
** my_compute_square_root.c
** File description:
** my_compute_square_root.c
*/

int my_compute_square_root(int nb)
{
    int x;

    for (x = 1; x <= nb; x++) {
        if (nb % x == 0 && nb / x == x) {
            return (x);
        }
    }
    return (0);
}
