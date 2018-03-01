/*
** my_put_nbr_o.c for  in /home/victor/rendu/Première année/Sys_Unix/PSU_2015_my_printf/lib/my
**
** Made by Victor
** Login   <marito_v@epitech.net>
**
** Started on  Mon Nov  9 14:36:47 2015 Victor
** Last update Sun Jun 05 18:51:58 2016 Victor
*/

#include <stdarg.h>
#include "my_lib.h"

int		my_put_nbr_o(va_list ap)
{
  unsigned int	nb;

  nb = va_arg(ap, unsigned int);
  if (nb == 0)
    {
      my_putstr("0");
      return (0);
    }
  my_putnbr_base(nb, "01234567");
  return (0);
}
