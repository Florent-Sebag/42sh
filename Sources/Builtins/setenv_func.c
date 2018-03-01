/*
** setenv_func.c for PSU_2015_minishell2 in /home/victor/Rendu/Sys_Unix/PSU_2015_minishell2/builtin
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Wed Apr 06 20:18:13 2016 Victor
** Last update Sun Jun 05 18:51:18 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

int		size_tab(char **tab)
{
  int		i;
  int		count;

  i = -1;
  count = 0;
  while (tab[++i])
    count += 1;
  return (count);
}

static bool	exist_in_env(char *new, t_data *dt, char *str)
{
  t_list_env	*tmp;

  tmp = dt->list_env;
  if (!tmp)
    return (0);
  while (dt->list_env)
    {
      if (!NCMP(str, dt->list_env->str, LEN(str)))
	{
	  dt->list_env->str = strdup(new);
          dt->list_env = tmp;
          dt->env = set_tab_from_list(dt);
	  return (true);
	}
      dt->list_env = dt->list_env->next;
    }
  dt->list_env = tmp;
  return (false);
}

int		setenv_func(t_data *dt, char **cmd)
{
  char		*new;

  if (!cmd[1])
    {
      print_env(dt->env);
      return (0);
    }
  if (size_tab(cmd) > 3)
    {
      my_printf("setenv: Too many arguments.\n");
      return (0);
    }
  new = my_reallcpy(cmd[1], "=");
  (cmd[2] == NULL) ? (0) : (new = my_reallcpy(new, cmd[2]));
  if (exist_in_env(new, dt, cmd[1]) == true)
    return (0);
  dt->list_env = add_elem_list(dt->list_env, new);
  dt->env = set_tab_from_list(dt);
  if (!CMP(cmd[1], "PATH"))
    dt->reserve.tab_path = get_path(dt->env);
  g_ret = 0;
  return (0);
}
