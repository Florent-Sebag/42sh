/*
** nb_lines.c for PSU_2015_minishell2 in /home/victor/Rendu/Sys_Unix/PSU_2015_minishell2/lib/my
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Sat Apr 09 16:59:28 2016 Victor
** Last update Sun Jun 05 18:51:32 2016 Victor
*/

#include "my_lib.h"

int	nb_line(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i]);
  return (i);
}
