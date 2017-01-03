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

void draw_wall(t_wolf *data, t_pos *player, t_my_framebuffer *buffer, int scale)
{
  sfVector2i plpos;
  sfVector2i wall;
  sfVector2i wall_up;
  sfVector2i wall_down;
  float count;
  float height;
  float corrector;
  t_ray ray;

  ray.x = player->x + 0 * (ray.y = player->y) + 0 * (count = (FOV / 2));
  while (count > -(FOV / 2))
  {
    ray.angle = player->angle + TO_RAD(count);
    raycast(data, &ray);
    height = FOCAL / (ray.distance * dot_pr(player, ray.angle));
    wall_up = dotgen((SCREEN_WIDTH - (SCREEN_WIDTH / FOV) * (count + (FOV / 2))), (SCREEN_HEIGHT / 2) - (height / 2));
    wall_down = dotgen((SCREEN_WIDTH - (SCREEN_WIDTH / FOV) * (count + (FOV / 2))), (SCREEN_HEIGHT / 2) + (height / 2));
    if (wall_down.y - wall_up.y > SCREEN_HEIGHT)
      wall_up.y = 0 + 0 * (wall_down.y = SCREEN_HEIGHT);
    my_draw_line(buffer, wall_up, wall_down, sfBlue);
    count -= FOV / SCREEN_WIDTH;
  }
}

void playertoggle(t_wolf *data, t_pos *player, t_my_framebuffer *buffer)
{
  if (data->toggle_map == 1)
    drawmap(data, buffer, player, 13);
  if (player->moving == 1)
    moveplayer(player, data, MOVEMENT);
  if (player->moving == -1)
    moveplayer(player, data, -MOVEMENT);
  if (player->strafing == -1)
    strafeplayer(player, data, MOVEMENT, M_PI / 2 * -1);
  if (player->strafing == 1)
    strafeplayer(player, data, MOVEMENT, M_PI / 2);
}

t_pos setplayer(int argc, char **argv, t_pos *player)
{
  player->x = atof(argv[2]);
  player->y = atof(argv[3]);
  if (argc == 4)
    player->angle = 0.01;
  if (argc == 5)
    player->angle = TO_RAD(my_get_nbr(argv[4]));
}

void mouseloop(t_var *var, t_pos *player)
{
  static sfVector2i mouse;
  static sfVector2i prev;

  mouse = sfMouse_getPosition((sfWindow *)var->window);
  if (mouse.x > prev.x)
    player->angle -= TO_RAD(SCREEN_WIDTH / 360);
  if (mouse.x < prev.x)
    player->angle += TO_RAD(SCREEN_WIDTH / 360);
  if (mouse.x > SCREEN_WIDTH)
    player->angle -= TO_RAD(SCREEN_WIDTH / 360);
  if (mouse.x < 0)
    player->angle += TO_RAD(SCREEN_WIDTH / 360);
  prev = mouse;
}

int main(int argc, char **argv)
{
  t_wolf *data;
  t_var *var;
  t_pos *player;
  sfEvent event;
  t_my_framebuffer buffer;

  data = setmap(argv[1]);
  var = malloc(sizeof(t_var));
  player = malloc(sizeof(t_pos));
  setplayer(argc, argv, player);
  setvar(var, buffer);
  buffer = create_buffer_struct(SCREEN_WIDTH, SCREEN_HEIGHT);
  while (sfRenderWindow_isOpen(var->window))
  {
    mouseloop(var, player);
    keyloop(var, event, player, data);
    draw_background(&buffer);
    draw_wall(data, player, &buffer, 20);
    drawmap(data, &buffer, player, 13);
    playertoggle(data, player, &buffer);
    updatepixels(&buffer, var);
  }
  return (0);
}
