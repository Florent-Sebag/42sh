/*
** excla.c for h in /home/sebag/Bureau/PSU_2015_42sh/Sources/Historic/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Wed Jun  1 23:11:21 2016 Florent Sebag
** Last update Sun Jun 05 18:52:15 2016 Victor
*/

#include "my.h"

char		*double_excla(t_index *list)
{
  if (list->size == 0)
    {
      fprintf(stderr, "0: Event not found.\n");
      return (NULL);
    }
  return (list->last->str);
}

char		*my_strcpy_w_(char *tab)
{
  char		*res;
  int		i;

  i = 1;
  if ((res = malloc(sizeof(char) * my_strlen(tab))) == NULL)
    exit(EXIT_FAILURE);
  while (tab[i] != '\0')
    {
      res[i - 1] = tab[i];
      i = i + 1;
    }
  res[i - 1] = '\0';
  return (res);
}

char		*neg_excla(t_index *list, int nb)
{
  int		i;
  t_histo	*elem;

  elem = list->last;
  i = 1;
  nb = nb * (-1);
  if (nb > list->size)
    {
      fprintf(stderr, "%d: Event not found.\n", (nb * -1) + 1);
      return (NULL);
    }
  while (i < nb)
    {
      elem = elem->prev;
      i = i + 1;
    }
  return (elem->str);
}

char		*find_elem(t_index *list, int size, int nb)
{
  t_histo	*elem;

  if (size < nb)
    elem = list->last;
  else
    elem = list->first;
  while (elem->indic != nb)
    {
      if (size < nb)
	elem = elem->prev;
      else
	elem = elem->next;
    }
  return (elem->str);
}

char		*excla(char *str, t_index *list, int size)
{
  int		nb;
  char		*ret;

  if (check_nb_or_str(str) == 0)
    {
      ret = find_str_in_histo(str, list);
      if (ret == NULL)
	fprintf(stderr, "%s: Event not found.\n", str);
      return (ret);
    }
  if ((nb = atoi(str)) < 0)
    return (neg_excla(list, nb));
  if (nb > list->size || nb == 0)
    {
      fprintf(stderr, "%d: Event not found.\n", nb);
      return (NULL);
    }
  return (find_elem(list, size, nb));
}
