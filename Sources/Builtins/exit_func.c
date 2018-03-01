/*
** exit_func.c for PSU_2015_minishell2 in /home/victor/Rendu/Sys_Unix/PSU_2015_minishell2/builtin
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Wed Apr 06 20:17:53 2016 Victor
** Last update Sun Jun 05 18:51:19 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

int		exit_func(t_data *dt, char **cmd)
{
  int		ret_ex;

  UNUSED(dt);
  if (cmd[1] != NULL && !cmd[2])
    {
      if (my_isnum(cmd[1]) == EXIT_ON_FAILURE)
	return (EXIT_ON_FAILURE);
      ret_ex = my_getnbr(cmd[1]);
      exit((ret_ex % 256));
    }
  else
    {
      my_printf("exit\n");
      exit(0);
    }
  return (EXIT_ON_FAILURE);
}
