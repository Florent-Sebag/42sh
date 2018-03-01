/*
** my_memset.c for PSU_2015_minitalk in /home/victor/Rendu/Sys_Unix/PSU_2015_minitalk/lib/my
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Fri Feb 12 22:35:30 2016 Victor
** Last update Sun Jun 05 18:52:00 2016 Victor
*/

#include "my_lib.h"

void		*my_memset(void *elem, char c, int size)
{
  int		i;
  char		*str;

  i = -1;
  str = (char *)elem;
  while (++i < size)
    str[i] = c;
  return (elem);
}
