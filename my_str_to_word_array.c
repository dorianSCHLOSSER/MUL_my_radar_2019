/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** return
*/

#include <stdlib.h>
#include <stddef.h>

int my_super_strlen(char const *str)
{
    int i = 0;

    for (; str[i] ; i++);
    return (i + 1);
}

int space(char const *str, char c)
{
    int space = 0;
    int k = 0;

    for (int i = 0 ; str[i] ; i++) {
        if (str[i] == c) {
            space++;
            if (str[i + 1] == c) space--;
            if (str[i + 1] == '\0') space--;
        }
    }
    return (space + 1);
}

char *m_malloc(int len)
{
    int i = 0;
    char *result = NULL;

    result = malloc(sizeof(char) * len + 1);
    for (; i < len ; i++) result[i] = 0;

    return (result);
}

char **malloc_array(char **word_array, char const *str, char c)
{
    int index = 0;
    int space1 = 0;
    int g = 0;
    int size = space(str, c);

    word_array = malloc(sizeof(char *) * (size + 2));
    for (int i = 0 ; str[i] ; i++, space1 += 1) {
        if ((str[i] == c && index <= size && str[i + 1] != c) \
            || str[i + 1] == '\0') {
            word_array[g] = m_malloc(my_super_strlen(str) + 1);
            g += 1;
            space1 = -1;
        }
    }
    return (word_array);
}

char **my_str_to_word_array(char const *str, char c)
{
    char **word_array = malloc_array(word_array, str, c);
    int index = 0;
    int j = 0;
    int size = space(str, c);
    int i = 0;

    for (; str[i] ; i++, j += 1) {
        if (str[i] != c);
            word_array[index][j] = str[i];
        if (str[i] == c && index < size && str[i + 1] != c) {
            word_array[index][j] = '\0';
            if (word_array[index][0] != '\0') index++;
            else size -= 1;
            j = -1;
        }
    }
    word_array[size] = NULL;
    return (word_array);
}