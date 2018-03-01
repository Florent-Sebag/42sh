/*
** my.h for  in Sys_Unix/PSU_2015_my_printf_bootstrap/include
**
** Made by Victor
** Login   <marito_v@epitech.net>
**
** Started on  Tue Nov  3 17:18:03 2015 Victor
** Last update Tue May 10 13:30:58 2016 Nicolas Diagne
*/

#ifndef MY_LIB_H_
# define MY_LIB_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/* ---------- | MACROS | ---------- */

#	define		EXIT_ON_FAILURE		-1


/* ---------- |  STRUCTURE PRINTF | ---------- */

typedef struct  s_carac
{
  char          c;
  int           (*ptr)(va_list);
}               t_carac;

/* ---------- | PROTOTYPES DE FONCTIONS POUR MY_PRINTF| ---------- */

void		*my_memset(void *, char , int);

char		**my_str_to_wordtab(char *, char);

char		*my_strcpy(char *, char *);
char		*my_strdup(char *);
char		*epur_str(char *);

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
int		my_strncmp(char *, char *, int);
int		my_putnbr_base_p(long int, char *);
int		my_putnbr_base_o(unsigned int, char *);

#endif /* !MY_LIB_H_ */
