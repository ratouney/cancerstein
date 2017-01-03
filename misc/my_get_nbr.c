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

int my_get_nbr(char *str)
{
  int count;
  int nbr;
  int moins;

  count = 0;
  nbr = 0;
  moins = 0;
  while (str[count] && (str[count] == '+' || str[count] == '-'))
  {
    if (str[count] == '-')
      moins = moins + 1;
    count = count + 1;
  }
  while (str[count] && (str[count] <= 57 && str[count] >= 48))
  {
    nbr = (nbr * 10) + (str[count] - 48);
    count = count + 1;
  }
  if (moins % 2 == 1)
    nbr = nbr * (-1);
  return (nbr);
}