/*
** my_strlen.c for  in /home/victor/rendu/Première année/Sys_Unix/PSU_2015_my_printf_bootstrap/sources
**
** Made by Victor
** Login   <marito_v@epitech.net>
**
** Started on  Tue Nov  3 16:35:05 2015 Victor
** Last update Sun Jun 05 18:51:34 2016 Victor
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (0);
  while (str[++i] != '\0');
  return (i);
}
