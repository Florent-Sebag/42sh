/*
** tab_to_str.c for h in /home/sebag/Bureau/PSU_2015_42sh/Sources/Misc/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Sat Jun  4 16:17:01 2016 Florent Sebag
** Last update Sun Jun 05 18:50:56 2016 Victor
*/

#include "my.h"

int	len_of_all(char **tab)
{
  int	i;
  int	j;
  int	res;

  res = 0;
  i = 0;
  j = 0;
  while (tab[i] != NULL)
    {
      while (tab[i][j] != '\0')
	{
	  res = res + 1;
	  j = j + 1;
	}
      res = res + 2;
      j = 0;
      i = i + 1;
    }
  return (res);
}

char	*tab_to_str(char **tab)
{
  char	*res;
  int	i;
  int	j;
  int	x;

  i = -1;
  j = -1;
  x = 0;
  res = my_malloc(sizeof(char) * len_of_all(tab));
  while (tab[++i] != NULL)
    {
      while (tab[i][++j] != '\0')
	{
	  res[x] = tab[i][j];
	  x = x + 1;
	}
      if (tab[i + 1] != NULL)
	{
	  res[x] = ' ';
	  x = x + 1;
	}
      j = -1;
    }
  res[x] = 0;
  return (res);
}
