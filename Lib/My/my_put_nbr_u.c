/*
** my_put_nbr_u.c for  in Première année/Sys_Unix/PSU_2015_my_printf/lib/my
**
** Made by Victor
** Login   <marito_v@epitech.net>
**
** Started on  Mon Nov  9 19:06:08 2015 Victor
** Last update Sun Jun 05 18:51:56 2016 Victor
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_lib.h"

int		my_put_nbr_u(va_list ap)
{
  unsigned int	nb;

  nb = va_arg(ap, unsigned int);
  if (nb == 0)
    my_putchar('0');
  else
    my_putnbr_base(nb, "0123456789");
  return (0);
}
