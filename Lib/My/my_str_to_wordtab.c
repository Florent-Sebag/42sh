/*
** my_str_to_wordtab.c for my_str_to_wordtab in Piscine 1/Piscine_C_J08/ex_04
**
** Made by Victor Mariton
** Login   <marito_v@epitech.net>
**
** Started on  Wed Oct  7 21:59:50 2015 Victor Mariton
** Last update Sun Jun 05 18:51:43 2016 Victor
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_lib.h"

static int	count_w(char *str, char sep)
{
  int		i;
  int		count;

  i = -1;
  count = 1;
  while (str[++i])
    {
      if (str[i] == sep || str[i] == '\t')
	count += 1;
    }
  return (count);
}

static int	my_strlen_space(char *str, char sep)
{
  int		i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == sep || str[i] == '\t')
	return (i);
    }
  return (i);
}

char		**my_str_to_wordtab(char *str, char sep)
{
  char		**tab;
  int		nb_w;
  int		count;
  int		j;

  j = -1;
  nb_w = count_w(str, sep);
  if ((tab = malloc(sizeof(char *) * (nb_w + 1))) == NULL)
    exit(EXIT_ON_FAILURE);
  while (++j != nb_w)
    {
      if ((tab[j] = malloc(sizeof(char) * (my_strlen_space(str, sep) + 1))) == NULL)
	exit(EXIT_ON_FAILURE);
      count = -1;
      while (++count < my_strlen_space(str, sep))
	tab[j][count] = str[count];
      tab[j][count] = '\0';
      str += my_strlen_space(str, sep) + 1;
    }
  tab[j] = NULL;
  return (tab);
}
