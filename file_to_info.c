/*
** EPITECH PROJECT, 2024
** B-MUL-100-BAR-1-1-myradar-keigan.baldwin
** File description:
** file_to_info
*/

#include "my_radar.h"


static int read_int(FILE *file)
{
    char buffer[20];
    int i = 0;
    char c;

    while (fread(&c, 1, 1, file) == 1 && c != ' ' && c != '\n') {
        if (i < 19) {
            buffer[i] = c;
            i++;
        }
    }
    buffer[i] = '\0';
    return atoi(buffer);
}

static float get_dist(int x1, int y1, int x2, int y2)
{
    float x = x2 - x1;
    float y = y2 - y1;

    return sqrt(x * x + y * y);
}

static plane_t *fill_basics(FILE *file, main_info_t *info)
{
    plane_t *new = malloc(sizeof(plane_t));
    float dist;

    new->start_x = read_int(file);
    new->start_y = read_int(file);
    new->cur_pos_x = new->start_x;
    new->cur_pos_y = new->start_y;
    new->elap_time = 0.0;
    new->is_active = 1;
    new->end_x = read_int(file);
    new->end_y = read_int(file);
    dist = get_dist(new->start_x, new->start_y, new->end_x, new->end_y);
    new->speed = dist / read_int(file);
    new->start = read_int(file);
    new->next = NULL;
    return new;
}

static void file_to_plane(FILE *file, main_info_t *info)
{
    plane_t *cur;
    plane_t *new = fill_basics(file, info);

    if (info->plane_head == NULL) {
        info->plane_head = new;
        return;
    }
    cur = info->plane_head;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = new;
}

static void file_to_tower(FILE *file, main_info_t *info)
{
    int read_size = sizeof(tower_t) - sizeof(tower_t *);
    tower_t *cur;
    tower_t *new = malloc(sizeof(tower_t));

    new->x_pos = read_int(file);
    new->y_pos = read_int(file);
    new->radius = read_int(file);
    new->next = NULL;
    if (info->tower_head == NULL) {
        info->tower_head = new;
        return;
    }
    cur = info->tower_head;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = new;
}

static void make_info_null(main_info_t *info)
{
    info->frame_time = sfClock_create();
    info->time = sfClock_create();
    info->plane_head = NULL;
    info->tower_head = NULL;
}

main_info_t *file_to_struct(char *file_path)
{
    FILE *file = fopen(file_path, "rb");
    main_info_t *main_info = malloc(sizeof(main_info_t));
    char type;
    char bin;

    make_info_null(main_info);
    if (file == NULL) {
        write(2, "Error opening file", 19);
        exit(84);
    }
    while (fread(&type, 1, 1, file) == 1) {
        fread(&bin, 1, 1, file);
        if (type == 'A')
            file_to_plane(file, main_info);
        if (type == 'T')
            file_to_tower(file, main_info);
    }
    fclose(file);
    return main_info;
}
