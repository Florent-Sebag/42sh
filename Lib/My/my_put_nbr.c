/*
** my_put_nbr.c for  in /home/victor/rendu/Première année/Sys_Unix/PSU_2015_my_printf_bootstrap
**
** Made by Victor
** Login   <marito_v@epitech.net>
**
** Started on  Tue Nov  3 15:15:30 2015 Victor
** Last update Sun Jun 05 18:51:54 2016 Victor
*/

#include <stdarg.h>
#include "my_lib.h"

int     my_isnega(int n)
{
  if (n < 0)
    return (1);
  return (0);
}

int	len(int n)
{
  int	x;
  int	i;

  x = 1;
  i = 1;
  while (((n / x) >= 10) || ((n / x) <= -10))
    {
      x = x * 10;
      i = i + 1;
    }
  return (i);
}

int	power(int i)
{
  int	x;
  int	n;

  x = 0;
  n = 1;
  while (x < (i - 1))
    {
      n = n * 10;
      x = x + 1;
    }
  return (n);
}

int	my_put_nbr(va_list ap)
{
  int	i;
  int	nb;
  int	num;
  long	lnb;

  nb = va_arg(ap, int);
  lnb = (long)nb;
  if (my_isnega(lnb))
    {
      my_putchar('-');
      lnb = lnb * -1;
    }
  i = len(lnb);
  while (i > 0)
    {
      num = (lnb / power(i)) % 10;
      my_putchar(num + 48);
      i = i - 1;
    }
  return (0);
}
