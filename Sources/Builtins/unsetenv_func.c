/*
** unsetenv_func.c for PSU_2015_minishell2 in /home/victor/Rendu/Sys_Unix/PSU_2015_minishell2/builtin
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Wed Apr 06 20:18:04 2016 Victor
** Last update Sun Jun 05 18:51:15 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

static void	del_elem(t_data *dt, char *tmp)
{
  t_list_env	*nav;

  if (!my_strncmp(dt->list_env->str, tmp, LEN(tmp)))
    {
      dt->list_env = dt->list_env->next;
      return ;
    }
  nav = dt->list_env;
  while (dt->list_env->next)
    {
      if (!my_strncmp(dt->list_env->next->str, tmp, LEN(tmp)))
	dt->list_env->next = dt->list_env->next->next;
      dt->list_env = dt->list_env->next;
    }
  if (!my_strncmp(dt->list_env->str, tmp, LEN(tmp)))
    dt->list_env->next = NULL;
  dt->list_env = nav;
}

int		unsetenv_func(t_data *dt, char **cmd)
{
  char		*tmp;
  int		i;

  i = 0;
  while (cmd[++i])
    {
      tmp = my_reallcpy(cmd[i], "=");
      del_elem(dt, tmp);
    }
  dt->env = set_tab_from_list(dt);
  g_ret = 0;
  return (0);
}
