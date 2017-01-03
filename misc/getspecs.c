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

void getspecs(char *name, t_wolf *data)
{
  int count;
  int start;

  count = -1;
  while (name[++count] != 'x')
    ;
  data->x = my_get_nbr(selectstr(name, 0, count - 1));
  count++;
  start = count;
  while (name[count] <= 57 && name[count] >= 48)
    count++;
  data->y = my_get_nbr(selectstr(name, start, count - 1));
}