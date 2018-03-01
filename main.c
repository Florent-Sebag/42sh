/*
** main.c for main in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh
**
** Made by Victor
** Login   <victor@victorPc>
**
** Started on  Fri Apr 15 12:24:38 2016 Victor
** Last update Sun Jun 05 18:52:31 2016 Victor
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

int g_ret = 0;

/*
** Affichage de l'usage du 42sh
*/
static void	put_usage()
{
  fprintf(stderr, USAGE);
  exit(EXIT_ON_FAILURE);
}

int		main(int ac, char **av, char **env)
{
  char		**tab;

  if (ac != 1 && av[1])
    put_usage();
  env[0] == NULL ? (tab = create_my_env()) : (tab = copy_env(env));
  main_loop(tab);
  return (g_ret);
}
