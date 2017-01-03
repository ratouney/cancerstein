/*
** main.c for CPE_2016_BSQ_bootstrap in /home/ratouney/CPE_2016_BSQ_bootstrap
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Dec 11 10:09:24 2016 ratouney
** Last update Sun Dec 11 13:02:27 2016 John Doe
*/

#include "wolf3d.h"

long get_size(char *filepath)
{
  struct stat buffer;
  long size;

  stat(filepath, &buffer);
  size = buffer.st_size;
  return (size);
}

char *load_file_in_mem(char *filepath)
{
  int fd;
  char *buffer;

  if ((fd = open(filepath, O_RDONLY)) == -1)
    return ("Nope");
  buffer = malloc((get_size(filepath) + 1) * sizeof(*buffer));
  if (buffer == NULL)
    return ("Nope");
  read(fd, buffer, get_size(filepath));
  buffer[get_size(filepath)] = '\0';
  return (buffer);
}
