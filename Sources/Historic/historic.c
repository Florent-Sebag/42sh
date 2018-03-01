/*
** historic.c for h in /home/sebag/Bureau/PSU_2015_42sh/Sources/Historic/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Fri May 27 15:34:16 2016 Florent Sebag
** Last update Sun Jun 05 18:52:18 2016 Victor
*/

#include "get_next_line.h"
#include "my.h"

int		my_strcmp(char *str, char *res)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != res[i])
	return (0);
      i = i + 1;
    }
  if (res[i] != '\0')
    return (0);
  return (1);
}

void		add_to_historic(t_index *list, char *str)
{
  if (list->size == 0)
    create_list_str(list, str);
  else
    add_case_end(list, str);
}

void	print_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (tab[i + 1] != NULL)
	printf("%s ", tab[i]);
      else
	printf("%s\n", tab[i]);
      i = i + 1;
    }
}

char	*my_historic(char *str, t_index *list, int indic)
{
  int	i;
  char	*ret;
  char	**tab;

  i = 0;
  if (check_excla(str) == 0)
    return (str);
  tab = my_str_to_wordtab(str, ' ');
  while (tab[i] != NULL)
    {
      if (indic != -1)
	indic = check_if_excla(indic, tab, list, i);
      else
	check_if_excla(indic, tab, list, i);
      i = i + 1;
    }
  if (indic == 1)
    print_tab(tab);
  ret = tab_to_str(tab);
  if (ret == NULL)
    return (NULL);
  add_to_historic(list, ret);
  if (indic == -1)
    return (NULL);
  return (ret);
}
