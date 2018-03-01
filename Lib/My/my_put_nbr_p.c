/*
** my_put_nbr_p.c for  in /home/victor/rendu/Première année/Sys_Unix/PSU_2015_my_printf/lib/my
**
** Made by Victor
** Login   <marito_v@epitech.net>
**
** Started on  Mon Nov  9 19:23:51 2015 Victor
** Last update Sun Jun 05 18:51:57 2016 Victor
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_lib.h"

int			my_put_nbr_p(va_list ap)
{
  long int	nb;

  nb = va_arg(ap, long int);
  if (nb == (long)NULL)
    {
      my_putstr("(nil)");
      return (0);
    }
  my_putstr("0x");
  my_putnbr_base_p(nb, "0123456789abcdef");
  return (0);
}
