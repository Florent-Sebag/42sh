/*
** my_minishell.c for my_minishell.c in /home/diagne_n/PSU_2015_42sh/Sources
**
** Made by Nicolas Diagne
** Login   <diagne_n@epitech.net>
**
** Started on  Tue May 17 12:08:56 2016 Nicolas Diagne
** Last update Sun Jun 05 18:51:08 2016 Victor
*/

#include "my.h"

int	execute_execve(t_data *dt, char *path, char **cmd)
{
  int	status;

  status = 0;
  if (dt->fork == 0)
    my_minishell(dt, path, cmd, status);
  else if (dt->fork == 1)
    my_minishell_extend(path, dt->env, cmd);
  return (0);
}

int	my_minishell(t_data *dt, char *path, char **cmd, int status)
{
  pid_t	pid;

  if ((pid = fork()) == -1)
    {
      fprintf(stderr, "%s\n", "[ERROR]: fork problem");
      exit(EXIT_FAILURE);
    }
  if (pid == 0)
    {
      if ((execve(path, cmd, dt->env)) == -1)
	{
	  fprintf(stderr, "%s\n", "[ERROR]: execve problem");
	  exit(EXIT_FAILURE);
	}
    }
  else
    {
      if ((waitpid(pid, &status, WUNTRACED | WCONTINUED)) == -1)
	exit(EXIT_FAILURE);
      if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
	fprintf(stderr, "%s\n", "Segmentation fault\n");
      if (status > 0)
	return (EXIT_ON_FAILURE);
    }
  return (0);
}

void	my_minishell_extend(char *path, char **env, char **cmd)
{
  if ((execve(path, cmd, env)) == -1)
    {
      fprintf(stderr, "%s\n", "[ERROR]: execve problem");
      exit(EXIT_FAILURE);
    }
}
