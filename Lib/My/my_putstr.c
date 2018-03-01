/*
** my_putstr.c for  in
**
** Made by Victor
** Login   <marito_v@epitech.net>
**
** Started on  Wed Nov 11 21:02:01 2015 Victor
** Last update Sun Jun 05 18:51:46 2016 Victor
*/

#include <unistd.h>

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i += 1;
  write(1, str, i);
  return (0);
}
