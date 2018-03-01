/*
** my_printf.c for  in /home/victor/rendu/Première année/Sys_Unix/PSU_2015_my_printf
**
** Made by Victor
** Login   <marito_v@epitech.net>
**
** Started on  Thu Nov  5 14:15:57 2015 Victor
** Last update Sun Jun 05 18:51:59 2016 Victor
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_lib.h"

t_carac	g_tab[] =
  {
    {'d', &my_put_nbr},
    {'i', &my_put_nbr},
    {'c', &my_putchar_v},
    {'s', &my_putstr_s},
    {'S', &my_putstr_S},
    {'o', &my_put_nbr_o},
    {'b', &my_put_nbr_b},
    {'p', &my_put_nbr_p},
    {'u', &my_put_nbr_u},
    {'x', &my_put_nbr_x},
    {'X', &my_put_nbr_X},
    {'e', &my_puterr},
    {0, NULL}
  };

int	redirect(va_list ap, char c)
{
  int	i;
  int	tmp;

  i = 0;
  tmp = 0;
  while (g_tab[i].c != 0)
    {
      if (g_tab[i].c == c)
	{
	  g_tab[i].ptr(ap);
	  tmp = 1;
	}
      i += 1;
    }
  if (c == '%')
    my_putchar('%');
  if (tmp == 0 && c != '%')
    {
      my_putchar('%');
      my_putchar(c);
    }
  return (tmp);
}

int	check(const char *str)
{
  if (str == NULL)
    {
      write(1, "Invalid format\n", 15);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

void	f_norme(va_list ap, const char *format)
{
  int	i;

  i = 0;
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	{
	  if (format[i + 1] == ' ')
	    {
	      my_putchar(' ');
	      redirect(ap, format[i + 2]);
	      i += 1;
	    }
	  else
	    redirect(ap, format[i + 1]);
	  i += 1;
	}
      else
	my_putchar(format[i]);
      i += 1;
    }
}

int		my_printf(const char *format, ...)
{
  va_list	ap;

  va_start(ap, format);
  if (check(format) == EXIT_FAILURE)
    return (0);
  f_norme(ap, format);
  va_end(ap);
  return (0);
}
