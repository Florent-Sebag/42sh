/*
** my_strdup.c for my_strdup in /home/marito_v/rendu/Piscine_C_J08/ex_01
**
** Made by Victor Mariton
** Login   <marito_v@epitech.net>
**
** Started on  Wed Oct  7 10:09:15 2015 Victor Mariton
** Last update Sun Jun 05 18:51:35 2016 Victor
*/

#include <stdlib.h>
#include "my_lib.h"

char	*my_strdup(char *src)
{
  char	*str;
  int   i;

  if ((str = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    exit(EXIT_ON_FAILURE);
  i = -1;
  while (src[++i])
    str[i] = src[i];
  str[i]= '\0';
  return (str);
}
