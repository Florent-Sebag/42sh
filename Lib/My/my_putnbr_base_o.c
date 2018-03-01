/*
** my_putnbr_base.c for my_putnbr_base in /home/marito_v/rendu/Piscine_C_J06/ex_16
**
** Made by Victor Mariton
** Login   <marito_v@epitech.net>
**
** Started on  Tue Oct  6 17:48:19 2015 Victor Mariton
** Last update Sun Jun 05 18:51:51 2016 Victor
*/

#include "my_lib.h"

int	base_r_o(unsigned int nbr, int i, int c, char *base)
{
  if (nbr == 0)
    return (0);
  c = (nbr % i);
  nbr = nbr / i;
  base_r_o(nbr, i, c, base);
  my_putchar(base[c]);
  return (0);
}

int	my_putnbr_base_o(unsigned int nbr, char *base)
{
  int	i;

  i = my_strlen(base);
  base_r_o(nbr, i, 0, base);
  return (nbr);
}
