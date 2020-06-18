/*
** EPITECH PROJECT, 2019
** my_put_array
** File description:
** return
*/

#include <stdlib.h>
#include <stddef.h>

void my_putchar(char);

void my_put_array(char **str)
{
    int i = 0;
    int index = 0;

    while (str[index] != NULL) {
        for (i = 0 ; str[index][i] != '\0' ; i++){
            my_putchar(str[index][i]);
        }
        index++;
        i = 0;
        my_putchar('\n');
    }
}