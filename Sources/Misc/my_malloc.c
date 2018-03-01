/*
** my_malloc.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources/Misc
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Wed Apr 27 17:44:47 2016 Victor
** Last update Sun Jun 05 18:50:58 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

/*
** Check automatique du retour de malloc.
** Exit(-1) en cas de fail.
*/
void		*my_malloc(size_t size)
{
  void		*elem;

  if ((elem = malloc(size)) == NULL)
    exit(EXIT_ON_FAILURE);
  return (elem);
}
