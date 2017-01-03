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

void raycast_main(t_wolf *data, t_pos *player,
t_my_framebuffer *buffer, int scale)
{
  float x;
  float y;
  float draw;
  float angle = player->angle;
  float xmod;
  float ymod;
  sfVector2i plpos;
  sfVector2i wall;

  x = rayhoriz(data, player->x, player->y, player->angle);
  y = rayvert(data, player->x, player->y, player->angle);

  if (x == -1)
    draw = y;
  else if (y == -1)
    draw = x;
  else if (x > y)
    draw = y;
  else if (y >= x)
    draw = x;
  plpos = dotgen(player->x * scale, player->y * scale);
  xmod = draw * cos(player->angle);
  ymod = draw * sin(player->angle);
  wall = dotgen((player->x + (draw * cos(angle)))
   * scale, (player->y - (draw * sin(angle))) * scale);
  my_draw_line(buffer, plpos, wall, sfGreen);
}