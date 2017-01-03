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

t_wolf *setmap(char *path)
{
  t_wolf *data;
  char *buffer;
  char **tab;
  int count;
  int lines;
  int start;

  data = malloc(sizeof(t_wolf));
  buffer = load_file_in_mem(path);
  getspecs(path, data);
  tab = malchartab(data->x, data->y);
  count = 0;
  lines = 0;
  while (lines < data->y)
  {
    start = count;
    while (buffer[count] != '\0' && buffer[count] != '\n')
      count++;
    tab[lines] = selectstr(buffer, start, count - 1);
    count++;
    lines++;
  }
  data->map = tab;
  data->toggle_map = MAP;
  return (data);
}