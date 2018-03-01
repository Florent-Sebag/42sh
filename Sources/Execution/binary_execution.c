/*
** binary_execution.c for binary_execution.c in /home/diagne_n/PSU_2015_42sh/Sources
**
** Made by Nicolas Diagne
** Login   <diagne_n@epitech.net>
**
** Started on  Tue May 10 13:16:25 2016 Nicolas Diagne
** Last update Sun Jun 05 18:51:09 2016 Victor
*/

#include "my.h"

static	t_token	tokentab[] =
  {
    {&my_semicolon, ";"},
    {&my_double_and, "&&"},
    {&my_double_or, "||"},
    {&my_redirect, ">"},
    {&my_double_redirect, ">>"},
    {&my_indirect, "<"},
    {&my_double_indirect, "<<"},
    {&my_pipe, "|"},
    {0, NULL},
  };

void	execute_token(t_bin *tree, t_data *dt)
{
  int	x;

  x = 0;
  while (tokentab[x].flags != NULL)
    {
      if (my_strcmp(tree->instruc, tokentab[x].flags) == 0)
	{
	  tokentab[x].ptr(tree, dt);
	  return ;
	}
      x += 1;
    }
}

void	my_semicolon(t_bin *tree, t_data *dt)
{
  if (dt->exec_return == 0)
    action_tree(dt, tree->left);
  if (dt->exec_return == 0)
    action_tree(dt, tree->right);
}

void	my_double_and(t_bin *tree, t_data *dt)
{
  action_tree(dt, tree->left);
  if (dt->exec_return == 0)
    action_tree(dt, tree->right);
  dt->exec_return = 0;
}

void	my_double_or(t_bin *tree, t_data *dt)
{
  action_tree(dt, tree->left);
  if (dt->exec_return == 1)
    {
      dt->exec_return = 0;
      g_ret = 0;
      action_tree(dt, tree->right);
    }
}
