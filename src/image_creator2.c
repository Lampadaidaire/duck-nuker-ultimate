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

sfSound *initialize_universel_sound(load_sound_t *sound)
{
    sound->sound_buf = sfSoundBuffer_createFromFile(sound->file);
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->sound_buf);
    return sound->sound;
}

void load_sound_second(display_struct_t *params)
{
    params->sounds.shoot1_buf = sfSoundBuffer_createFromFile(
        "Sounds/shoot1.ogg");
    params->sounds.reload_buf = sfSoundBuffer_createFromFile(
        "Sounds/reload.ogg");
    params->sounds.quack_buf = sfSoundBuffer_createFromFile(
        "Sounds/quack.ogg");
    params->sounds.quack_buf = sfSoundBuffer_createFromFile(
        "Sounds/quack.ogg");
    params->sounds.quack = sfSound_create();
    params->sounds.reload = sfSound_create();
    params->sounds.shoot1 = sfSound_create();
    sfSound_setBuffer(params->sounds.shoot1, params->sounds.shoot1_buf);
    sfSound_setBuffer(params->sounds.reload, params->sounds.reload_buf);
    sfSound_setBuffer(params->sounds.quack, params->sounds.quack_buf);
    params->nuke.nuke_sound = initialize_universel_sound(&(load_sound_t){
        "Sounds/nuke.ogg", params->nuke.nuke_buf, params->nuke.nuke_sound});
    params->nuke.no_nuke_sound = initialize_universel_sound(&(load_sound_t){
        "Sounds/empty.ogg", params->nuke.no_nuke_buf,
        params->nuke.no_nuke_sound});
    sfSound_setVolume(params->sounds.shoot1, 65);
}

void add_bullet_rectangle(images_t *images)
{
    images->rect.left = 30;
    images->rect.top = 112;
    images->rect.width = 110;
    images->rect.height = 220;
    sfSprite_setTextureRect(images->sprites, images->rect);
}

void create_pause_images(display_struct_t *params)
{
    params->pause.pause_img.sprites = initialize_universel_image(
        &(load_image_t){"Images/pause.png", (sfVector2f){1, 1}, (sfVector2f){0,
        0}, params->pause.pause_img, (sfVector2f){375, 30}});
    params->pause.resum_img.sprites = initialize_universel_image(
        &(load_image_t){"Images/resume.png", (sfVector2f){0.8, 0.8},
        (sfVector2f){0, 0}, params->pause.resum_img, (sfVector2f){470, 250}});
    params->pause.exit_img.sprites = initialize_universel_image(
        &(load_image_t){"Images/exit.png", (sfVector2f){0.8, 0.77},
        (sfVector2f){0, 0}, params->pause.exit_img, (sfVector2f){375, 400}});
    params->nuke.nuke_image.sprites = initialize_universel_image(
        &(load_image_t){"Images/nuke.png", (sfVector2f){0.3, 0.3},
        (sfVector2f){728 / 2, 343 / 2}, params->nuke.nuke_image,
        (sfVector2f){830, -200}});
    sfSprite_setRotation(params->nuke.nuke_image.sprites, -90);
}

void add_bullets(images_t *images, char *file)
{
    sfVector2f size = {1, 1};
    sfVector2f pos = { 1510, 780 };

    images->textures = sfTexture_createFromFile(file, NULL);
    images->sprites = sfSprite_create();
    images->textures = sfTexture_createFromFile("Images/bullet.png", NULL);
    sfSprite_setTexture(images->sprites, images->textures, sfTrue);
    add_bullet_rectangle(images);
    sfSprite_scale(images->sprites, size);
    sfSprite_setPosition(images->sprites, pos);
}
