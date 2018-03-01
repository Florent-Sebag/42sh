/*
** cpy_tab.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources/Misc
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Sat Jun 04 23:07:50 2016 Victor
** Last update Sun Jun 05 18:51:02 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

char		**have_good_tab(char *str, char **tab)
{
  int		i;
  char		**new;

  i = 0;
  if (!tab)
    {
      new = my_malloc(sizeof(char *) * 2);
      new[0] = strdup(str);
      new[1] = NULL;
    }
  else
    {
      new = my_malloc(sizeof(char *) * (nb_line(tab) * 3));
      tab[0] = strdup(str);
      while (tab[++i])
	new[i] = strdup(tab[i]);
      new[i] = NULL;
    }
  return (new);
}

char		**add_line(char **tab, char *str)
{
  int		i;
  char		**new;

  i = -1;
  if (!tab)
    {
      new = my_malloc(sizeof(char *) * 2);
      new[0] = strdup(str);
      new[1] = NULL;
    }
  else
    {
      new = my_malloc(sizeof(char *) * (nb_line(tab) * 3));
      while (tab[++i])
	new[i] = strdup(tab[i]);
      new[i] = strdup(str);
      new[i + 1] = NULL;
    }
  return (new);
}

char		**cpy_tab(char **first, char **sec)
{
  char		**new;
  int		i;
  int		j;

  if (!first)
    return (sec);
  if (!sec)
    return (NULL);
  new = my_malloc(sizeof(char *) * (nb_line(first) + nb_line(sec) + 1));
  i = -1;
  while (first[++i])
    {
      new[i] = strdup(first[i]);
      free(first[i]);
    }
  j = -1;
  while (sec[++j])
    {
      new[i] = strdup(sec[j]);
      i += 1;
      free(sec[j]);
    }
  new[i] = NULL;
  return (new);
}
