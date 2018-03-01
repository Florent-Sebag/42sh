/*
** main_loop.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Wed Apr 27 18:15:06 2016 Victor
** Last update Sun Jun 05 18:52:03 2016 Victor
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "my.h"

int	get_user_var(char **envp)
{
  int	i;

  i = -1;
  while (envp[++i])
    {
      if (!(NCMP(envp[i], "USER=", 5)))
	return (i);
    }
  return (0);
}

void	sig_handler(int sig)
{
  if (sig == SIGINT)
    my_printf(" Pas très gentil ça...\n(%s --> %d) ", USER, g_env.compt);
}

int		fill_struct(t_data *dt, char **env)
{
  g_env.env = dt->env = env;
  g_env.compt = 0;
  dt->fork = 0;
  dt->exec_return = 0;
  dt->process_pid = getpid();
  dt->reserve.tab_path = get_path(env);
  dt->reserve.home = dt->reserve.oldpwd = NULL;
  dt->list_env = NULL;
  dt->list_alias = list_create();
  dt->alias = list_create();
  set_list_from_tab(&dt->list_env, dt->env);
  if (load_our_file(dt, env) == EXIT_ON_FAILURE)
    dt->alias = NULL;
  else
    list_destroy(dt->list_alias);
  dt->list_alias = list_create();
  return (EXIT_SUCCESS);
}

void		main_loop(char **env)
{
  t_data	dt;
  char		*str;

  str = NULL;
  fill_struct(&dt, env);
  signal(SIGINT, sig_handler);
  getcwd(dt.reserve.oldpwd, 1024);
  while (str || !g_env.compt)
    {
      g_env.env = dt.env;
      if (isatty(0))
      	my_printf("(%s --> %d) ", USER, g_env.compt);
      str = get_next_line(0);
      if (str && CMP(str, "\0"))
	main_func(&dt, str);
      g_env.compt += 1;
      if (str)
      	free(str);
    }
  if (isatty(0))
    fprintf(stderr, "exit\n");
}
