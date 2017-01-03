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

char *selectstr(char *buffer, int from, int to)
{
  int cunt;
  char *result;

  result = malloc(sizeof(char) * (to - from + 2));
  cunt = 0;
  while (from + cunt <= to)
  {
    result[cunt] = buffer[from + cunt];
    cunt++;
  }
  result[cunt] = '\0';
  return (result);
}