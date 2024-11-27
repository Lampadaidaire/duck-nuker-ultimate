/*
** EPITECH PROJECT, 2024
** my_compute_power_rec
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    long long nbl = nb;

    if (p < 0) {
        return (0);
    }
    if (p != 1) {
        nbl = nbl * my_compute_power_rec(nbl, p - 1);
    }
    if (nbl > 2147483647 || nbl < -2147483648) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    return (nbl);
}
