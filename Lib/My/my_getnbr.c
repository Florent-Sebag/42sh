/*
** my_getnbr.c for my_getnbr in /home/marito_v/rendu/Piscine_C_J04
**
** Made by Victor Mariton
** Login   <marito_v@epitech.net>
**
** Started on  Thu Oct  1 20:27:14 2015 Victor Mariton
** Last update Sun Jun 05 18:52:00 2016 Victor
*/

#include "my_lib.h"
#include <stdlib.h>

static int	execute(char *str, double multiple)
{
  int		j;
  int		value;
  double	longe;

  longe = 0;
  j = 0;
  while (str[j] != '\0')
    {
      if (str[j] >= 48 && str[j] <= 57)
	{
	  longe = longe + ((str[j] - 48) * multiple);
	  multiple = multiple / 10;
	}
      j = j + 1;
    }
  value = longe;
  if (value != longe)
    return (0);
  return (value);
}

int		my_getnbr(char *str)
{
  int		i;
  double	multiple;
  int		signe;
  int		bool;

  if (str == NULL)
    return (0);
  i = 0;
  multiple = 1;
  signe = 1;
  bool = 0;
  while (str[i] != '\0' && bool == 0)
    {
      if (str[i] == '-')
	signe = signe * -1;
      else if (str[i] >= 48 && str[i] <= 57)
	multiple = multiple * 10;
      else if (str[i] != '+' && str[i] != '-')
	bool = 1;
      i = i + 1;
    }
  multiple = multiple / 10;
  return (execute(str, multiple) * signe);
}
