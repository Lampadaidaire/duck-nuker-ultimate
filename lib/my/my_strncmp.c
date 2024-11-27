/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** my_strcmp.c
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i != n; i++) {
        if (s1[i] < s2[i]) {
            return (s1[i] - s2[i]);
        }
        if (s1[i] > s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return 0;
}
