/*
** advanced.h for adv_wireframe in /home/ratouney/bswireframe
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Nov 20 11:37:31 2016 ratouney
** Last update Mon Dec 12 10:46:43 2016 John Doe
*/

#ifndef WOLF_H_
#define WOLF_H_

#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/Sprite.h"
#include "SFML/Graphics/Texture.h"
#include "SFML/Window/Keyboard.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#define TO_RAD(x) (x * (M_PI / 180))
#define TO_DEG(x) (x * (180 / M_PI))
#define ABS(x) (x < 0) ? x * -1 : x;
#define FOCAL SCREEN_WIDTH / 2 / tan(TO_RAD(FOV / 2))
#define MOVEMENT 0.05
#define MAP 0
#define ANGLE 1
#define FOV 70.0
#define SCANINT 0.05
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define BUFFSIZE 50000

typedef struct s_my_framebuffer
{
  sfUint8 *pixels;
  int width;
  int height;
} t_my_framebuffer;

typedef struct s_var
{
  sfRenderWindow *window;
  sfTexture *texture;
  sfSprite *sprite;
  sfEvent event;
  sfVector2i base;
  sfVector2i proj;
} t_var;

typedef struct s_vertex
{
  sfVector2i from;
  sfVector2i to;
  sfColor srccol;
  sfColor descol;
} t_vertex;

typedef struct s_pos
{
  float x;
  float y;
  float angle;
  float strafing;
  float moving;
} t_pos;

typedef struct s_ray
{
  float x;
  float y;
  float angle;
  float distance;

  float scale_mod;
  float scale_dist;
} t_ray;

typedef struct s_wolfmap
{
  char **map;
  int x;
  int y;

  int toggle_hor;
  int toggle_ver;
  int toggle_ray;
  int toggle_map;
} t_wolf;

typedef struct s_raydata
{
  float x;
  float y;
  float px;
  float py;
  float angle;
  float step_x;
  float step_y;
  float tab_y;
  float tab_x;
  int done;
  float count;
  float distance;
  float dist_x;
  float dist_y;
} t_data;

/*
** [my_put_pixel.c]
*/
void my_put_pixel(t_my_framebuffer *buffer, int x, int y, sfColor color);

/*
** [main.c]
*/
void setvar(t_var *var, t_my_framebuffer buffer);
void resetbuffer(t_my_framebuffer *buffer);
int main(int argc, char **argv);

/*
** [init_gen.c]
*
	t_my_framebuffer create_buffer_struct(int width, int height);
	t_var *create_window(char* name, int width, int height, t_var *var);

/*
** [headergen.c]
*/
char *namecheck(char *str);
char *slinstr(char *str, int from, int to);
int main(int argc, char **argv);

t_my_framebuffer create_buffer_struct(int width, int height);
sfUint8 *create_pixel_buffer(int width, int height);
t_var *create_window(char *name, int width, int height, t_var *var);
void updatepixels(t_my_framebuffer *buffer, t_var *var);
void my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from, sfVector2i to, sfColor color);
sfVector2f move_backward(sfVector2f pos, float direction, float distance);
sfVector2f move_forward(sfVector2f pos, float direction, float distance);
void show_tab(int **tab, int x, int y);
void shintab(int *tab, int size);
sfColor colorgen(int r, int g, int b, int a);
char *load_file_in_mem(char *filepath);
sfVector2i dotgen(float x, float y);
char *selectstr(char *buffer, int from, int to);
void getspecs(char *name, t_wolf *data);
void drawsquare(t_my_framebuffer *buffer, sfVector2i *pos, int size, sfColor color);
char **malchartab(int x, int y);
int my_get_nbr(char *str);
t_wolf *setmap(char *path);
void drawmap(t_wolf *data, t_my_framebuffer *buffer, t_pos *player, int scale);
void draw_raycast(t_pos *player, t_wolf *data, int scale, t_my_framebuffer *);
float cedric_main(t_wolf *data, t_pos *player, t_my_framebuffer *buffer, int scale);
void draw_fov(t_wolf *data, t_pos *player, t_my_framebuffer *buffer, int scale);

float rayhoriz(t_wolf *wolf, float px, float py, float angle);
int rayhoriz_load(t_wolf *wolf, t_data *data);
float rayvert(t_wolf *wolf, float px, float py, float angle);
int rayvert_load(t_wolf *wolf, t_data *data);
void moveplayer(t_pos *player, t_wolf *data, float distance);
void strafeplayer(t_pos *player, t_wolf *data, float distance, float mod);
void keyloop(t_var *var, sfEvent event, t_pos *player, t_wolf *data);
void raycast(t_wolf *data, t_ray *ray);
void draw_background(t_my_framebuffer *buffer);
void draw_vertex(t_my_framebuffer *buffer, t_vertex *data);
t_vertex *vertex_gen(sfVector2i source, sfVector2i destination, sfColor src, sfColor org);
double dot_pr(t_pos *player, float angle);

#endif /* WOLF_H_ */

/*
**	   Made by Ratouney's C-Header Generator
**
**
**           __             _,-"~^"-.
**         _// )      _,-"~`         `.
**       .\ ( /`"-,-"`                 ;
**      / 6                             ;
**     /           ,             ,-"     ;
**    (,__.--.      \           /        ;
**     '   /`-.\   |          |        `._________
**       _.-'_/`  )  )--...,,,___\     \-----------,)
**     ((("~` _.-'.-'           __`-.   )         //
**          ((("`             (((---~ "`         //
**                                              ((________________
**                                              `----""""~~~~^^^```
*/