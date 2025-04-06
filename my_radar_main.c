/*
** EPITECH PROJECT, 2024
** B-MUL-100-BAR-1-1-myradar-keigan.baldwin
** File description:
** my_radar_main
*/

#include "my_radar.h"


sfRenderWindow *make_window(void)
{
    sfRenderWindow *new;
    sfVideoMode video_mode;

    video_mode.width = 1920;
    video_mode.height = 1080;
    video_mode.bitsPerPixel = 32;
    new = sfRenderWindow_create(video_mode, "MyWindow", sfDefaultStyle, NULL);
    return new;
}

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ)
        sfRenderWindow_close(window);
}

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setOutlineThickness(circle, 1.0);
    sfCircleShape_setFillColor(circle, sfBlue);
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOrigin(circle, (sfVector2f){radius, radius});
    return circle;
}

static void dis_plane(plane_t *plane, sfRenderWindow *window)
{
    while (plane) {
        if (plane->is_active) {
        sfRenderWindow_drawSprite(window, plane->plane, NULL);
        sfRenderWindow_drawRectangleShape(window, plane->plane_shape, NULL);
        }
        plane = plane->next;
    }
}

static void dis_tower(tower_t *tower, sfRenderWindow *window)
{
    sfVector2f pos;
    float radius;
    sfCircleShape *c;

    while (tower) {
        pos = (sfVector2f){tower->x_pos, tower->y_pos};
        radius = tower->radius;
        c = create_circle(pos, radius);
        sfRenderWindow_drawCircleShape(window, c, NULL);
        tower = tower->next;
    }
}

static void all_inactive(plane_t *plane, sfRenderWindow *window)
{
    sfVector2f pos;
    float radius;
    sfCircleShape *c;

    while (plane) {
        if (plane->is_active)
            return;
        plane = plane->next;
    }
    sfRenderWindow_close(window);
}

void display(main_info_t *info, sfRenderWindow *window)
{
    dis_tower(info->tower_head, window);
    dis_plane(info->plane_head, window);
    all_inactive(info->plane_head, window);
    sfRenderWindow_display(window);
}

int main(int argc, char **argv)
{
    sfRenderWindow *window = make_window();
    main_info_t *info = file_to_struct(argv[1]);
    sfEvent event;

    make_sprites(info);
    sfRenderWindow_setFramerateLimit(window, 140);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfWhite);
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event);
        }
        move_plane(info);
        check_crash(info);
        display(info, window);
    }
    free_info(info);
}
