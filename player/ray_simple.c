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

void raycast(t_wolf *data, t_ray *ray)
{
  float x;
  float y;
  float angle = ray->angle;
  float draw;

  x = rayhoriz(data, ray->x, ray->y, angle);
  y = rayvert(data, ray->x, ray->y, angle);

  if (x == -1)
    draw = y;
  else if (y == -1)
    draw = x;
  else if (x >= y)
    draw = y;
  else if (y > x)
    draw = x;

  ray->distance = draw;
}