/*
** create_my_env.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/src/EnvManagement
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Wed Apr 27 16:56:56 2016 Victor
** Last update Sun Jun 05 18:51:11 2016 Victor
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

/*
** Si pas d'environnement : création de notre propre environnement
*/
char		**create_my_env()
{
  char		**tab;
  char		cwd[1024];
  char		*pwd;
  char		*old;

  if (getcwd(cwd, 1024) == NULL)
    return (NULL);
  pwd = strcpy("PWD=", cwd);
  old = strcpy("OLDPWD=", cwd);
  tab = my_malloc(sizeof(char *) * 5);
  tab[0] = strdup("PATH=/usr/local/bin:/bin:/usr/bin");
  tab[1] = strdup(pwd);
  tab[2] = strdup(old);
  tab[3] = strdup("USER=Dommage");
  tab[4] = NULL;
  return (tab);
}

/*
** Copie de l'env
*/
char		**copy_env(char **env)
{
  char		**new;
  int		i;

  i = -1;
  new = my_malloc(sizeof(char *) * (nb_line(env) + 1));
  while (env[++i])
    new[i] = strdup(env[i]);
  new[i] = NULL;
  return (new);
}
