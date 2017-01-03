/*
** headergen.c for CPE_2016_BSQ_bootstrap in /home/ratouney/CPE_2016_BSQ_bootstrap
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Dec 11 09:59:08 2016 ratouney
** Last update Sun Dec 11 11:45:49 2016 John Doe
*/

#include "rtlib.h"

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
