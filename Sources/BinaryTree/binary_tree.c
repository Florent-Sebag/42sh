/*
** binary_tree.c for PSU_2015_minishell2 in /home/victor/Rendu/Sys_Unix/PSU_2015_minishell2/src
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Thu Mar 31 20:26:22 2016 Victor
** Last update Sun Jun 05 18:51:24 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

t_bin		*create_tree(char *str, int *err)
{
  t_bin		*root;
  int		pos_op;
  int		size_op;

  root = my_malloc(sizeof(t_bin));
  if (((str = epur_str(str)) == NULL))
    return (NULL);
  if ((pos_op = pos_prio_operator(str, &size_op)) == EXIT_ON_FAILURE)
    {
      root->instruc = str;
      root->type = 1;
      root->left = NULL;
      root->right = NULL;
    }
  else
    {
      if ((root->instruc = epur_str(get_ope(str, size_op, pos_op))) == NULL)
	return (NULL);
      root->type = 0;
      str[pos_op] = '\0';
      root->left = create_tree(str, err);
      root->right = create_tree((str + pos_op + size_op), err);
      check_error_ope(root, err);
    }
  return (root);
}
