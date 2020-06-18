/*
** EPITECH PROJECT, 2020
** my_all_function
** File description:
** return
*/

#include "my.h"

void keyboardescape(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
        sfRenderWindow_close(window);
}

void destroy_all(sfRenderWindow *window, csfml_t *spri_text, char *files)
{
    int nbr_a = 0;
    int nbr_b = 0;

    number_line(files, &nbr_a, &nbr_b);
    sfRenderWindow_destroy(window);
    for (int i = 0 ; i < nbr_a ; i++) {
        sfSprite_destroy(spri_text->aircraft[i]);
        sfRectangleShape_destroy(spri_text->shape[i]);
    }
    sfTexture_destroy(spri_text->map);
    for (int i = 0 ; i < nbr_b ; i++) {
        sfSprite_destroy(spri_text->tower[i]);
        sfCircleShape_destroy(spri_text->circle[i]);
    }
    sfSprite_destroy(spri_text->map_s);
    sfTexture_destroy(spri_text->t_aircraft);
    sfTexture_destroy(spri_text->t_tower);
}