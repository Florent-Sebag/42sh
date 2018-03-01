/*
** print_env.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources/Builtins
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Mon May 02 18:51:47 2016 Victor
** Last update Sun Jun 05 18:51:17 2016 Victor
*/

#include <stdio.h>
#include "my.h"

void		print_env(char **env)
{
  int		i;

  i = -1;
  while (env[++i])
    {
      printf("%s\n", env[i]);
    }
}
