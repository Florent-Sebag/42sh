/*
** my_putstr_S.c for  in /home/victor/rendu/Première année/Sys_Unix/PSU_2015_my_printf/lib/my
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Fri Nov 13 20:45:33 2015 Victor
** Last update Sun Jun 05 18:51:49 2016 Victor
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_lib.h"

int		my_putstr_S(va_list ap)
{
  int		i;
  char		*str;

  i = 0;
  str = va_arg(ap, char *);
  if (str == NULL)
    my_putstr("(null)");
  else
    {
      while (str[i] != '\0')
	{
	  if (str[i] < 32 || str[i] == 127)
	    {
	      my_putstr("\\0");
	      if (str[i] < 8)
		my_putchar('0');
	      my_putnbr_base(str[i], "01234567");
	    }
	  else
	    my_putchar(str[i]);
	  i += 1;
	}
    }
  return (0);
}
