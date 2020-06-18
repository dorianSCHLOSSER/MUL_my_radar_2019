/*
** EPITECH PROJECT, 2020
** my_create_tow
** File description:
** return
*/

#include "my.h"

void create_air(csfml_t *spri_text, pos_t *pos, int nbr_a)
{
    for (int i = 0 ; i < nbr_a ; i++) {
        spri_text->aircraft[i] = sfSprite_create();
        spri_text->shape[i] = sfRectangleShape_create();
        sfRectangleShape_setTexture(spri_text->shape[i], spri_text->hitbox, \
        sfTrue);
        sfRectangleShape_setSize(spri_text->shape[i], (sfVector2f) {20, 20});
        sfRectangleShape_setPosition(spri_text->shape[i], pos->air_dep[i]);
        sfSprite_setTexture(spri_text->aircraft[i], spri_text->t_aircraft, \
        sfTrue);
        sfSprite_setPosition(spri_text->aircraft[i], pos->air_dep[i]);
    }
}

void create_tow(csfml_t *spri_text, pos_t *pos, int nbr_b)
{
    for (int i = 0 ; i < nbr_b ; i++) {
        spri_text->tower[i] = sfSprite_create();
        spri_text->circle[i] = sfCircleShape_create();
        sfCircleShape_setOutlineThickness(spri_text->circle[i], 2.0);
        sfCircleShape_setOutlineColor(spri_text->circle[i], sfGreen);
        sfCircleShape_setFillColor(spri_text->circle[i], sfTransparent);
        sfCircleShape_setRadius(spri_text->circle[i], pos->radius_tower[i]);
        sfSprite_setTexture(spri_text->tower[i], spri_text->t_tower, sfTrue);
        sfSprite_setPosition(spri_text->tower[i], pos->tower_pos[i]);
        pos->tower_pos[i].x = (pos->tower_pos[i].x - pos->radius_tower[i] + 25);
        pos->tower_pos[i].y = (pos->tower_pos[i].y - pos->radius_tower[i] + 50);
        sfCircleShape_setPosition(spri_text->circle[i], pos->tower_pos[i]);
    }
}

void create_all(csfml_t *spri_text, char *files, pos_t *pos, \
sfRenderWindow *window)
{
    int nbr_a = 0;
    int nbr_b = 0;

    my_parse(files, nbr_a, nbr_b, pos);
    number_line(files, &nbr_a, &nbr_b);
    spri_text->aircraft = malloc(sizeof(sfSprite *) * nbr_a + 1);
    spri_text->tower = malloc(sizeof(sfSprite *) * nbr_b + 1);
    spri_text->shape = malloc(sizeof(sfRectangleShape *) * nbr_a + 1);
    spri_text->circle = malloc(sizeof(sfCircleShape *) * nbr_b + 1);
    spri_text->map_s = sfSprite_create();
    sfSprite_setTexture(spri_text->map_s, spri_text->map, sfTrue);
    create_air(spri_text, pos, nbr_a);
    create_tow(spri_text, pos, nbr_b);
}