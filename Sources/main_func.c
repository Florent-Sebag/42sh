/*
** main_func.c for main_func.c in /home/diagne_n/PSU_2015_42sh/Sources
**
** Made by Nicolas Diagne
** Login   <diagne_n@epitech.net>
**
** Started on  Wed Jun  1 14:50:52 2016 Nicolas Diagne
** Last update Sun Jun 05 18:52:02 2016 Victor
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

/*
** Fonction qui execute les commandes builtins/execve
*/
void	action_function(t_data *dt, char *str)
{
  char	**path_cmd;
  int	i;
  int	x;

  if ((i = check_builtin(dt, str)) == EXIT_FAILURE)
    {
      path_cmd = get_path_cmd(dt->reserve.tab_path, dt->cmd[0]);
      if ((x = check_path(path_cmd)) == EXIT_ON_FAILURE)
	{
	  dt->exec_return = 1;
	  g_ret = 1;
	  fprintf(stderr, "%s: Command not found.\n", dt->cmd[0]);
	}
      else
	if ((execute_execve(dt, path_cmd[x], dt->cmd)) == EXIT_ON_FAILURE)
	  {
	    dt->exec_return = 1;
	    g_ret = 1;
	  }
    }
  else if (i == EXIT_ON_FAILURE)
    {
      dt->exec_return = 1;
      g_ret = 1;
    }
}

/*
** Parcours et execute l'arbre binaire (token et fonction)
*/
void	action_tree(t_data *dt, t_bin *tree)
{
  if (tree->type == 0)
    execute_token(tree, dt);
  else
    action_function(dt, tree->instruc);
}

void		main_func(t_data *dt, char *str)
{
  int		err;

  err = 0;
  if ((str = epur_str(str)) == NULL || !CMP(str, "\0"))
    return ;
    if ((str = replace_string(dt, str)) == NULL)
      {
        fprintf(stderr, "CARE /!\\ Alias loop detected !\n");
        return ;
      }
  if ((dt->tree = create_tree(str, &err)) == NULL)
    return ;
  if (err == EXIT_ON_FAILURE)
    return ;
  action_tree(dt, dt->tree);
}
