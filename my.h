/*
** EPITECH PROJECT, 2019
** my_h
** File description:
** return
*/

#ifndef _MY_H_
#define _MY_H_
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#define M_PI 3.14159265358979323846
#define M 1000000.0

typedef struct pos_s
{
    char *tower;
    char *aircraft;
    sfVector2f *tower_pos;
    int *radius_tower;
    sfVector2f *air_dep;
    sfVector2f *air_arr;
    float *air_speed;
    float *air_second;
    sfVector2f *distance;
    float *time_d;
    float *longer;
    sfVector2f *speed;
    sfClock **clock;
    sfTime *time;
    sfClock *clock_all;
    sfTime time_all;
} pos_t;

typedef struct index_s
{
    int ind_t;
    int ind_a;
} index_t;

typedef struct csfml_s
{
    sfSprite **tower;
    sfSprite **aircraft;
    sfRectangleShape **shape;
    sfCircleShape **circle;
    sfSprite *map_s;
    sfTexture *hitbox;
    sfTexture *t_tower;
    sfTexture *t_aircraft;
    sfTexture *map;
} csfml_t;

void get_words(void);
int my_putstr(char const *str);
void colision_calcul(pos_t *pos, int *i, int *j);
int number_error(char *files);
int my_error(char *files);
void number_line(char *files, int *nbr_a, int *nbr_b);
void my_free_array(char **str);
int my_getnbr(char const *str, int *index);
void my_putchar(char c);
void my_put_array(char **str);
void my_putchar(char);
int my_super_strlen(char const *str);
int space(char const *str, char c);
char *m_malloc(int len);
char **malloc_array(char **word_array, char const *str, char c);
char **my_str_to_word_array(char const *str, char c);
void keyboardescape(sfRenderWindow *window, sfEvent *event);
void destroy_all(sfRenderWindow *window, csfml_t *spri_text, char *files);
int principal_win(char *files);
void show_texture(csfml_t *texture, char *files);
void show_sprite(csfml_t *sprite);
char **read_script(char *files);
void malloc_struct(char *files, pos_t *pos);
void my_parse(char *files, int ind_a, int ind_b, pos_t *pos);
void create_all(csfml_t *spri_text, char *files, pos_t *pos, \
sfRenderWindow *window);
void draw_all(sfRenderWindow *window, csfml_t *spri_text, \
char *files, pos_t *pos);
void my_calcul(csfml_t *spri_text, pos_t *pos, int *i);
void my_calcul_pos(csfml_t *spri_text, pos_t *pos, char *files);
void create_clock(pos_t *pos, char *files);
void colision_plane(pos_t *pos, char *files, int *i);
void create_air(csfml_t *spri_text, pos_t *pos, int nbr_a);
void create_tow(csfml_t *spri_text, pos_t *pos, int nbr_b);

#endif