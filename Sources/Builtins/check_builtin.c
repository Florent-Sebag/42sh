/*
** check_builtin.c for PSU_2015_minishell2 in /home/victor/Rendu/Sys_Unix/PSU_2015_minishell2/builtin
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Wed Apr 06 19:10:22 2016 Victor
** Last update Sun Jun 05 19:28:40 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

t_builtin	tab_builtin[] =
    {
      {"cd", cd_func},
      {"echo", echo_cmd},
      {"exit", exit_func},
      {"setenv", setenv_func},
      {"unsetenv", unsetenv_func},
      {"alias", make_alias},
      {"unalias", del_alias},
      {NULL, NULL}
    };

int		check_builtin(t_data *dt, char *str)
{
  int		i;

  i = -1;
  if ((regroup_function(dt, str)) == EXIT_ON_FAILURE)
    return (EXIT_ON_FAILURE);
  while (tab_builtin[++i].str)
    {
      if (!CMP(dt->cmd[0], tab_builtin[i].str))
	{
	  if (tab_builtin[i].func(dt, dt->cmd) == EXIT_ON_FAILURE)
	    return (EXIT_ON_FAILURE);
	  return (EXIT_SUCCESS);
	}
    }
  return (EXIT_FAILURE);
}

int		regroup_function(t_data *dt, char *str)
{
  if ((dt->cmd = variables_env(dt, my_str_to_wordtab(str, ' '))) == NULL)
    return (EXIT_ON_FAILURE);
  return (EXIT_SUCCESS);
}
