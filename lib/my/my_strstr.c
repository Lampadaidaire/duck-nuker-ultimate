/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** strstr
*/

int length_of_str(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int check(char *str, char const *to_find, int i)
{
    int length = length_of_str(to_find);
    int j = 0;

    for (i; str[i] == to_find[j]; i++) {
        if (length == j) {
            return (0);
        }
        j++;
    }
}

char *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (check(str, to_find, i) == 0) {
            return (&str[i]);
        }
    }
    return 0;
}
