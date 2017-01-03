/*
** my_put_pixel.c for adv in /home/ratouney/bswireframe/adv
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Nov 27 16:10:52 2016 ratouney
** Last update Mon Dec 12 10:51:14 2016 John Doe
*/

#include "wolf3d.h"

void my_put_pixel(t_my_framebuffer *framebuffer, int x, int y, sfColor color)
{
  if (x > framebuffer->width - 1 || x < 0 ||
   y > framebuffer->height - 1 || y < 0)
      return ;
  framebuffer->pixels[(framebuffer->width *y +x) * 4] = color.r;
  framebuffer->pixels[(framebuffer->width *y +x) * 4 + 1] = color.g;
  framebuffer->pixels[(framebuffer->width *y +x) * 4 + 2] = color.b;
  framebuffer->pixels[(framebuffer->width *y +x) * 4 + 3] = color.a;
}
