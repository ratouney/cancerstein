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

void my_put_pixel(t_my_framebuffer *buffer, int x, int y, sfColor color)
{
  if (x > SCREEN_WIDTH - 1 || x < 0 || y > SCREEN_HEIGHT - 1 || y < 0)
      return ;
  buffer->pixels[(SCREEN_WIDTH * (int)y + (int)x) * 4] = color.r;
  buffer->pixels[(SCREEN_WIDTH * (int)y + (int)x) * 4 + 1] = color.g;
  buffer->pixels[(SCREEN_WIDTH * (int)y + (int)x) * 4 + 2] = color.b;
  buffer->pixels[(SCREEN_WIDTH * (int)y + (int)x) * 4 + 3] = color.a;
}
