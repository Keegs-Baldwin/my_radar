/*
** EPITECH PROJECT, 2024
** B-MUL-100-BAR-1-1-myradar-keigan.baldwin
** File description:
** make_sprites
*/

#include "my_radar.h"

static double get_angle(double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;

    return atan2(dy, dx);
}

static void fill_plane(plane_t *cur, sfTexture *texture)
{
    double angle;
    double angle_degrees;
    sfVector2f pos;

    angle = get_angle(cur->start_x, cur->start_y, cur->end_x, cur->end_y);
    angle_degrees = angle * (180.0 / 3.14159265359);
    cur->plane = sfSprite_create();
    sfSprite_setTexture(cur->plane, texture, sfTrue);
    sfSprite_setPosition(cur->plane, (sfVector2f){cur->start_x, cur->start_y});
    sfSprite_setScale(cur->plane, (sfVector2f){0.05f, 0.05f});
    cur->plane_shape = sfRectangleShape_create();
    pos = (sfVector2f){cur->start_x, cur->start_y};
    sfRectangleShape_setOutlineColor(cur->plane_shape, sfRed);
    sfRectangleShape_setOutlineThickness(cur->plane_shape, 2.0f);
    sfRectangleShape_setFillColor(cur->plane_shape, sfTransparent);
    sfRectangleShape_setSize(cur->plane_shape, (sfVector2f){20, 20});
    sfRectangleShape_setPosition(cur->plane_shape, pos);
}

static void make_plane(plane_t *head)
{
    plane_t *cur = head;
    sfTexture *texture = sfTexture_createFromFile("plane.png", NULL);

    if (!texture) {
        write(2, "bad\n", 4);
        exit(84);
    }
    while (cur != NULL) {
        fill_plane(cur, texture);
        cur = cur->next;
    }
}

void make_sprites(main_info_t *info)
{
    make_plane(info->plane_head);
}
