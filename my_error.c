/*
** EPITECH PROJECT, 2020
** error
** File description:
** return
*/

#include "my.h"

int my_error(char *files)
{
    char **buf = read_script(files);

    for (int i = 0 ; buf[i] != NULL ; i++) {
        if (buf[i][0] != 'T' && buf[i][0] != 'A') return (84);
        for (int index = 1 ; buf[i][index] ; index++) {
            if ((buf[i][index] < '0' || buf[i][index] > '9') && \
            buf[i][index] != ' ') return (84);
        }
    }
    my_free_array(buf);
    return (0);
}

int number_error(char *files)
{
    char **buf = read_script(files);
    int k = 0;

    for (int i = 0 ; buf[i] != NULL ; i++) {
        for (int index = 0 ; buf[i][index] ; index++)
        if (buf[i][index] == ' ' && buf[i][index + 1] >= '0') k += 1;
        if (buf[i][0] == 'A' && k != 6) return (84);
        if (buf[i][0] == 'T' && k != 3) return (84);
        k = 0;
    }
    my_free_array(buf);
    return (0);
}