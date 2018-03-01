/*
** get_path.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources/EnvManagement
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Thu Apr 28 10:15:07 2016 Victor
** Last update Sun Jun 05 18:51:10 2016 Victor
*/

#include "my.h"

static char		**copy_tab(char **tab)
{
  char			**new;
  int			i;

  i = -1;
  new = my_malloc(sizeof(char *) * (nb_line(tab) + 3));
  while (tab[++i])
    {
      new[i] = strdup(tab[i]);
      free(tab[i]);
    }
  free(tab);
  new[i] = strdup("./");
  new[i + 1] = NULL;
  return (new);
}

static char	**my_path()
{
  char		*str;
  char		**tab;

  str = strdup("PATH=/usr/local/bin:/bin:/usr/bin:./");
  tab = my_str_to_wordtab(&str[5], ':');
  return (tab);
}

char		**get_path(char **env)
{
  int		i;
  char		**tab;

  i = -1;
  while (env && env[++i])
    {
      if (!NCMP(env[i], "PATH=", 5))
	{
	  tab = my_str_to_wordtab(&env[i][5], ':');
	  tab = copy_tab(tab);
	  return (tab);
	}
    }
  return (my_path());
}
