/*
** EPITECH PROJECT, 2024
** main
** File description:
** main function
*/
#include <SFML/Audio.h>
#include "my.h"
#include "hunter.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>

static void handle_help(void)
{
    my_putstr("***Help menu***\n");
    my_putstr("\n                 Welcome to the \"my_hunter\" game !\n\n");
    my_putstr("Your goal is to shoot as many ducks as you can with the left");
    my_putstr(" click button.\nThe score increases when you shoot a duck. ");
    my_putstr("If a duck escapes, you loose points.\nTo make the best score");
    my_putstr(", try to shoot the ducks as fast as you can !\n");
    my_putstr("For each missed shots, you loos one of your 5 bullets.\n");
    my_putstr("You can press 'r' to reload earlier (if your magazine is ");
    my_putstr("empty, it reloads automatically)\n\n");
    my_putstr("You have 10 seconds to kill a duck. If it escapes, it quacks");
    my_putstr(" and you loose some points.\nThe game lasts 3 minutes.\n");
    my_putstr("\n(If you have more than 150 000 points,");
    my_putstr(" try to right click)\nEscape: pause/resume\n");
}

int main(int ac, char **av)
{
    display_struct_t params = create_window();

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        handle_help();
        return 0;
    }
    if (ac > 1)
        my_putstr("Invalid option. Use -h for help.\n");
    if (ac == 1)
        start_menu(&params);
    sfRenderWindow_destroy(params.window);
    return 0;
}
