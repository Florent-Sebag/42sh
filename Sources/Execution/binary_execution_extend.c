/*
** binary_execution_extend.c for binary_execution_extend.c in /home/diagne_n/PSU_2015_42sh/Sources
**
** Made by Nicolas Diagne
** Login   <diagne_n@epitech.net>
**
** Started on  Tue May 10 13:38:47 2016 Nicolas Diagne
** Last update Sun Jun 05 18:51:09 2016 Victor
*/

#include "my.h"

void	my_redirect(t_bin *tree, t_data *dt)
{
  int	nopen;
  int	status;
  pid_t	pid;

  if ((nopen = open(tree->right->instruc, O_RDWR | O_CREAT, 00644)) == -1)
    exit(EXIT_FAILURE);
  dt->fork = 1;
  if ((pid = fork()) == -1)
    exit(EXIT_FAILURE);
  if (pid == 0)
    {
      dup2(nopen, 1);
      action_tree(dt, tree->left);
      if (dt->exec_return == 1)
	exit (-1);
      exit(0);
    }
  else
    {
      waitpid(pid, &status, WUNTRACED | WCONTINUED);
      close(nopen);
      if (status > 0)
	dt->exec_return = 1;
    }
  dt->fork = 0;
}

void	my_indirect(t_bin *tree, t_data *dt)
{
  int	nopen;
  int	status;
  pid_t	pid;

  if ((nopen = open(tree->right->instruc, O_RDWR | O_CREAT, 00644)) == -1)
      exit(EXIT_FAILURE);
  dt->fork = 1;
  if ((pid = fork()) == -1)
    exit(EXIT_FAILURE);
  if (pid == 0)
    {
      dup2(nopen, 0);
      action_tree(dt, tree->left);
      if (dt->exec_return == 1)
	exit (-1);
      exit(0);
    }
  else
    {
      waitpid(pid, &status, WUNTRACED | WCONTINUED);
      close(nopen);
      if (status > 0)
	dt->exec_return = 1;
    }
  dt->fork = 0;
}

void	my_double_redirect(t_bin *tree, t_data *dt)
{
  int	status;
  int	nopen;
  pid_t	pid;

  if ((nopen = open(tree->right->instruc, O_RDWR | O_APPEND
		    | O_CREAT, 00644)) == -1)
      exit(EXIT_FAILURE);
  dt->fork = 1;
  if ((pid = fork()) == -1)
    exit(EXIT_FAILURE);
  if (pid == 0)
    {
      dup2(nopen, 1);
      action_tree(dt, tree->left);
      if (dt->exec_return == 1)
	exit (-1);
      exit(0);
    }
  else
    {
      waitpid(pid, &status, WUNTRACED | WCONTINUED);
      close(nopen);
      if (status > 0)
	dt->exec_return = 1;
    }
  dt->fork = 0;
}

void	my_double_indirect(t_bin *tree, t_data *dt)
{
  (void)dt;
  char	*str;
  int	nopen;

  if ((nopen = open(".tartiflette$$", O_RDWR | O_CREAT, 00644)) == -1)
    exit (EXIT_FAILURE);
  my_printf(">>");
  str = get_next_line(0);
  while ((my_strcmp(tree->right->instruc, str)) != 0)
    {
      if ((write(nopen, str, my_strlen(str))) == -1)
	exit (EXIT_FAILURE);
      if ((write(nopen, "\n", 1)) == -1)
	exit (EXIT_FAILURE);
      my_printf(">>");
      free(str);
      str = get_next_line(0);
    }
  my_double_indirect_extend(nopen);
}

void	my_double_indirect_extend(int nopen)
{
  off_t	x;
  char	*str;

  if ((x = lseek(nopen, 0, SEEK_SET)) == -1)
    exit (EXIT_FAILURE);
  while ((str = get_next_line(nopen)))
    {
      my_printf("%s\n", str);
      free(str);
    }
  close(nopen);
  remove(".tartiflette$$");
}
