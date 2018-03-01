/*
** my_puterr.c for  in
**
** Made by Victor Mariton
** Login   <marito_v@epitech.net>
**
** Started on  Thu Dec  3 15:22:16 2015 Victor Mariton
** Last update Sun Jun 05 18:51:52 2016 Victor
*/

#include <unistd.h>
#include "my_lib.h"

int    my_puterr(va_list ap)
{
  int	i;
  char	*str;

  str = va_arg(ap, char *);
  i = -1;
  if (!str)
    {
      my_putstr("(null)");
      return (0);
    }
  while (str[++i]);
  write(2, str, i);
  return (0);
}
