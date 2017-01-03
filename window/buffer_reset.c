/*
** init_gen.c for adv in /home/ratouney/bswireframe/adv
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Nov 27 16:07:41 2016 ratouney
** Last update Mon Dec 12 10:51:10 2016 John Doe
*/

#include "wolf3d.h"

void resetbuffer(t_my_framebuffer *buffer)
{
  int i;

  i = 0;
  while (i < SCREEN_WIDTH * SCREEN_HEIGHT * 4)
  {
    buffer->pixels[i] = 0;
    i = i + 1;
  }
}

void  updatepixels(t_my_framebuffer *buffer, t_var *var)
{
    sfRenderWindow_clear(var->window, sfBlack);
    sfTexture_updateFromPixels(var->texture, buffer->pixels,
                               SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(var->window, var->sprite, NULL);
    sfRenderWindow_display(var->window);
}