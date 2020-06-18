/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** return
*/

#include "my.h"

int principal_win(char *files)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};
    sfEvent event;
    csfml_t spri_text;
    pos_t pos;
    window = sfRenderWindow_create(video_mode, "my_radar", \
    sfResize | sfClose, NULL);
    show_texture(&spri_text, files);
    create_all(&spri_text, files, &pos, window);
    my_calcul_pos(&spri_text, &pos, files);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfWhite);
        while (sfRenderWindow_pollEvent(window, &event))
            keyboardescape(window, &event);
        draw_all(window, &spri_text, files, &pos);
        sfRenderWindow_display(window);
    }
    destroy_all(window, &spri_text, files);
    return (0);
}