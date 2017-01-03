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

double dot_pr(t_pos *player, float angle)
{
  t_ray ray1, ray2;

  ray1.x = cos(player->angle);
  ray1.y = sin(player->angle);
  ray2.x = cos(angle);
  ray2.y = sin(angle);
  return (ray1.x * ray2.x + ray1.y * ray2.y);
}
