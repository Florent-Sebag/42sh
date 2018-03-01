/*
** all_flag_echo_part.c for h in /home/sebag/Bureau/PSU_2015_42sh/Sources/Builtins/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Mon May 30 14:24:23 2016 Florent Sebag
** Last update Sun Jun 05 18:51:22 2016 Victor
*/

#include "my.h"

void	t_flag()
{
  fprintf(stdout, "\t");
}

void	v_flag()
{
  fprintf(stdout, "\v");
}

int	check_backslash(int i, char *str)
{
  int	ret;

  if (str[++i] != 92)
    fprintf(stdout, "%c", str[i]);
  else
    {
      if ((ret = find_letter(str, i + 1)) == 0)
	fprintf(stdout, "%c", str[i + 1]);
      if (ret == 1)
	i = i + 1;
      if (ret == -1)
	return (-1);
      if (ret == -2)
	i = i + 2;
    }
  return (i);
}

void	print_letter(char c)
{
  if (c == '\a')
    fprintf(stdout, "a");
  if (c == '\b')
    fprintf(stdout, "b");
  if (c == '\t')
    fprintf(stdout, "t");
  if (c == '\n')
    fprintf(stdout, "n");
  if (c == '\v')
    fprintf(stdout, "v");
  if (c == '\f')
    fprintf(stdout, "f");
  if (c == '\r')
    fprintf(stdout, "r");
}
