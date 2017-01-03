/*
** altmain.c for rework_wireframe in /home/ratouney/bswireframe
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Nov 20 11:36:28 2016 ratouney
** Last update Mon Dec 12 10:46:59 2016 John Doe
*/

#include "wolf3d.h"

void placefov(t_wolf *data, t_pos *player, t_my_framebuffer *buffer, int scale)
{
  sfVector2i plpos;
  sfVector2i wall;
  float ct;
  t_ray ray;

  ct = -(FOV / 2);
  ray.x = player->x;
  ray.y = player->y;
  while (ct < (FOV / 2))
  {
    ray.angle = player->angle + TO_RAD(ct);
    raycast(data, &ray);
    plpos = dotgen(player->x * scale, player->y * scale);
    wall = dotgen((ray.x + (ray.distance * cos(ray.angle))) * scale,
     (ray.y - (ray.distance * sin(ray.angle))) * scale);
    my_draw_line(buffer, plpos, wall, sfRed);
    ct += 1;
  }
}

void drawmap(t_wolf *data, t_my_framebuffer *buffer, t_pos *player, int scale)
{
  int count;
  int cunt;
  sfVector2i pos;
  sfVector2i pldot;
  sfColor grey;

  grey = colorgen(120, 120, 120, 255);
  count = -1;
  while (++count < data->y)
  {
    cunt = -1;
    while (++cunt < data->x)
    {
      pos = dotgen(count * scale, cunt * scale);
      drawsquare(buffer, &pos, scale,
      (data->map[count][cunt] == '1') ? grey : sfBlack);
    }
  }
  placefov(data, player, buffer, scale);
}
