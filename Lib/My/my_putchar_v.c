/*
** my_putchar_v.c for  in /home/victor/rendu/Première année/Sys_Unix/PSU_2015_my_printf/lib/my
**
** Made by Victor
** Login   <marito_v@epitech.net>
**
** Started on  Mon Nov  9 14:31:38 2015 Victor
** Last update Sun Jun 05 18:51:53 2016 Victor
*/

#include "my_lib.h"

int	my_putchar_v(va_list ap)
{
  char	a;

  a = va_arg(ap, int);
  my_putchar(a);
  return (0);
}
