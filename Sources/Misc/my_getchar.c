/*
** my_getchar.c for my_getchar.c in /home/diagne_n/PSU_2015_42sh/Sources/Misc
**
** Made by Nicolas Diagne
** Login   <diagne_n@epitech.net>
**
** Started on  Fri Jun  3 11:14:47 2016 Nicolas Diagne
** Last update Sun Jun 05 18:50:58 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

int     my_isnegative(int n)
{
  if (n < 0)
    return (1);
  return (0);
}

int	my_intlen(int n)
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

char    *my_charcat(char *dest, char c)
{
  int   len;

  len = my_strlen(dest);
  dest[len] = c;
  dest[len + 1] = '\0';
  return (dest);
}

int	my_power(int i)
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

char	*my_getchar(int nb)
{
  int	i;
  int	num;
  char	*str;

  i = my_intlen(nb);
  str = malloc(sizeof(char) * (i + 1));
  if (str == NULL)
    return (NULL);
  str[my_intlen(nb)] = '\0';
  if (my_isnegative(nb))
    {
      str = my_charcat(str, '-');
      nb = nb * -1;
    }
  while (i > 0)
    {
      num = (nb / my_power(i)) % 10;
      str = my_charcat(str, (num + 48));
      i = i - 1;
    }
  return (str);
}
