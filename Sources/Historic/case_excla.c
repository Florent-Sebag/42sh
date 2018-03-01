/*
** case_excla.c for h in /home/sebag/Bureau/PSU_2015_42sh/Sources/Historic/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Thu Jun  2 16:51:48 2016 Florent Sebag
** Last update Sun Jun 05 18:52:07 2016 Victor
*/

#include "my.h"

int	check_nb_or_str(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9') && str[i] != '!' && str[i] != '-')
	return (0);
      i = i + 1;
    }
  return (1);
}

int	test_str_hist(char *src, char *str)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      if (str[i] != src[i])
	return (0);
      i = i + 1;
    }
  return (1);
}

char	*find_str_in_histo(char *str, t_index *list)
{
  t_histo	*elem;

  if (list->size == 0)
    return (NULL);
  elem = list->last;
  while (test_str_hist(str, elem->str) == 0)
    {
      elem = elem->prev;
      if (elem == list->last)
	return (NULL);
    }
  return (elem->str);
}

int	check_excla(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '!')
	return (1);
      i = i + 1;
    }
  return (0);
}

char	*use_excla(t_index *list, char *str)
{
  char	*tmp;

  if (my_strcmp(str, "!!") == 1)
    {
      if ((tmp = double_excla(list)) == NULL)
	return (NULL);
      str = tmp;
    }
  else if ((tmp = excla(str, list, list->size / 2)) != NULL)
    {
      free(str);
      str = tmp;
    }
  else
    return (NULL);
  return (str);
}
