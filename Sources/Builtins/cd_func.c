/*
** cd_func.c for PSU_2015_minishell2 in /home/victor/Rendu/Sys_Unix/PSU_2015_minishell2/builtin
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Wed Apr 06 20:16:04 2016 Victor
** Last update Sun Jun 05 18:51:21 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

static int	get_home_path(char **envp)
{
  int		i;

  i = -1;
  while (envp[++i])
    {
      if (!my_strncmp(envp[i], "HOME=", 5))
	return (i);
    }
  return (EXIT_ON_FAILURE);
}

static int	find_pwd_and_update(t_data *dt, char *new)
{
  t_list_env	*tmp;

  tmp = dt->list_env;
  while (dt->list_env)
    {
      if (!my_strncmp(dt->list_env->str, "PWD=", 4))
	{
	  new = my_reallcpy("PWD=", new);
	  dt->list_env->str = new;
	}
      dt->list_env = dt->list_env->next;
    }
  dt->list_env = tmp;
  dt->env = set_tab_from_list(dt);
  return (0);
}

static int	update_pwd(t_data *dt, char *pwd)
{
  char		cwd[1024];

  if (getcwd(cwd, sizeof(cwd)) == NULL)
    return (EXIT_ON_FAILURE);
  dt->reserve.oldpwd = my_strdup(pwd);
  find_pwd_and_update(dt, cwd);
  return (0);
}

static int	cd_extend(t_data *dt, char **cmd, char *pwd)
{
  if (!CMP(cmd[1], "-"))
    {
      if (chdir(dt->reserve.oldpwd) == EXIT_ON_FAILURE)
	return (EXIT_ON_FAILURE);
    }
  else if (access(cmd[1], F_OK) == EXIT_ON_FAILURE)
    {
      fprintf(stderr, "cd: %s: No such file or directory.\n", cmd[1]);
      return (EXIT_ON_FAILURE);
    }
  else if (access(cmd[1], X_OK) == EXIT_ON_FAILURE)
    {
      fprintf(stderr, "%s: Permission denied.\n", cmd[1]);
      return (EXIT_ON_FAILURE);
    }
  else if (chdir(cmd[1]) == EXIT_ON_FAILURE)
    {
      fprintf(stderr, "cd: %s: No such file or directory.\n", cmd[1]);
      return (EXIT_ON_FAILURE);
    }
  update_pwd(dt, pwd);
  return (EXIT_SUCCESS);
}

int		cd_func(t_data *dt, char **cmd)
{
  int		pos;
  char		pwd[1024];

  g_ret = 1;
  if (getcwd(pwd, 1024) == NULL)
    return (EXIT_ON_FAILURE);
  if ((pos = get_home_path(dt->env)) == EXIT_ON_FAILURE)
    return (EXIT_ON_FAILURE);
  if (cmd[1] == NULL)
    {
      if (chdir(&dt->env[pos][5]) == EXIT_ON_FAILURE)
	return (EXIT_ON_FAILURE);
    }
  else if (cd_extend(dt, cmd, pwd) == EXIT_ON_FAILURE)
    return (EXIT_ON_FAILURE);
  g_ret = 0;
  return (EXIT_SUCCESS);
}
