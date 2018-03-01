/*
** my_putnbr_base.c for  in /home/victor/rendu/Première année/Sys_Unix/PSU_2015_my_printf/lib/my
**
** Made by Victor
** Login   <marito_v@epitech.net>
**
** Started on  Tue Nov 10 10:38:53 2015 Victor
** Last update Sun Jun 05 18:51:50 2016 Victor
*/

#include "my_lib.h"

int	base_r(int nbr, int i, int c, char *base)
{
  if (nbr == 0)
    return (0);
  c = (nbr % i);
  nbr = nbr / i;
  base_r(nbr, i, c, base);
  my_putchar(base[c]);
  return (0);
}

int	my_putnbr_base(int nbr, char *base)
{
  int	i;

  i = my_strlen(base);
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  base_r(nbr, i, 0, base);
  return (nbr);
}
