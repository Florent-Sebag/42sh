/*
** my_str_to_wordtab.c for my_str_to_wordtab in Piscine 1/Piscine_C_J08/ex_04
**
** Made by Victor Mariton
** Login   <marito_v@epitech.net>
**
** Started on  Wed Oct  7 21:59:50 2015 Victor Mariton
** Last update Sun Jun 05 18:50:57 2016 Victor
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static int	count_w(char *str, char sep, bool state)
{
  int		i;
  int		count;

  i = -1;
  count = 1;
  while (str[++i] && state)
    {
      if (str[i] == sep || str[i] == '\t')
	{
	  count += 1;
	  state = false;
	}
    }
  return (count);
}

static int	my_strlen_space(char *str, char sep, bool state)
{
  int		i;

  i = -1;
  while (str[++i])
    {
      if ((str[i] == sep || str[i] == '\t') && state)
	return (i);
    }
  return (i);
}

char		**my_wordtab(char *str, char sep, bool state)
{
  char		**tab;
  int		nb_w;
  int		count;
  int		j;

  j = -1;
  nb_w = count_w(str, sep, state);
  tab = my_malloc(sizeof(char *) * (nb_w + 1));
  while (++j != nb_w)
    {
      tab[j] = my_malloc(sizeof(char) * (my_strlen_space(str, sep, state) + 1));
      count = -1;
      while (++count < my_strlen_space(str, sep, state))
	tab[j][count] = str[count];
      tab[j][count] = '\0';
      str += my_strlen_space(str, sep, state) + 1;
      state = false;
    }
  tab[j] = NULL;
  return (tab);
}
