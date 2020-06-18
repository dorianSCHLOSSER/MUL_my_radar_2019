/*
** EPITECH PROJECT, 2020
** my_parsing
** File description:
** return
*/

#include "my.h"

void my_parse(char *files, int ind_a, int ind_b, pos_t *pos)
{
    char **buf = read_script(files);
    malloc_struct(files, pos);
    for (int i = 0; buf[i] != NULL; i++) {
        for (int ind = 0 ; buf[i][ind] ; ind++) {
            if (buf[i][ind] == 'A' && ind == 0) {
                pos->aircraft[ind_a] = 'A';
                pos->air_dep[ind_a].x = my_getnbr(buf[i], &ind);
                pos->air_dep[ind_a].y = my_getnbr(buf[i], &ind);
                pos->air_arr[ind_a].x = my_getnbr(buf[i], &ind);
                pos->air_arr[ind_a].y = my_getnbr(buf[i], &ind);
                pos->air_speed[ind_a] = my_getnbr(buf[i], &ind);
                pos->air_second[ind_a] = my_getnbr(buf[i], &ind);
                ind_a += 1;
            }
            if (buf[i][ind] == 'T' && ind == 0) {
                pos->tower[ind_b] = 'T';
                pos->tower_pos[ind_b].x = my_getnbr(buf[i], &ind);
                pos->tower_pos[ind_b].y = my_getnbr(buf[i], &ind);
                pos->radius_tower[ind_b] = my_getnbr(buf[i], &ind);
                ind_b += 1;
            }
        }
    }
    create_clock(pos, files);
    my_free_array(buf);
}

void malloc_struct(char *files, pos_t *pos)
{
    int nbr_a = 0;
    int nbr_b = 0;
    number_line(files, &nbr_a, &nbr_b);
    pos->tower = malloc(sizeof(char) * nbr_b + 1);
    pos->radius_tower = malloc(sizeof(int) * nbr_b + 1);
    pos->tower_pos = malloc(sizeof(sfVector2f) * nbr_b + 1);
    pos->aircraft = malloc(sizeof(char) * nbr_a + 1);
    pos->air_arr = malloc(sizeof(sfVector2f) * nbr_a + 1);
    pos->air_dep = malloc(sizeof(sfVector2f) * nbr_a + 1);
    pos->air_speed = malloc(sizeof(float) * nbr_a + 1);
    pos->air_second = malloc(sizeof(float) * nbr_a + 1);
    pos->time_d = malloc(sizeof(float) * nbr_a + 1);
    pos->distance = malloc(sizeof(sfVector2f) * nbr_a + 1);
    pos->longer = malloc(sizeof(float) * nbr_a + 1);
    pos->speed = malloc(sizeof(sfVector2f) * nbr_a + 1);
    pos->clock = malloc(sizeof(sfClock *) * nbr_a + 1);
}

void create_clock(pos_t *pos, char *files)
{
    int nbr_a = 0;
    int nbr_b = 0;
    number_line(files, &nbr_a, &nbr_b);
    pos->clock_all = sfClock_create();
    pos->time = malloc(sizeof(sfTime *) * nbr_a + 1);
    for (int i = 0 ; i < nbr_a ; i++) {
        pos->clock[i] = sfClock_create();
    }
}

char **read_script(char *files)
{
    int fd = open(files, O_RDONLY);
    char *buf = NULL;
    char **str = NULL;
    char c;
    int index = 0;

    while (read(fd, &c, 1) != 0) index += 1;
    close(fd);
    buf = m_malloc(index + 2);
    fd = open(files, O_RDONLY);
    read(fd, buf, index);
    close(fd);
    str = my_str_to_word_array(buf, '\n');
    free(buf);
    return (str);
}

void number_line(char *files, int *nbr_a, int *nbr_b)
{
    char **buf = read_script(files);

    for (int i = 0 ; buf[i] != NULL ; i++) {
        if (buf[i][0] == 'A') *nbr_a += 1;
        if (buf[i][0] == 'T') *nbr_b += 1;
    }
    my_free_array(buf);
}