/*
** echo.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_42sh/echo
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
**
** Started on  Wed Apr 27 17:04:36 2016 Florent Sebag
** Last update Sun Jun 05 18:51:20 2016 Victor
*/

#include "my.h"

t_flags	tab_echo[] =
{
  {'a', &a_flag},
  {'b', &b_flag},
  {'f', &f_flag},
  {'n', &n_flag},
  {'r', &r_flag},
  {'t', &t_flag},
  {'v', &v_flag},
  {0, NULL}
};

int	find_letter(char *str, int i)
{
  int	j;
  int	indic;

  indic = 0;
  j = 0;
  if (str[i] == 92)
    {
      indic = -2;
      i = i + 1;
    }
  if (str[i] == 'c')
    return (-1);
  while (tab_echo[j].flag != 0)
    {
      if (str[i] == tab_echo[j].flag)
	{
	  tab_echo[j].func();
	  if (indic != -2)
	    indic = 1;
	  return (indic);
	}
      j = j + 1;
    }
  return (indic);
}

int	my_putstr_w_ba(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == 92)
	{
	  if ((i = check_backslash(i, str)) == -1)
	    return (-1);
	}
      else if (str[i] >= 7 && str[i] <= 13)
	print_letter(str[i]);
      else
	fprintf(stdout, "%c", str[i]);
    }
  return (0);
}

void	print_double_star(char **tab, int i)
{
  int	tmp;

  tmp = i;
  while (tab[i] != NULL)
    {
      if (i != tmp)
	fprintf(stdout, " ");
      if (my_putstr_w_ba(tab[i]) == -1)
	return ;
      i = i + 1;
    }
}

int	echo_cmd(t_data *dt, char **cmd)
{
  //fprintf(stderr, "hum : %s\n", dt->cmd[1]);
  if (dt->cmd[1] == NULL)
    {
      fprintf(stdout, "\n");
      return (EXIT_SUCCESS);
    }
  if (my_strcmp(dt->cmd[1], "-n") == 1)
    print_double_star(dt->cmd, 2);
  else
    {
      print_double_star(dt->cmd, 1);
      fprintf(stdout, "\n");
    }
  (void)cmd;
  return (EXIT_SUCCESS);
}
