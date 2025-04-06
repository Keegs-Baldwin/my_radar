/*
** EPITECH PROJECT, 2024
** B-MUL-100-BAR-1-1-myradar-keigan.baldwin
** File description:
** move_plane
*/

#include "my_radar.h"

void move_plane(main_info_t *info)
{
    plane_t *cur = info->plane_head;
    sfVector2f move;
    float progress;
    sfTime t = sfClock_getElapsedTime(info->frame_time);
    float d_time = sfTime_asMilliseconds(t);

    sfClock_restart(info->frame_time);
    while (cur) {
        cur->elap_time += d_time;
        progress = cur->elap_time / cur->speed / 1000;
        if (progress > 1)
            cur->is_active = 0;
        cur->cur_pos_x = cur->start_x + (cur->end_x - cur->start_x) * progress;
        cur->cur_pos_y = cur->start_y + (cur->end_y - cur->start_y) * progress;
        move = (sfVector2f){cur->cur_pos_x, cur->cur_pos_y};
        sfSprite_setPosition(cur->plane, move);
        sfRectangleShape_setPosition(cur->plane_shape, move);
        cur = cur->next;
    }
}
