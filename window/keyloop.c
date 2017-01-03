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

void keyloop(t_var *var, sfEvent event, t_pos *player, t_wolf *data)
{
  while (sfRenderWindow_pollEvent(var->window, &event))
  {
    if (event.type == sfEvtKeyPressed && event.key.code == 36)
      sfRenderWindow_close(var->window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
      player->moving = 1;
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyUp)
      player->moving = 0;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
      player->moving = -1;
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyDown)
      player->moving = 0;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft)
      player->strafing = -1;
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyLeft)
      player->strafing = 0;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight)
      player->strafing = 1;
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyRight)
      player->strafing = 0;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ)
      player->angle += TO_RAD(ANGLE);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD)
      player->angle -= TO_RAD(ANGLE);
  }
}