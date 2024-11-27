/*
** EPITECH PROJECT, 2024
** my func
** File description:
** c
*/

#ifndef MY_H_
    #define MY_H_

int my_put_map_nbr(int **map, int);
char *int_to_str(int);
int do_file_exists(char const *);
int my_putmap(char **map, char *separator);
char *my_strcat_return(char *dest, char const *str);
int count_total_words(char const *str);
int count_start(char const *str, int i);
int count_length(char const *str, int start);
int is_letter_nbr(char c);
int count_str_str_len(char *const *str);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int is_prime(int nb);
int returner(int length, char *str, int beg);
int pos_neg(char *str, int beg);
int printer2(long long nb);
int count_my_strlen(char const *str);
int swaper(char *, char *);
int check(char *str, char const *to_find, int i);
int length_of_str(char const *);
int is_nbr(char *str);
char *my_strdup(char const *);
int do_op(int argc, char **argv);

#endif /* MY_H_ */
