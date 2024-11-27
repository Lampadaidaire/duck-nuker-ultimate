/*
** EPITECH PROJECT, 2024
** menu
** File description:
** menu
*/
#include <SFML/Audio.h>
#include "my.h"
#include "hunter.h"
#include "fcntl.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "stdio.h"
#include <unistd.h>

static images_t *load_menu(display_struct_t *params)
{
    images_t *menu_images = malloc(sizeof(images_t) * 3);
    sfVector2f pos = { 590, 320};
    sfFont *pixel_font = sfFont_createFromFile("Font/font.ttf");

    add_background(&menu_images[0], "Images/background.jpg");
    menu_images[1].textures = sfTexture_createFromFile(
        "Images/start_button.png", NULL);
    menu_images[1].sprites = sfSprite_create();
    sfSprite_setTexture(menu_images[1].sprites, menu_images[1].textures,
        sfTrue);
    sfSprite_setPosition(menu_images[1].sprites, pos);
    get_bestscore(params);
    menu_images[2].sprites = initialize_universel_image(&(load_image_t)
        {"Images/exit.png", (sfVector2f){1, 0.9}, (sfVector2f){0, 0},
        menu_images[2], (sfVector2f){520, 700}});
    params->best_score_txt = initialize_universel_text(&(text_t){
        params->bestscore_char, 40, sfColor_fromRGB(0, 0, 0), pixel_font,
        params->best_score_txt, sfTextBold, (sfVector2f){110, 70}});
    sfSprite_setColor(menu_images[2].sprites, sfColor_fromRGB(255, 50, 50));
    return menu_images;
}

display_struct_t create_window(void)
{
    display_struct_t params;
    sfFont *pixel_font = sfFont_createFromFile("Font/font.ttf");

    params.mode.height = 936;
    params.mode.width = 1664;
    params.window = sfRenderWindow_create(params.mode,
        "Duck nuker anti-vegan ultimate", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(params.window, 144);
    params.bestscore_fix = initialize_universel_text(&(text_t){
        "Bestscore:\n", 40, sfColor_fromRGB(0, 0, 0), pixel_font,
        params.best_score_txt, sfTextBold, (sfVector2f){90, 20}});
    return params;
}

static void draw_menu_sprites(images_t *menu_images, sfRenderWindow *window,
    display_struct_t *params)
{
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(window, menu_images[i].sprites, NULL);
    sfRenderWindow_drawText(params->window, params->best_score_txt, NULL);
    sfRenderWindow_drawText(params->window, params->bestscore_fix, NULL);
}

int manage_menu_left_click(sfMouseButtonEvent event, display_struct_t *params,
    sfMusic *quack, images_t *menu_images)
{
    sfVector2u size = sfRenderWindow_getSize(params->window);
    float coef_x = (float)size.x / 1664;
    float coef_y = (float)size.y / 936;
    sfFloatRect rect_exit = sfSprite_getGlobalBounds(menu_images[2].sprites);

    if (event.x <= 990 * coef_x &&
        event.x >= 664 * coef_x &&
        event.y <= 520 * coef_y &&
        event.y >= 390 * coef_y) {
        sfMusic_play(quack);
        return 1;
    }
    if (sfFloatRect_contains(&rect_exit, event.x / coef_x, event.y / coef_y))
        sfRenderWindow_close(params->window);
    return 0;
}

int analyse_menu_events(display_struct_t *params, sfEvent event,
    sfMusic *quack, images_t *menu_images)
{
    basic_events(params->window, event);
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft)
        return manage_menu_left_click(event.mouseButton, params, quack,
            menu_images);
    return 0;
}

static void do_scene_switch(display_struct_t *params, sfMusic *menu)
{
    sfMusic_setLoop(menu, sfFalse);
    sfMusic_stop(menu);
    start_game(params);
}

static void start_menu_music(sfMusic *menu)
{
    sfMusic_setLoop(menu, sfTrue);
    sfMusic_play(menu);
}

void get_bestscore(display_struct_t *params)
{
    int fd = open("Save/save", O_RDONLY);
    char *buf = malloc(sizeof(char) * 10);
    int i = 0;

    params->bestscore_char = malloc(sizeof(char) * 10);
    read(fd, buf, 10);
    for (; buf[i] >= '0' && buf[i] <= '9' && buf[i] != '\0'; i++) {
        params->bestscore_char[i] = buf[i];
    }
    params->bestscore_char[i] = '\0';
    params->bestscore = my_getnbr(buf);
}

int start_menu(display_struct_t *params)
{
    images_t *menu_images = load_menu(params);
    sfMusic *menu = sfMusic_createFromFile("Sounds/menu_music.ogg");
    sfMusic *quack = sfMusic_createFromFile("Sounds/quack.ogg");
    int switch_scene = 0;

    start_menu_music(menu);
    while (sfRenderWindow_isOpen(params->window)) {
        while (sfRenderWindow_pollEvent(params->window, &params->event))
            switch_scene = analyse_menu_events(params, params->event, quack,
                menu_images);
        sfRenderWindow_clear(params->window, sfBlack);
        draw_menu_sprites(menu_images, params->window, params);
        sfRenderWindow_display(params->window);
        if (switch_scene == 1)
            break;
    }
    if (switch_scene == 1)
        do_scene_switch(params, menu);
    menu_destroyer(menu_images, menu, quack);
    return 0;
}
