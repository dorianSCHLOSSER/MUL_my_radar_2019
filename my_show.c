/*
** EPITECH PROJECT, 2020
** show
** File description:
** return
*/

#include "my.h"

void show_texture(csfml_t *texture, char *files)
{
    int nbr_a = 0;
    int nbr_b = 0;
    number_line(files, &nbr_a, &nbr_b);
    texture->map = sfTexture_createFromFile("map.jpg", NULL);
    texture->t_aircraft = sfTexture_createFromFile("aircraft.png", NULL);
    texture->t_tower = sfTexture_createFromFile("tower.png", NULL);
    texture->hitbox = sfTexture_createFromFile("hitbox.png", NULL);
}

void my_calcul_pos(csfml_t *spri_text, pos_t *pos, char *files)
{
    int nbr_a = 0;
    int nbr_b = 0;

    number_line(files, &nbr_a, &nbr_b);
    for (int i = 0 ; i < nbr_a ; i++) {
        pos->distance[i].x = (pos->air_arr[i].x - pos->air_dep[i].x);
        pos->distance[i].y = (pos->air_arr[i].y - pos->air_dep[i].y);
        pos->longer[i] = pow(pow(pos->distance[i].x, 2) + \
        pow(pos->distance[i].y, 2), 0.5);
        pos->time_d[i] = (pos->longer[i] / pos->air_speed[i]);
        pos->speed[i].x = (pos->distance[i].x / pos->time_d[i]) / 60.0;
        pos->speed[i].y = (pos->distance[i].y / pos->time_d[i]) / 60.0;
    }
}

void my_calcul(csfml_t *spri_text, pos_t *pos, int *i)
{
    if (pos->time[*i].microseconds / 1000000.0 < pos->time_d[*i]) {
        if (pos->air_dep[*i].x > pos->air_arr[*i].x)
            pos->air_dep[*i].x += pos->speed[*i].x;
        if (pos->air_dep[*i].x < pos->air_arr[*i].x)
            pos->air_dep[*i].x += pos->speed[*i].x;
        if (pos->air_dep[*i].y < pos->air_arr[*i].y)
            pos->air_dep[*i].y += pos->speed[*i].y;
        if (pos->air_dep[*i].y > pos->air_arr[*i].y)
            pos->air_dep[*i].y += pos->speed[*i].y;
    }
}

void draw_all(sfRenderWindow *window, csfml_t *spri_text, \
char *files, pos_t *pos)
{
    int nbr_a = 0;
    int nbr_b = 0;
    number_line(files, &nbr_a, &nbr_b);
    sfRenderWindow_drawSprite(window, spri_text->map_s, NULL);
    pos->time_all = sfClock_getElapsedTime(pos->clock_all);
    for (int i = 0 ; i < nbr_a ; i++)
        if (pos->time_all.microseconds / M < pos->air_second[i])
            sfClock_restart(pos->clock[i]);
    for (int i = 0 ; i < nbr_a ; i++) {
        if (pos->time_all.microseconds / M > pos->air_second[i]) {
        pos->time[i] = sfClock_getElapsedTime(pos->clock[i]);
        sfSprite_setPosition(spri_text->aircraft[i], pos->air_dep[i]);
        sfRectangleShape_setPosition(spri_text->shape[i], pos->air_dep[i]);
        my_calcul(spri_text, pos, &i);
        colision_plane(pos, files, &i);
            if (pos->time[i].microseconds / M < pos->time_d[i]) {
            sfRenderWindow_drawRectangleShape(window, spri_text->shape[i], 0);
            sfRenderWindow_drawSprite(window, spri_text->aircraft[i], NULL);
        }
    }
    }
    for (int i = 0 ; i < nbr_b ; i++) {
        sfRenderWindow_drawCircleShape(window, spri_text->circle[i], NULL);
        sfRenderWindow_drawSprite(window, spri_text->tower[i], NULL);
    }
}

