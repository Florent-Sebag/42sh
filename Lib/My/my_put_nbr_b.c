/*
** my_put_nbr_b.c for  in /home/victor/rendu/Première année/Sys_Unix/PSU_2015_my_printf/lib/my
**
** Made by Victor
** Login   <marito_v@epitech.net>
**
** Started on  Tue Nov 10 10:17:03 2015 Victor
** Last update Sun Jun 05 18:51:59 2016 Victor
*/

#include <stdarg.h>
#include "my_lib.h"

int		my_put_nbr_b(va_list ap)
{
  unsigned int	nb;

  nb = va_arg(ap, unsigned int);
  if (nb == 0)
    {
      my_putstr("0");
      return (0);
    }
  my_putnbr_base(nb, "01");
  return (0);
}
