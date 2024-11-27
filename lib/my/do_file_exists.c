/*
** EPITECH PROJECT, 2024
** do_file_exists
** File description:
** returns 0 if file exists
*/
#include <sys/stat.h>

int do_file_exists(char const *filepath)
{
    struct stat struct_stat;

    if (stat(filepath, &struct_stat) == -1)
        return -1;
    return 0;
}
