/*
** path.c for path.c in /home/diagne_n/PSU_2015_42sh/Sources
**
** Made by Nicolas Diagne
** Login   <diagne_n@epitech.net>
**
** Started on  Tue May 17 11:51:23 2016 Nicolas Diagne
** Last update Sun Jun 05 18:51:07 2016 Victor
*/

#include "my.h"

char    **get_path_cmd(char **path, char *str)
{
  char  **real_path;
  int   x;
  int   size;

  x = 0;
  if (str[0] == '/' || (str[0] == '.' && str[1] == '/'))
    {
      real_path = my_malloc(sizeof(char*) * 2);
      real_path[0] = my_strdup(str);
      real_path[1] = NULL;
      return (real_path);
    }
  real_path = my_malloc(sizeof(char*) * (nb_line(path) + 1));
  while (path[x] != NULL)
    {
      size = my_strlen(path[x]) + my_strlen(str) + 1;
      real_path[x] = my_malloc(sizeof(char) * size);
      real_path[x] = my_concat_path(path[x], str);
      x = x + 1;
    }
  real_path[x] = NULL;
  return (real_path);
}

int	check_path(char **tab)
{
  int	x;

  x = 0;
  while (tab[x])
    {
      if ((access(tab[x], F_OK)) == 0)
	return (x);
      x = x + 1;
    }
  return (EXIT_ON_FAILURE);
}
