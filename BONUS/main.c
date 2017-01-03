/*
** moveforward.c for CancersteinxD in /home/ratouney/GRAPH/bswolf3d
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Nov 20 11:36:28 2016 ratouney
** Last update Mon Dec 12 10:46:59 2016 John Doe
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *makename(char *x, char *y, char *name)
{
    char *new = malloc(sizeof(char) * (strlen(x) + strlen(y) + strlen(name) + 3));

    strcat(new, x);
    strcat(new, "x");
    strcat(new, y);
    strcat(new, "-");
    strcat(new, name);
    return (new);
}

int main(int argc, char **argv)
{
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    char *filename = makename(argv[1], argv[2], argv[3]);
    char *line = malloc(sizeof(char) * (x + 1));
    char *prev = malloc(sizeof(char) * (x + 1));

    FILE *data = fopen(filename, "w");

    int count = -1;
    int cunt;

    while (++count < x)
        line[count] = '1';
    line[count] = '\0';
    prev = line;
    count = 0;
    fprintf(data ,"%s\n", line);
    while (count < y - 2)
    {
        line[0] = '1';
        line[x - 1] = '1';
        cunt = 1;
        while (cunt < x - 1)
        {
                line[cunt] = ((rand() % 4 > 2) ? '1' : '0');
            cunt++;
        }
        line[x] = '\0';
        prev = line;
        fprintf(data, "%s\n", line);
        count++;
    }
    count = -1;
    while (++count < x)
        line[count] = '1';
    line[count] = '\0';
    count = 0;
    fprintf(data, "%s\n", line);
}