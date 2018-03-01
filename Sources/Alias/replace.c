/*
** replace.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources/Alias
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Wed Jun 01 10:59:06 2016 Victor
** Last update Sun Jun 05 18:51:25 2016 Victor
*/

#include "my.h"
#include <stdlib.h>

static int	exist(char *to_find, t_elem *list)
{
  bool		turn;
  t_elem	*tmp;

  turn = true;
  tmp = list;
  if (!tmp)
    return (EXIT_FAILURE);
  while (tmp != list || turn)
    {
      if (!CMP(to_find, ((t_alias *)tmp->_data)->old))
	return (EXIT_SUCCESS);
      tmp = tmp->_next;
      turn = false;
    }
  return (EXIT_FAILURE);
}

char	*replace_string(t_data *dt, char *cmd)
{
  int		count;
  char		*str;
  t_elem	*tmp;

  str = first_word(cmd);
  cmd += LEN(str);
  count = -1;
  while (exist(str, dt->alias->_head) != EXIT_FAILURE)
    {
      tmp = dt->alias->_head;
      while (tmp != dt->alias->_back)
	{
	  (!CMP(((t_alias *)tmp->_data)->old, str)) ? (NORME) : (0);
	  tmp = tmp->_next;
	}
      (!CMP(((t_alias *)tmp->_data)->old, str)) ? (NORME) : (0);
      if (++count > 50)
	return (NULL);
    }
  (cmd[0]) ? (str = my_reallcpy(str, cmd)) : (0);
  // printf("[%s]\n", str);
  return (str);
}
