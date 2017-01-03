/*
** moveforward.c for CancersteinxD in /home/ratouney/GRAPH/bswolf3d
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Nov 20 11:36:28 2016 ratouney
** Last update Mon Dec 12 10:46:59 2016 John Doe
*/

#include "wolf3d.h"

sfVector2f move_forward(sfVector2f pos, float direction, float distance)
{
    sfVector2f yolo;
    float angle = player->angle;
    float xmod = distance * cos(angle);
    float ymod = distance * sin(angle);

    float newpos_x = player->x + xmod;
    float newpos_y = player->y - ymod;

    if (data->map[(int)newpos_y][(int)newpos_x] == '0')
    {
        player->x = newpos_x;
        player->y = newpos_y;
        player->angle = angle;
    }
    yolo.x = 42;
    yolo.y = 42;
    return (yolo);
}