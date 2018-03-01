/*
** isnum.c for CPE_2015_corewar in /home/victor/Rendu/CPE/COREWAR/CPE_2015_corewar/corewar/lib/my
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Mon Mar 21 17:15:51 2016 Victor
** Last update Sun Jun 05 18:52:01 2016 Victor
*/

#include "my_lib.h"

int		size_tab1(char **tab)
{
  int		i = -1;
  while (tab[++i]);
  return (i);
}

int		my_isnum(char *str)
{
  int		i;

  i = 0;
  if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
    i = 0;
  while (str[++i])
    {
      if (str[i] == '-')
	{
	  my_printf("exit: Badly formed number.\n");
	  return (EXIT_ON_FAILURE);
	}
      if (str[i] < 48 || str[i] > 57)
	{
	  my_printf("exit: Expression Syntax.\n");
	  return (EXIT_ON_FAILURE);
	}
    }
  return (0);
}
