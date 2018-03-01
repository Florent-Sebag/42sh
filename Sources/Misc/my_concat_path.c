/*
** my_concat_path.c for my_concat_path.c in /home/diagne_n/PSU_2015_42sh/Sources/Misc
**
** Made by Nicolas Diagne
** Login   <diagne_n@epitech.net>
**
** Started on  Tue May 17 11:42:23 2016 Nicolas Diagne
** Last update Sun Jun 05 18:50:59 2016 Victor
*/

#include "my.h"

char	*my_concat_path(char *tmp, char *cat)
{
  char	*str;
  int	size;
  int	i;
  int	x;

  x = 0;
  i = 0;
  size = my_strlen(tmp) + my_strlen(cat) + 2;
  if ((str = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  while (tmp[x])
    {
      str[x] = tmp[x];
      x = x + 1;
    }
  str[x] = '/';
  x = x + 1;
  while (cat[i])
    {
      str[x] = cat[i];
      i = i + 1;
      x = x + 1;
    }
  str[x] = '\0';
  return (str);
}
