/*
** EPITECH PROJECT, 2024
** my evil str
** File description:
** evil grrr
*/

int len(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    if (i % 2 == 1) {
        i--;
    } else {
    i--;
    }
    return (i);
}

void swaper(char *a, char *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

char *my_revstr(char *str)
{
    int length = len(str);
    int end = length / 2;
    int rev_len = 0;
    char *a;
    char *b;

    if (length % 2 == 1) {
        end++;
    }
    for (end; end != 0; end--) {
        a = &str[rev_len];
        b = &str[length];
        swaper(a, b);
        rev_len++;
        length--;
    }
    return (str);
}
