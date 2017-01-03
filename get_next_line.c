/*
** main.c for CPE_2016_getnextline in /home/ratouney/CPE_2016_getnextline
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Dec 11 10:09:24 2016 ratouney
** Last update Sun Dec 11 13:02:27 2016 ratouney
*/

#include <stdio.h>
#include "get_next_line.h"

int findjump(char *b)
{
    int i;

    i = 0;
    if (b == NULL)
        return (-2);
    while (b[i] != '\0')
    {
        if (b[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char *slc(char *b, int from, int to)
{
    int i;
    char *new;

    new = malloc(sizeof(char) * (to - from + 1));
    i = 0;
    while (b[from + i] != '\0' && from + i + 1 < to)
    {
        new[i] = b[from + i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

int stl(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}

char *concat(char *src, char *add)
{
    char *new;
    int i;
    int j;

    new = malloc(sizeof(char) * (stl(src) + stl(add) + 1));
    i = -1;
    while (src[++i] != '\0')
        new[i] = src[i];
    j = -1;
    while (add[++j] != '\0')
        new[i + j] = add[j];
    new[i + j] = '\0';
    free(src);
    free(add);
    return (new);
}

char *get_next_line(int fd)
{
    static char *b = NULL;
    static int end = 0;
    char *rt;
    int t;

    if (b == NULL && (b = malloc(sizeof(char) * ((RS * 1)))))
    {
        rt = malloc(sizeof(char) * (RS + 1));
        if (rt[RS] = '\0' && (b = rt) && read(fd, rt, RS) <= 0)
            return (NULL);
    }
    while (42 + 42 == 84)
    {
        t = findjump(b);
        if (t >= 0 && (rt = slc(b, 0, t + 1)) &&
         (b = slc(b, t + 1, stl(b) + 1)))
            return (rt);
        else if (1 == 1 && (rt = malloc(sizeof(char) * (RS + 1))))
        {
            if (read(fd, rt, RS) == 0)
                return ((end == 0) && ((end = 1) == 1) ?
                 slc(b, 0, stl(b) + 1) : NULL);
            rt[RS] = '\0';
            b = concat(b, rt);
        }
    }
}