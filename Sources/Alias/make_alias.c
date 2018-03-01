/*
** make_alias.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources/Alias
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Fri Jun 03 22:20:46 2016 Victor
** Last update Sun Jun 05 18:51:26 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

static void	print_alias(t_data *dt, bool state)
{
  t_elem	*tmp;
  t_alias	*alias;

  tmp = dt->alias->_head;
  while (tmp != dt->alias->_head || state)
    {
      alias = tmp->_data;
      if (words(alias->new) == 1)
	printf("%s\t%s\n", alias->old, alias->new);
      else
	printf("%s\t(%s)\n", alias->old, alias->new);
      state = false;
      tmp = tmp->_next;
    }
}

static void	add_alias_to_list(t_data *dt, char **cmd)
{
  t_alias	*new;
  char		*new_str;
  int		i;

  new = my_malloc(sizeof(t_alias));
  new->old = cmd[1];
  new_str = NULL;
  i = 1;
  while (cmd[++i])
    {
      new_str = my_reallcpy(new_str, cmd[i]);
      if (cmd[i + 1])
	new_str = my_reallcpy(new_str, " ");
    }
  new->new = new_str;
  dt->alias->push_back(dt->alias, new);
}

int		make_alias(t_data *dt, char **cmd)
{
  if (!cmd[1])
    print_alias(dt, true);
  else if (cmd[1] && cmd[2])
    add_alias_to_list(dt, cmd);
  return (EXIT_SUCCESS);
}
