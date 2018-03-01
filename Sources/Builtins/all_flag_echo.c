/*
** all_flag_echo.c for h in /home/sebag/Bureau/PSU_2015_42sh/Sources/Builtins/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Mon May 30 14:21:20 2016 Florent Sebag
** Last update Sun Jun 05 18:51:22 2016 Victor
*/

#include "my.h"

void	a_flag()
{
  fprintf(stdout, "\a");
}

void	b_flag()
{
  fprintf(stdout, "\b");
}

void	f_flag()
{
  fprintf(stdout, "\f");
}

void	n_flag()
{
  fprintf(stdout, "\n");
}

void	r_flag()
{
  fprintf(stdout, "\r");
}
