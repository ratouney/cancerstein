/*
** colorgen.c for adv in /home/ratouney/bswireframe/adv
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Nov 27 16:16:42 2016 ratouney
** Last update Sun Nov 27 16:17:12 2016 John Doe
*/

#include "wolf3d.h"

sfColor				colorgen(int r, int g, int b, int a)
{
  sfColor		color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
	return (color);
}
