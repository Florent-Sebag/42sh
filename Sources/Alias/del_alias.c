/*
** del_alias.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources/Alias
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Sat Jun 04 13:02:46 2016 Victor
** Last update Sun Jun 05 18:51:32 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

static void	find_elem_to_del(t_data *dt, char *cmd, bool state)
{
  t_elem	*tmp;
  int		count;

  tmp = dt->alias->_head;
  count = 1;
  while (tmp != dt->alias->_head || state)
    {
      if (!CMP(((t_alias *)tmp->_data)->old, cmd))
	{
	  printf("%d\n", count);
	  dt->alias->erase(dt->alias, count);
	  return ;
	}
      count += 1;
      state = false;
    }
}

static int	unalias_func(t_data *dt, char **cmd)
{
  int		i;

  i = 0;
  while (cmd[++i])
    {
      find_elem_to_del(dt, cmd[i], true);
      i += 1;
    }
  return (0);
}

int		del_alias(t_data *dt, char **cmd)
{
  if (cmd[1])
    unalias_func(dt, cmd);
  else
    {
      fprintf(stderr, "unalias: Too few arguments.\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
