/*
** get_first_word.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources/Misc
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Tue May 31 11:20:09 2016 Victor
** Last update Sun Jun 05 18:51:01 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

int		len_space(char *str)
{
  int		i;

  i = -1;
  while (str[++i] != ' ' && str[i]);
  return (i);
}

char		*first_word(char *str)
{
  char		*new;
  int		size;
  int		i;

  i = -1;
  size = len_space(str);
  new = my_malloc(sizeof(char) * size + 1);
  while (++i < size)
    new[i] = str[i];
  new[i] = '\0';
  return (new);
}

int		words(char *str)
{
  int		i;
  int		count;

  i = -1;
  count = 1;
  while (str[++i])
    {
      if (str[i] == ' ')
	count += 1;
    }
  return (count);
}
