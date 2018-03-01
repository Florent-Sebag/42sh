/*
** check_if_excla.c for h in /home/sebag/Bureau/PSU_2015_42sh/Sources/Historic/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Fri Jun  3 20:01:21 2016 Florent Sebag
** Last update Sun Jun 05 18:52:08 2016 Victor
*/

#include "my.h"

int	check_if_excla(int indic, char **tab, t_index *list, int i)
{
  char	*tmp;

  if (check_excla(tab[i]) == 1)
    {
      if ((tmp = find_and_rm_excla(tab[i])) != NULL)
	{
	  if ((tmp = use_excla(list, tmp)) == NULL)
	    {
	      indic = -1;
	      rm_to_tab(tab, i);
	      i = i - 1;
	    }
	  else if (my_strcmp(tab[i], "!!") == 0
		   && list->size > 0)
	    tab[i] = compact(tab[i], tmp);
	  else
	    tab[i] = tmp;
	  if (indic != -1)
	    indic = 1;
	}
      else
	indic = -1;
    }
  return (indic);
}
