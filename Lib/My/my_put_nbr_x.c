/*
** my_put_nbr_x.c for  in
**
** Made by Victor Mariton
** Login   <marito_v@epitech.net>
**
** Started on  Sun Jan 24 22:41:03 2016 Victor Mariton
** Last update Sun Jan 24 22:41:03 2016 Victor Mariton
*/

#include "my_lib.h"

int		 my_put_nbr_x(va_list ap)
{
  unsigned int	nb;

  nb = va_arg(ap, unsigned int);
  if (nb == 0)
    {
      my_putstr("0");
      return (0);
    }
  my_putnbr_base(nb, "0123456789abcdef");
  return (0);
}
