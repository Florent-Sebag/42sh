/*
** variables.c for variables in /home/diagne_n/PSU_2015_42sh/Sources/Builtins
**
** Made by Nicolas Diagne
** Login   <diagne_n@epitech.net>
**
** Started on  Mon May 30 19:29:15 2016 Nicolas Diagne
** Last update Sun Jun 05 18:51:11 2016 Victor
*/

#include "my.h"

char	**variables_env(t_data *dt, char **tab)
{
  int	x;
  int	i;

  x = 0;
  i = 0;
  while (tab[x])
    {
      while (tab[x][i])
	{
	  if (tab[x][i] == '$' && tab[x][i + 1] == '$')
	    tab[x] = my_process_pid(tab[x], i, (i + 1), dt->process_pid);
	  else if (tab[x][i] == '$' && tab[x][i + 1] != '\0')
	    if ((tab[x] = change_variables(tab[x], dt->env, i + 1)) == NULL)
	      return (NULL);
	  i = i + 1;
	}
      i = 0;
      x = x + 1;
    }
  return (tab);
}

char	*change_variables(char *str, char **env, int i)
{
  char	*tmp;
  int	n;
  int	x;

  x = 0;
  n = EXIT_ON_FAILURE;
  tmp = NULL;
  while (env[x] != NULL &&
	 (n = compare_variables((str + i), env[x])) != EXIT_SUCCESS)
    x = x + 1;
  if (n == EXIT_ON_FAILURE)
    {
      fprintf(stderr, "%s: Undefined variable.\n", (str + i));
      return (NULL);
    }
  if (n == EXIT_SUCCESS)
    {
      tmp = my_strdup((env[x] + (LEN(str + i - 1))));
      str[i - 1] = '\0';
      tmp = strcat(str, tmp);
    }
  return (tmp);
}

int	compare_variables(char *str, char *tmp)
{
  int	x;

  x = 0;
  while (str[x])
    {
      if (str[x] == tmp[x])
	x = x + 1;
      else
	return (EXIT_ON_FAILURE);
    }
  if (tmp[x] == '=')
    return (EXIT_SUCCESS);
  return (EXIT_ON_FAILURE);
}

char	*my_process_pid(char *str, int s, int e, pid_t pid)
{
  char	*dest;
  char	*end;
  char	*tmp;

  if (str[0] == '$' && str[1] == '$' && str[2] == '\0')
    {
      tmp = my_malloc(sizeof(char) * 6);
      sprintf(tmp, "%d", pid);
      tmp[5] = '\0';
      return (tmp);
    }
  end = strdup(str + e + 1);
  tmp = my_malloc(sizeof(char) * 6 + LEN(end));
  sprintf(tmp, "%d", pid);
  tmp[5] = '\0';
  tmp = strcat(tmp, end);
  if (s > 0)
    {
      str[s] = '\0';
      dest = my_reallcpy(str, tmp);
      return (dest);
    }
  return (tmp);
}
