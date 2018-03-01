/*
** type_of_alias.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Wed Jun 01 14:43:06 2016 Victor
** Last update Sun Jun 05 18:51:25 2016 Victor
*/

#include "my.h"
#include <stdlib.h>

int	get_type(char *type)
{
  char		*str;

  str = first_word(type);
  if (!CMP(str, "alias"))
    return (ALIAS);
  return (EXIT_ON_FAILURE);
}

void	*delete_type_alias(void *data)
{
  char		*str;

  str = (char *)data;
  str += 6;
  data = str;
  return (data);
}
