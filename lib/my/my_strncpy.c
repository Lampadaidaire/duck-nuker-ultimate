/*
** EPITECH PROJECT, 2024
** my_strncpy
** File description:
** my_strncpy
*/
int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int length = my_strlen(src);
    int i = 0;
    int n_cpy = n;

    if (n < 0) {
    }
    for (i; i < n; i++) {
        dest[i] = src[i];
    }
    if (n_cpy > length) {
        dest[i] = '\0';
    }
    return (dest);
}
