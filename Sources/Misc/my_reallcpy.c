/*
** my_reallcpy.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources/Misc
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Wed Apr 27 17:40:22 2016 Victor
** Last update Sun Jun 05 18:50:58 2016 Victor
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

/*
** Création d'une nouvelle chaine de caractère contenant
** les deux passées en paramètres.
*/
char		*my_reallcpy(char *s1, char *s2)
{
  int		i;
  int		j;
  char		*new;

  i = j = -1;
  if (!s1)
    return (s2);
  new = my_malloc(sizeof(char) * (LEN(s1) + LEN(s2) + 1));
  while (s1[++i])
    new[i] = s1[i];
  while (s2[++j])
    {
      new[i] = s2[j];
      i += 1;
    }
  new[i] = '\0';
  return (new);
}
