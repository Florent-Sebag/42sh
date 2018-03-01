/*
** List_Tab.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources/Misc
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Wed Apr 27 20:08:59 2016 Victor
** Last update Sun Jun 05 18:51:10 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

char		**set_tab_from_list(t_data *dt)
{
  t_list_env	*tmp;
  char		**new_env;
  int		i;

  new_env = my_malloc(sizeof(char *) * (size_list(dt->list_env) + 1));
  i = 0;
  tmp = dt->list_env;
  while (tmp)
    {
      new_env[i] = my_malloc(sizeof(char) * (LEN(tmp->str) + 1));
      new_env[i] = tmp->str;
      tmp = tmp->next;
      i += 1;
    }
  return (new_env);
}

int		set_list_from_tab(t_list_env **list, char **env)
{
  int		i;

  i = -1;
  while (env[++i])
    {
      if ((*list = add_elem_list(*list, env[i])) == NULL)
	return (EXIT_ON_FAILURE);
    }
  return (EXIT_SUCCESS);
}
