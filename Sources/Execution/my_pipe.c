/*
** my_pipe.c for my_pipe.c in /home/diagne_n/PSU_2015_42sh/Sources/Execution
**
** Made by Nicolas Diagne
** Login   <diagne_n@epitech.net>
**
** Started on  Sun May 29 20:12:02 2016 Nicolas Diagne
** Last update Sun Jun 05 18:51:08 2016 Victor
*/

#include "my.h"

void	my_pipe(t_bin *tree, t_data *dt)
{
  pid_t	pid;
  int	fd[2];
  int	status;

  g_ret = 0;
  if (pipe(fd) == -1 || (pid = fork()) == -1)
    exit(EXIT_FAILURE);
  dt->fork = 1;
  if (pid == 0)
    {
      close(fd[0]);
      dup2(fd[1], 1);
      action_tree(dt, tree->left);
      if (dt->exec_return == 1)
        exit(-1);
      exit(0);
    }
  else
    {
      waitpid(pid, &status, WUNTRACED | WCONTINUED);
      between_pipe(tree, dt, fd, status);
    }
}

void	between_pipe(t_bin *tree, t_data *dt, int fd[2], int status)
{
  if (status == 0)
    my_pipe_extend(tree, dt, fd);
  else
    {
      dt->exec_return = 1;
      g_ret = 1;
    }
  close(fd[0]);
  close(fd[1]);
  dt->fork = 0;
}

void	my_pipe_extend(t_bin *tree, t_data *dt, int fd[2])
{
  int	x;
  pid_t	pid1;
  int	status;

  if ((x = check_builtin(dt, tree->right->instruc)) == EXIT_FAILURE
      || x == EXIT_ON_FAILURE)
    {
      if ((pid1 = fork()) == -1)
	exit(EXIT_FAILURE);
      close(fd[1]);
      if (pid1 == 0)
	{
	  dup2(fd[0], 0);
	  action_tree(dt, tree->right);
	  if (dt->exec_return == 1)
	    exit (-1);
	  exit(0);
	}
      waitpid(pid1, &status, WUNTRACED | WCONTINUED);
      if (status > 0)
	{
	  dt->exec_return = 1;
	  g_ret = 1;
	}
    }
}
