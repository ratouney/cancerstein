/*
** dotgen.c for adv in /home/ratouney/bswireframe/adv
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Nov 27 16:16:20 2016 ratouney
** Last update Sun Nov 27 16:16:27 2016 John Doe
*/

#include "wolf3d.h"

sfVector2i	dotgen(float x, float y)
{
  sfVector2i result;

  result.x = (int)x;
  result.y = (int)y;
  return (result);
}
