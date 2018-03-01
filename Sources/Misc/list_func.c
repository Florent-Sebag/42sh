/*
** list_func.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources/Misc
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Thu Apr 28 09:49:45 2016 Victor
** Last update Sun Jun 05 18:50:59 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

size_t		size_list(t_list_env *list)
{
  t_list_env	*tmp;
  int		i;

  i = 0;
  tmp = list;
  while (tmp)
    {
      tmp = tmp->next;
      i += 1;
    }
  return (i);
}

t_list_env		*add_elem_list(t_list_env *list, char *str)
{
  t_list_env	*new;

  new = my_malloc(sizeof(t_list_env));
  new->next = list;
  new->str = str;
  return (new);
}
