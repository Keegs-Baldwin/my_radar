/*
** EPITECH PROJECT, 2025
** B-MUL-100-BAR-1-1-myradar-keigan.baldwin
** File description:
** free
*/

#include "my_radar.h"

static void free_tower(tower_t *head)
{
    tower_t *next;

    while (head) {
        next = head->next;
        free(head);
        head = next;
    }
}

static void free_plane(plane_t *head)
{
    plane_t *next;

    while (head) {
        next = head->next;
        if (head->plane_shape != NULL)
            sfRectangleShape_destroy(head->plane_shape);
        if (head->plane != NULL)
            sfSprite_destroy(head->plane);
        head = next;
    }
}

void free_info(main_info_t *info)
{
    free_tower(info->tower_head);
    free_plane(info->plane_head);
    sfClock_destroy(info->time);
    sfClock_destroy(info->frame_time);
    free(info);
}
