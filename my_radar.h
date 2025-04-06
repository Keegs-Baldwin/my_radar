/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** setup
*/

#ifndef PRINTF_H_
    #define PRINTF_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <time.h>
    #include <SFML/Audio.h>
    #include <math.h>

typedef struct main_info_s main_info_t;
typedef struct node_s node_t;

typedef struct tower_s {
    int x_pos;
    int y_pos;
    int radius;
    struct tower_s *next;
} tower_t;

typedef struct plane_s {
    int is_active;
    int in_safezone;
    int start_x;
    int start_y;
    float cur_pos_x;
    float cur_pos_y;
    int end_x;
    int end_y;
    float speed;
    float elap_time;
    int start;
    sfRectangleShape *plane_shape;
    sfSprite *plane;
    struct plane_s *next;
} plane_t;

typedef struct node_s {
    void (*tick)(main_info_t *info, struct node_s *node);
    void (*click)(struct node_s element);
    struct node_s *next;
} node_t;

typedef struct main_info_s {
    tower_t *tower_head;
    plane_t *plane_head;
    sfClock *time;
    sfClock *frame_time;
} main_info_t;

//file to info
main_info_t *file_to_struct(char *file_path);

void make_sprites(main_info_t *info);
//random
int my_getnbr(char const *str);
char *my_int_to_str(int nb);
char *my_revstr(char *str);
//game over

void check_crash(main_info_t *info);
void move_plane(main_info_t *info);

//void free_info(main_info_t *info);

void game_over(main_info_t *info);
void exit_f(sfMouseButtonEvent e, main_info_t *i, sfRenderWindow *w);
void free_info(main_info_t *info);
#endif
