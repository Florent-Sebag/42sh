/*
** my.h for  in Sys_Unix/PSU_2015_my_printf_bootstrap/include
**
** Made by Victor
** Login   <marito_v@epitech.net>
**
** Started on  Tue Nov  3 17:18:03 2015 Victor
** Last update Mon May 02 17:34:01 2016 Victor
*/

#ifndef MY_LIB_H_
# define MY_LIB_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

/* ---------- | MACROS | ---------- */

# define	EXIT_ON_FAILURE		-1
# define	LEN			strlen

/* ---------- |  STRUCTURE PRINTF | ---------- */

typedef struct  s_carac
{
  char          c;
  int           (*ptr)(va_list);
}               t_carac;

/* ---------- | PROTOTYPES DE FONCTIONS POUR MY_PRINTF| ---------- */

char		**my_str_to_wordtab(char *, char);
char		*my_strdup(char *);
char		*my_strcpy(char *, char *);
int		nb_line(char **);
int		my_isnum(char *);
int		my_putchar(char);
int		my_strlen(char *);
int		my_putstr(char *);
int		my_getnbr(char *);
int		my_puterr(va_list);
int		size_tab1(char **);
int		my_put_nbr(va_list);
int		my_putstr_S(va_list);
int		my_putstr_s(va_list);
int		my_put_nbr_o(va_list);
int		my_put_nbr_b(va_list);
int		my_put_nbr_p(va_list);
int		my_put_nbr_u(va_list);
int		my_put_nbr_x(va_list);
int		my_put_nbr_X(va_list);
int		my_putchar_v(va_list);
int		my_strcmp(char *, char *);
int		my_putnbr_base(int, char *);
int		my_printf(const char *, ...);
int		my_putnbr_base_p(long int, char *);
int		my_putnbr_base_o(unsigned int, char *);
int		my_strcmp(char *s1, char *s2);

#endif /* !MY_LIB_H_ */
