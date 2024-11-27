/*
** EPITECH PROJECT, 2024
** str to word array
** File description:
** str to word array
*/
#include <stdlib.h>
#include "my.h"

char **my_str_to_word_array(char const *str)
{
    int start = count_start(str, 0);
    int length = count_length(str, start);
    int total_words = count_total_words(str);
    char **to_ret = malloc(sizeof(char *) * (total_words + 1));

    for (int count = 0; total_words > count; count++) {
        to_ret[count] = malloc((1 + length) * sizeof(char));
        for (int i = 0; i < length; i++) {
            to_ret[count][i] = str[start];
            start++;
        }
        start = count_start(str, start);
        length = count_length(str, start);
    }
    to_ret[total_words] = 0;
    return (to_ret);
}

int count_total_words(char const *str)
{
    int total_words = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (is_letter_nbr(str[i - 1]) == 1 && is_letter_nbr(str[i]) == 0) {
            total_words++;
        }
    }
    return (total_words);
}

int count_start(char const *str, int i)
{
    while (is_letter_nbr(str[i]) == 1 && str[i] != '\0') {
        i++;
    }
    if (str[i] != '\0') {
        return (i);
    }
    return 0;
}

int count_length(char const *str, int start)
{
    int length = 0;

    while (is_letter_nbr(str[start]) == 0) {
        length++;
        start++;
    }
    return (length);
}

int is_letter_nbr(char c)
{
    if ((c >= 48 && c <= 57) || (c >= 65
        && c <= 90) || (c >= 97 && c <= 122)) {
        return 0;
    }
    return 1;
}
