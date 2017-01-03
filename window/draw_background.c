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

void draw_background(t_my_framebuffer *buffer)
{
  int count;
  int cunt;
  t_vertex *vertex;
  sfVector2i up;
  sfVector2i mid;
  sfVector2i ground;
  count = 0;
  while (count < SCREEN_WIDTH)
  {
    up = dotgen(count, 0);
    mid = dotgen(count, SCREEN_HEIGHT / 2);
    ground = dotgen(count, SCREEN_HEIGHT);
    my_draw_line(buffer, up, mid, sfGreen);
    vertex = vertex_gen(mid, ground, sfYellow, sfBlack);
    draw_vertex(buffer, vertex);
    count++;
  }
}