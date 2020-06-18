/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** return
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "my.h"

void get_words(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr(" ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("  path_to_script    The path to the script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr(" -h               print the usage and quit.\n");
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        my_putstr("Error: argc are not 2, retry with -h\n");
        return (84);
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        get_words();
        return (0);
    }
    if (my_error(argv[1]) == 84) {
        my_putstr("Error: Script, retry with -h\n");
        return (84);
    }
    if (number_error(argv[1]) == 84) {
        my_putstr("Error: Script, retry with -h\n");
        return (84);
    }
    principal_win(argv[1]);

    return (0);
}