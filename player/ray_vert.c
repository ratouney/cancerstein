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

int rayvert_load(t_wolf *wolf, t_data *data)
{
  if (cos(data->angle) == 0)
    return (-1);
  else if (cos(data->angle) > 0)
    data->x = (int)data->px + 1 - data->px;
  else if (cos(data->angle) < 0)
    data->x = -data->px + (int)data->px;
  data->y = tan(data->angle) * -data->x;

  if (cos(data->angle) > 0)
    data->step_x = -1;
  else
    data->step_x = 1;
  data->step_y = tan(data->angle) * -data->step_x;

  while (data->done == 1)
  {
    data->tab_y = data->py + data->y - (data->step_y * data->count);
    data->tab_x = data->px + data->x - (data->step_x * data->count);
    if (data->tab_y >= 0 && data->tab_y < wolf->y &&
     wolf->map[(int)data->tab_y][(int)data->tab_x] == '0')
      data->count++;
    else
      data->done = 0;
  }
  data->count -= 0.00001;
  return (0);
}

float rayvert(t_wolf *wolf, float px, float py, float angle)
{
  t_data *data;
  data = malloc(sizeof(t_data));
  data->done = 1;
  data->count = 0.00001;
  data->px = px;
  data->py = py;
  data->angle = angle;
  int rt;
  float distance;

  rt = rayvert_load(wolf, data);
  if (rt == -1)
    return (-1);
  data->dist_x = (data->px + data->x - (data->step_x * data->count) - data->px);
  data->dist_y = (data->py + data->y - (data->step_y * data->count) - data->py);

  distance = sqrt((data->dist_x * data->dist_x) +
   (data->dist_y * data->dist_y));
  return (distance);
}