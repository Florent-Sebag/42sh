/*
** my_putstr_s.c for  in
**
** Made by Victor Mariton
** Login   <marito_v@epitech.net>
**
** Started on  Sun Jan 24 22:41:22 2016 Victor Mariton
** Last update Mon May 23 18:18:29 2016 Dheilly Joss
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_lib.h"

int		my_putstr_s(va_list ap)
{
  char		*str;
  int		i;

  str = va_arg(ap, char *);
  i = 0;
  if (str == NULL)
    {
      my_putstr("(null)");
      return (0);
    }
  while (str[i] != '\0')
    i += 1;
  write(1, str, i);
  return (0);
}
