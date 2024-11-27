/*
** EPITECH PROJECT, 2024
** create universary
** File description:
** create
*/
#include "hunter.h"
#include "my.h"

sfText *initialize_universel_text(text_t *text_par)
{
    text_par->text = sfText_create();
    sfText_setPosition(text_par->text, text_par->pos);
    sfText_setFont(text_par->text, text_par->font);
    sfText_setColor(text_par->text, text_par->color);
    sfText_setCharacterSize(text_par->text, text_par->font_size);
    sfText_setStyle(text_par->text, text_par->style);
    sfText_setString(text_par->text, text_par->str);
    return text_par->text;
}

sfSprite *initialize_universel_image(load_image_t *image_par)
{
    image_par->tex_spr.textures = sfTexture_createFromFile(image_par->file,
        NULL);
    image_par->tex_spr.sprites = sfSprite_create();
    sfSprite_setTexture(image_par->tex_spr.sprites, image_par->tex_spr.
        textures, sfTrue);
    sfSprite_setOrigin(image_par->tex_spr.sprites, image_par->origin);
    sfSprite_scale(image_par->tex_spr.sprites, image_par->size);
    sfSprite_setPosition(image_par->tex_spr.sprites, image_par->pos);
    return image_par->tex_spr.sprites;
}
