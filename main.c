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

  prev = dotgen(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
  mouse = sfMouse_getPosition((sfWindow *)var->window);
  if (mouse.x > prev.x)
    player->angle -= TO_RAD(SCREEN_WIDTH / 70);
  if (mouse.x < prev.x)
    player->angle += TO_RAD(SCREEN_WIDTH / 70);
  if (mouse.x > SCREEN_WIDTH)
    player->angle -= TO_RAD(SCREEN_WIDTH / 70);
  if (mouse.x < 0)
    player->angle += TO_RAD(SCREEN_WIDTH / 70);
  sfMouse_setPosition(prev,(sfWindow *)var->window);
}

t_color *colortabgen(int colors, int space)
{
  t_color data[colors];
  int count;

  count = 0;
  //data = malloc(sizeof(t_color *) * colors);
  while (count < colors)
  {
    data[count].r = 2;
    //data[count] = malloc(sizeof(t_color));
    //data[count]->tag = malloc(sizeof(char) * space);
    count++;
  }
  return (data);
}

void draw_menu(t_var *var, t_my_framebuffer *buffer)
{
  int fd;
  char *line;

  fd = open("bite.xpm", O_RDONLY);
  get_next_line(fd);
  get_next_line(fd);
  line = get_next_line(fd);
  printf("Config : %s\n", line);

  int count = 1;
  int save;
  int x;
  int y;
  int colors;
  int space;
  while (line[count] >= '0' && line[count] <= '9')
    count++;
  x = atoi(selectstr(line, 1, count - 1));
  printf("X : %d\n", x);
  count++;
  save = count;
  while (line[count] >= '0' && line[count] <= '9')
    count++;
  y = atoi(selectstr(line, save, count - 1));
  printf("Y : %d\n", y);
  count++;
  save = count;
  while (line[count] >= '0' && line[count] <= '9')
    count++;
  colors = atoi(selectstr(line, save, count - 1));
  printf("Color : %d\n", colors);
  count++;
  save = count;
  while (line[count] >= '0' && line[count] <= '9')
    count++;
  space = atoi(selectstr(line, save, count - 1));
  printf("Space : %d\n", space);

  char *tag;
  int cunt = 0;
  sfColor color;
  t_color data[colors];

  while (cunt < colors)
  {
    line = get_next_line(fd);
    tag = selectstr(line, 1, space);
    count = space - 1;
    while (line[++count] != '#')
      ;
    data[cunt].r = strtol(selectstr(line, count + 1, count + 2), NULL, 16);
    data[cunt].g = strtol(selectstr(line, count + 3, count + 4), NULL, 16);
    data[cunt].b = strtol(selectstr(line, count + 5, count + 6), NULL, 16);
    data[cunt].color = colorgen(data[cunt].r, data[cunt].g, data[cunt].b, 255);
    data[cunt].tag = selectstr(line, 1, space);
    printf("Color : %s == [%s] {%d, %d, %d}\n", line, data[cunt].tag, data[cunt].r, data[cunt].g, data[cunt].b);
    cunt++;
  }
  
}

int main(int argc, char **argv)
{
  t_wolf *data;
  t_var *var;
  t_pos *player;
  sfEvent event;
  t_my_framebuffer buffer;
  int menu = 0;

  data = setmap(argv[1]);
  var = malloc(sizeof(t_var));
  player = malloc(sizeof(t_pos));
  setplayer(argc, argv, player);
  setvar(var, buffer);
  buffer = create_buffer_struct(SCREEN_WIDTH, SCREEN_HEIGHT);
  //draw_menu(var, &buffer);
  while (sfRenderWindow_isOpen(var->window))
  {
    if (menu == 1)
    {
      draw_menu(var, &buffer);
      //menu_keys(var, event, data);
    }
    else
    {
      mouseloop(var, player);
      keyloop(var, event, player, data);
      draw_background(&buffer);
      draw_wall(data, player, &buffer, 20);
      drawmap(data, &buffer, player, 13);
      playertoggle(data, player, &buffer);
      }
    updatepixels(&buffer, var);
  }
  return (0);
}
