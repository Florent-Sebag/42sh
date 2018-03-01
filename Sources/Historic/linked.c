/*
** linked.c for h in /home/sebag/Bureau/dante/recup/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Fri May 20 14:02:19 2016 Florent Sebag
** Last update Sun Jun 05 18:52:21 2016 Victor
*/

#include "my.h"

t_index		*init_list_str()
{
  t_index	*list;

  if ((list = malloc(sizeof(t_index))) == NULL)
    exit(EXIT_FAILURE);
  list->first = NULL;
  list->last = NULL;
  list->size = 0;
  return (list);
}

int		create_list_str(t_index *list, char *data)
{
  char		*hour_crea;
  t_histo	*elem;

  if ((elem = malloc(sizeof(t_histo))) == NULL)
    exit(EXIT_FAILURE);
  hour_crea = get_time();
  elem->hour = hour_crea;
  elem->str = data;
  elem->indic = 1;
  elem->prev = elem;
  elem->next = elem;
  list->first = elem;
  list->last = elem;
  list->size = 1;
  return (0);
}

int		add_case_end(t_index *list, char *data)
{
  char		*hour_crea;
  t_histo	*new_elem;

  if ((new_elem = malloc(sizeof(t_histo))) == NULL)
    exit(EXIT_FAILURE);
  hour_crea = get_time();
  new_elem->hour = hour_crea;
  new_elem->str = data;
  new_elem->indic = list->last->indic + 1;
  new_elem->next = list->first;
  new_elem->prev = list->last;
  list->first->prev = new_elem;
  list->last->next = new_elem;
  list->last = new_elem;
  list->size = list->size + 1;
  return (0);
}
