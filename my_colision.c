/*
** EPITECH PROJECT, 2020
** show
** File description:
** return
*/

#include "my.h"

void colision_plane(pos_t *pos, char *files, int *i)
{
    int nbr_a = 0;
    int nbr_b = 0;
    number_line(files, &nbr_a, &nbr_b);
    for (int j = 0 ; j < nbr_a ; j++) {
        colision_calcul(pos, i, &j);
    }
}

void colision_calcul(pos_t *pos, int *i, int *j)
{
    if ((pos->air_dep[*i].x > pos->air_dep[*j].x && \
    pos->air_dep[*i].x < pos->air_dep[*j].x + 20) || \
    (pos->air_dep[*j].x > pos->air_dep[*i].x && \
    pos->air_dep[*j].x < pos->air_dep[*i].x + 20)) {
        if ((pos->air_dep[*i].y > pos->air_dep[*j].y && \
        pos->air_dep[*i].y < pos->air_dep[*j].y + 20) || \
        (pos->air_dep[*j].y > pos->air_dep[*i].y && \
        pos->air_dep[*j].y < pos->air_dep[*i].y + 20)) {
            pos->time_d[*i] = pos->time[*i].microseconds / 1000000;
            pos->time_d[*j] = pos->time[*j].microseconds / 1000000;
            pos->air_dep[*i].x = 0;
            pos->air_dep[*i].y = 0;
            pos->air_dep[*j].x = 0;
            pos->air_dep[*j].y = 0;
        }
    }
}