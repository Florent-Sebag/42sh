/*
** excla_in.c for h in /home/sebag/Bureau/PSU_2015_42sh/Sources/Historic/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Fri Jun  3 18:01:36 2016 Florent Sebag
** Last update Sun Jun 05 18:52:12 2016 Victor
*/

#include "my.h"

void	rm_to_tab(char **tab, int i)
{
  while (tab[i] != NULL)
    {
      tab[i] = tab[i + 1];
      i = i + 1;
    }
}

int	len_w_excla(char *str)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (str[i] != '!')
    i = i + 1;
  while (str[i] != '\0')
    {
      res = res + 1;
      i = i + 1;
    }
  return (res + 1);
}

char	*compact(char *src, char *dest)
{
  int	i;
  int	j;
  char	*res;

  res = my_malloc(sizeof(char) * (my_strlen(src) + my_strlen(dest) + 1));
  j = 0;
  i = 0;
  while (src[i] != '\0')
    {
      res[j] = src[i];
      i = i + 1;
      j = j + 1;
    }
  i = 0;
  while (dest[i] != '\0')
    {
      res[j] = dest[i];
      j = j + 1;
      i = i + 1;
    }
  free(src);
  res[j] = '\0';
  return (res);
}

char	*find_and_rm_excla(char *str)
{
  char	*res;
  int	i;
  int	j;

  j = 0;
  i = -1;
  if (my_strcmp(str, "!!") == 1)
    return (str);
  while (str[++i] != '!');
  i = i + 1;
  res = my_malloc(sizeof(char) * len_w_excla(str));
  str[i - 1] = '\0';
  while (str[i] != '\0')
    {
      res[j] = str[i];
      i = i + 1;
      j = j + 1;
    }
  if (j == 0)
    {
      printf("%s: Command not found.\n", str);
      return (NULL);
    }
  res[j] = '\0';
  return (res);
}
