/*
** EPITECH PROJECT, 2019
** my_free_array
** File description:
** return
*/

#include <stdlib.h>

void my_free_array(char **str)
{
    for (int i = 0 ; str[i] != NULL ; i++) free(str[i]);
    free(str);
}
