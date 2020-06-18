/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** return
*/

int my_getnbr(char const *str, int *index)
{
    int i = *index;
    int nbr = 0;
    int daisy = 1;

    for (; str[i] < '0' || str[i] > '9' ; i++, *index += 1) {
        if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
            daisy = daisy * (-daisy);
        if (str[i] == '\0') break;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10;
            nbr = nbr + str[i] - '0';
            i++;
            *index += 1;
        }
        else
            return (nbr * daisy);
    }
    return (nbr * daisy);
}
