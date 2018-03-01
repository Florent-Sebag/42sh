/*
** error_ope.c for PSU_2015_minishell2 in /home/victor/Rendu/Sys_Unix/PSU_2015_minishell2/src
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Mon Apr 04 17:21:46 2016 Victor
** Last update Sun Jun 05 18:51:24 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

static int		missing_name(t_bin *tree, int *err)
{
  if (!CMP(tree->instruc, ">>") || !CMP(tree->instruc, ">"))
    {
      if (!CMP(tree->right->instruc, "\0"))
	{
	  my_printf("%e\n", "Missing name for redirect.");
          *err = EXIT_ON_FAILURE;
	  return (EXIT_ON_FAILURE);
	}
      if (!CMP(tree->left->instruc, "\0"))
	{
	  my_printf("%e\n", "Invalid null command.");
          *err = EXIT_ON_FAILURE;
	  return (EXIT_ON_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}

static int		null_command(t_bin *tree, int *err)
{
  if (!CMP(tree->instruc, "|"))
    {
      if (!CMP(tree->right->instruc, "\0") || !CMP(tree->left->instruc, "\0"))
	{
	  my_printf("%e\n", "Invalid null command.");
          *err = EXIT_ON_FAILURE;
	  return (EXIT_ON_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}

static int		ambigous_input(t_bin *tree, int *err)
{
  if (!CMP(tree->instruc, "<") || !CMP(tree->instruc, "<<"))
    {
      if (!CMP(tree->right->instruc, "<<") || !CMP(tree->right->instruc, "<"))
	{
	  my_printf("%e\n", "Ambigous input redirect.");
          *err = EXIT_ON_FAILURE;
	  return (EXIT_ON_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}

static int		ambigous_output(t_bin *tree, int *err)
{
  if (!CMP(tree->instruc, ">") || !CMP(tree->instruc, ">>"))
    {
      if (!CMP(tree->right->instruc, "|"))
	{
	  my_printf("%e\n", "Ambigous input redirect.");
          *err = EXIT_ON_FAILURE;
	  return (EXIT_ON_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}

int			check_error_ope(t_bin *tree, int *err)
{
  if (!CMP(tree->instruc, ">>") || !CMP(tree->instruc, ">"))
    {
      if (!CMP(tree->right->instruc, ">>") || !CMP(tree->left->instruc, ">>") ||
	  !CMP(tree->right->instruc, ">") || !CMP(tree->left->instruc, ">"))
	{
	  my_printf("%e\n", "Ambigous output redirect.");
	  *err = EXIT_ON_FAILURE;
	  return (EXIT_ON_FAILURE);
	}
    }
  (*err != EXIT_ON_FAILURE) ? ambigous_output(tree, err) : (0);
  (*err != EXIT_ON_FAILURE) ? ambigous_input(tree, err) : (0);
  (*err != EXIT_ON_FAILURE) ? missing_name(tree, err) : (0);
  (*err != EXIT_ON_FAILURE) ? null_command(tree, err) : (0);
  return (EXIT_SUCCESS);
}
