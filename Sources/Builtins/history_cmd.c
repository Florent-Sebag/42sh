/*
** history_cmd.c for h in /home/sebag/Bureau/PSU_2015_42sh/Sources/Builtins/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Sat Jun  4 15:57:59 2016 Florent Sebag
** Last update Sun Jun 05 18:51:19 2016 Victor
*/

#include "my.h"

int	history_cmd(t_data *dt, char **cmd)
{
  int	i;
  t_histo	*elem;

  i = 1;
  (void)cmd;
  elem = dt->list_histo->first;
  while (i <= dt->list_histo->size)
    {
      printf("  %d", elem->indic);
      printf("   %s", elem->hour);
      printf("  %s\n", elem->str);
      i = i + 1;
      elem = elem->next;
    }
  return (0);
}
