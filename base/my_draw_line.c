/*
** my_draw_line.c for adv in /home/ratouney/bswireframe/adv
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Nov 27 16:13:18 2016 ratouney
** Last update Wed Dec  7 14:50:32 2016 John Doe
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
  count = 0.99 / sqrt ((xc * xc) + (yc * yc));
	d = 0;
  while (d <= 1)
  {
    x = from.x + xc * d;
    y =  from.y + yc *d;
    my_put_pixel(framebuffer, x, y, color);
    d += count;
  }
}

void my_draw_line_opti(t_my_framebuffer *framebuffer, sfVector2i *from,
		  sfVector2i *to, sfColor color)
{
  float xc;
  float x;
  float yc;
  float y;
  float count;
  float d;

	xc = to->x - from->x;
	yc = to->y - from->y;
  count = 1.0 / sqrt ((xc * xc) + (yc * yc));
	d = 0;
  while (d <= 1)
  {
    x = from->x + xc * d;
    y =  from->y + yc *d;
    my_put_pixel(framebuffer, x, y, color);
    d += count;
  }
}
