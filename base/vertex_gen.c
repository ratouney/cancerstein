/*
** vertex_gen.c for adv in /home/ratouney/bswireframe/adv
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Mon Dec 05 15:34:41 2016 ratouney
** Last update Mon Dec  5 16:09:04 2016 John Doe
*/

#include "wolf3d.h"

t_vertex			*vertex_gen(sfVector2i source, sfVector2i destination,
					    						sfColor src, sfColor org)
{
	t_vertex		*data;

  data = malloc(sizeof(t_vertex));
  data->from = source;
  data->to = destination;
  data->srccol = src;
  data->descol = org;
  return (data);
}
