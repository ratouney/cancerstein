/*
** my_draw_line.c for project in wolf3d
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Mon Jan 02 17:43:46 2017 ratouney
** Last update Mon Jan 02 17:43:46 2017 ratouney
*/

#include "wolf3d.h"

void my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
                  sfVector2i to, sfColor color)
{
    float xc;
    float x;
    float yc;
    float y;
    float count;
    float d;

    xc = to.x - from.x;
    yc = to.y - from.y;
    count = 0.99 / sqrt((xc * xc) + (yc * yc));
    d = 0;
    while (d <= 1)
    {
        x = from.x + xc * d;
        y = from.y + yc * d;
        my_put_pixel(framebuffer, x, y, color);
        d += count;
    }
}
