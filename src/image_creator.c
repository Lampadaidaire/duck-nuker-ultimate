/*
** EPITECH PROJECT, 2024
** add_images
** File description:
** add_images
*/
#include <SFML/Audio.h>
#include "my.h"
#include "hunter.h"
#include <SFML/Graphics.h>

/*
decor[2] is the cursor
*/
void draw_sprites(display_struct_t *params, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, params->images[0].sprites, NULL);
    for (int i = 1; i < params->duck_nbr + 1; i++) {
        if (params->pause.is_paused == 1)
            sfRenderWindow_drawSprite(window, params->images[i].sprites, NULL);
    }
    sfRenderWindow_drawSprite(params->window,
        params->nuke.nuke_image.sprites, NULL);
    sfRenderWindow_drawSprite(window, params->decor[0].sprites, NULL);
    sfRenderWindow_drawSprite(window, params->decor[1].sprites, NULL);
    sfRenderWindow_drawSprite(window, params->decor[5].sprites, NULL);
    sfRenderWindow_drawSprite(window, params->decor[4].sprites, NULL);
    sfRenderWindow_drawSprite(window, params->decor[2].sprites, NULL);
}

void add_background(images_t *images, char *file)
{
    images->textures = sfTexture_createFromFile(file, NULL);
    images->sprites = sfSprite_create();
    sfSprite_setTexture(images->sprites, images->textures, sfTrue);
}

void add_sign(images_t *images, char *file)
{
    sfVector2f size = { 0.5, 0.5 };
    sfVector2f pos = { 0, 800 };

    images->textures = sfTexture_createFromFile(file, NULL);
    images->sprites = sfSprite_create();
    sfSprite_setTexture(images->sprites, images->textures, sfTrue);
    sfSprite_scale(images->sprites, size);
    sfSprite_setPosition(images->sprites, pos);
}

void add_cursor(images_t *images, char *file)
{
    sfVector2f size = {0.15, 0.15};
    sfVector2f origin = {520, 515};
    sfColor color = sfColor_fromRGB(121, 64, 61);

    images->textures = sfTexture_createFromFile(file, NULL);
    images->sprites = sfSprite_create();
    sfSprite_setTexture(images->sprites, images->textures, sfTrue);
    sfSprite_scale(images->sprites, size);
    sfSprite_setColor(images->sprites, color);
    sfSprite_setOrigin(images->sprites, origin);
}

void add_decor(images_t *images, char *file)
{
    sfVector2f size = { 2.5, 2.5 };
    sfVector2f pos = { 0, 10 };

    images->textures = sfTexture_createFromFile(file, NULL);
    images->sprites = sfSprite_create();
    sfSprite_setTexture(images->sprites, images->textures, sfTrue);
    sfSprite_scale(images->sprites, size);
    sfSprite_setPosition(images->sprites, pos);
    sfSprite_setColor(images->sprites, sfColor_fromRGB(0, 255, 150));
}
