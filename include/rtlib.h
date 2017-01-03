/*
** headergen.c for CPE_2016_BSQ_bootstrap in /home/ratouney/CPE_2016_BSQ_bootstrap
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Dec 11 09:59:08 2016 ratouney
** Last update Sun Sep 09 11:42:69 2016 Chuck Norris
*/ 

#ifndef RATMX_H_
# define RATMX_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


 struct s_variable
 {
   char *flags;
   char *width;
   char *pre;
   char *length;
   char spe;
   char *full;

   int change;
   int count;
   int valid;
   int start;
 };

/*
** [my_putchar.c]
*/
void my_putchar(char c);

/*
** [my_putstr.c]
*/
void    my_putstr(char *str);

/*
** [my_get_nbr.c]
*/
int	my_get_nbr(char *str);

/*
** [my_strlen.c]
*/
int	my_strlen(char *str);

/*
** [my_putchars.c]
*/
void	my_putchars(char c, int max);

/*
** [my_put_nbr.c]
*/
int	rec_my_put_nbr(int nb);
int	my_put_nbr(int nb);

/*
** [fdinstr.c]
*/

int	fdinstr(char c, char* str);

/*
** [selectstr.c]
*/

char *selectstr(char *buffer, int from, int to);

/*
** [launcher.c]
*/

struct s_variable *findtag(char *str, int i);
void	do_nothing();
void	my_printf(char *str, ...);

/*
** [load_file_in_mem.c]
*/

long get_size(char *filepath);
char *load_file_in_mem(char *filepath);

/*
** [gayificator.c]
*/

void	gayificator(char *str);

/*
** [print.c]
*/

int	my_strcmp(char *str1, char *str2);
void	my_putstr_withblanks(char *str, int blanks, int max);
void	my_putstr_tilln(char *carac, int max);
void	print_str(char *carac, struct s_variable *tag);
void	print_nbr(int carac, struct s_variable *tag);

/*
** [tag_loops.c]
*/

struct s_variable *findflags(struct s_variable *tag, int i, char *str);
struct s_variable *findwidth(struct s_variable *tag, int i, char *str);
struct s_variable *findpre(struct s_variable *tag, int i, char *str);
struct s_variable *findlen(struct s_variable *tag, int i, char *str);
struct s_variable *findspe(struct s_variable *tag, int i, char *str);

/*
** [my_nbrlen.c]
*/

int	my_nbrlen(int a);
char *slinstr(char *, int, int);

#endif /* !RATMX_H_ */

/*
**   Made by Ratouney's C-Header Generator
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
