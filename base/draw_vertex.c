/*
** draw_vertex.c for adv in /home/ratouney/bswireframe/adv
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Mon Dec 05 15:21:50 2016 ratouney
** Last update Mon Dec  5 16:49:13 2016 John Doe
*/

#include "wolf3d.h"

void		draw_vertex(t_my_framebuffer *buffer, t_vertex *data)
{
  float xc;
  float yc;
  float count;
  float d;
  sfColor color;

  xc = data->to.x - data->from.x;
  yc = data->to.y - data->from.y;
  count = 1.0 / sqrt ((xc * xc) + (yc * yc));
  d = 0;
  while (d <= 1)
  {
    float x = data->from.x + xc * d;
    float y =  data->from.y + yc *d;
    color = colorgen((data->srccol.r-data->descol.r) * d,
    (data->srccol.g-data->descol.g) * d,
    (data->srccol.b-data->descol.b) * d, 255);
    my_put_pixel(buffer, x, y, color);
    d += count * 0.9;
  }
}
