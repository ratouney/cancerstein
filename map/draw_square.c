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

void drawsquare(t_my_framebuffer *buffer, sfVector2i *pos,
 int size, sfColor color)
{
  int count;
  int cunt;

  count = pos->y;
  while (count < pos->y + size)
  {
    cunt = pos->x;
    while (cunt < pos->x + size)
    {
      my_put_pixel(buffer, count, cunt, color);
      cunt++;
    }
    count++;
  }
}