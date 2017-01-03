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

char **malchartab(int x, int y)
{
  char **tab;
  int count;
  int cunt;

  tab = malloc(sizeof(char *) * y);
  count = 0;
  while (count < y)
  {
    tab[count] = malloc(sizeof(char) * x);
    cunt = 0;
    while (cunt < x)
    {
      tab[count][cunt] = 0;
      cunt++;
    }
    count++;
  }
  return (tab);
}