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

int rayhoriz_load(t_wolf *wolf, t_data *data)
{
  if (sin(data->angle) == 0)
    return (-1);
  else if (sin(data->angle) > 0)
    data->y = -(data->py - (int)data->py);
  else if (sin(data->angle) < 0)
    data->y = -data->py + (int)data->py + 1;
  data->x = -data->y / tan(data->angle);

  if (sin(data->angle) > 0)
    data->step_y = -1;
  else
    data->step_y = 1;
  data->step_x = -data->step_y / tan(data->angle);

  while (data->done == 1)
  {
    data->tab_y = data->py + data->y + (data->step_y * data->count);
    data->tab_x = data->px + data->x + (data->step_x * data->count);
    if (data->tab_x >= 0 && data->tab_x < wolf->x &&
     wolf->map[(int)data->tab_y][(int)data->tab_x] == '0')
      data->count++;
    else
      data->done = 0;
  }
  data->count -= 0.00001;
  return (0);
}

float rayhoriz(t_wolf *wolf, float px, float py, float angle)
{
  t_data *data;
  data = malloc(sizeof(t_data));
  data->done = 1;
  data->count = 0.00001;
  data->px = px;
  data->py = py;
  int rt;
  data->angle = angle;
  float distance;

  rt = rayhoriz_load(wolf, data);
  if (rt == -1)
    return (-1);
  data->dist_x = (px + data->x + (data->step_x * data->count) - px);
  data->dist_y = (py + data->y + (data->step_y * data->count) - py);

  distance = sqrt((data->dist_x * data->dist_x) +
  (data->dist_y * data->dist_y));

  return (distance);
}