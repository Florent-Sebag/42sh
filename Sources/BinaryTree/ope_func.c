/*
** ope_func.c for PSU_2015_minishell2 in /home/victor/Rendu/Sys_Unix/PSU_2015_minishell2/src
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Thu Mar 31 20:28:25 2016 Victor
** Last update Sun Jun 05 18:51:23 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

static t_op	tab_ope[] =
 {
   {"<", 1, 1},
   {"<<", 2, 2},
   {"|", 1, 3},
   {">", 1, 4},
   {">>", 2, 5},
   {"&&", 2, 6},
   {"||", 2, 7},
   {";", 1, 8},
   {NULL, 0, 0}
 };

int		pos_prio_operator(char *str, int *size)
{
  int		prio;
  int		pos;
  int		i;
  int		j;

  i = 0;
  pos = -1;
  *size = 0;
  prio = 0;
  while (*str != '\0')
    {
      j = -1;
      while (tab_ope[++j].str)
	{
	  (prio < tab_ope[j].prior &&
	   !my_strncmp(str, tab_ope[j].str, tab_ope[j].nb_car)) ?
	  (*size = tab_ope[j].nb_car, prio = tab_ope[j].prior, pos = i) :
	      (0);
	}
      str += 1;
      i += 1;
    }
  return (pos);
}

char		*get_ope(char *str, int size_op, int pos_op)
{
  char		*new;
  char		*tmp;
  int		i;

  i = -1;
  tmp = str + pos_op;
  new = my_malloc(sizeof(char) * (size_op + 1));
  while (++i < size_op)
    new[i] = tmp[i];
  new[i] = '\0';
  return (new);
}
