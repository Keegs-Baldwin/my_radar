/*
** EPITECH PROJECT, 2025
** B-MUL-100-BAR-1-1-myradar-keigan.baldwin
** File description:
** ckeck_crash
*/

#include "my_radar.h"

static void check_square_overlap(plane_t *plane1, plane_t *plane2)
{
    float left1 = plane1->cur_pos_x;
    float right1 = plane1->cur_pos_x + 20;
    float top1 = plane1->cur_pos_y;
    float bottom1 = plane1->cur_pos_y + 20;
    float left2 = plane2->cur_pos_x;
    float right2 = plane2->cur_pos_x + 20;
    float top2 = plane2->cur_pos_y;
    float bottom2 = plane2->cur_pos_y + 20;

    if (plane1->in_safezone == 1 || plane2->in_safezone == 1)
        return;
    if (plane1->is_active == 0 || plane2->is_active == 0)
        return;
    if (left1 < right2 && right1 > left2 && top1 < bottom2 && bottom1 > top2) {
        plane1->is_active = 0;
        plane2->is_active = 0;
    }
}

static void in_tower(tower_t *head, float x, float y, plane_t *plane)
{
    float d_x;
    float d_y;

    while (head) {
        d_x = head->x_pos - x;
        d_y = head->y_pos - y;
        if (sqrt(d_x * d_x + d_y * d_y) <= head->radius) {
            plane->in_safezone = 1;
            return;
        }
        head = head->next;
    }
    plane->in_safezone = 0;
}

static void check_safe(plane_t *p_head, tower_t *t_head)
{
    tower_t *t_cur = t_head;
    float x_mid;
    float y_mid;

    while (p_head) {
        x_mid = p_head->cur_pos_x + 10;
        y_mid = p_head->cur_pos_y + 10;
        in_tower(t_head, x_mid, y_mid, p_head);
        p_head = p_head->next;
    }
}

void check_crash(main_info_t *info)
{
    plane_t *cur = info->plane_head;
    plane_t *slide = cur->next;

    check_safe(info->plane_head, info->tower_head);
    while (cur) {
        if (cur->is_active == 0) {
            cur = cur->next;
            continue;
        }
        slide = cur->next;
        while (slide) {
            check_square_overlap(cur, slide);
            slide = slide->next;
        }
        cur = cur->next;
    }
}

// sfSprite *load_sprite(const char* file)
// {
//     sfTexture *texture = sfTexture_createFromFile(file);
//     sfSprite *sprite = sfSprite_create();
//     sfSprite_setTexture(sprite, texture, sfFalse);
//     return sprite;
// }
