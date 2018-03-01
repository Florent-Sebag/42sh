/*
** epur.c for PSU_2015_minishell1 in /home/marito_v/rendu/Première année/Sys_Unix/PSU_2015_minishell1/lib/my
**
** Made by Victor Mariton
** Login   <marito_v@epitech.net>
**
** Started on  Sun Jan 24 17:08:28 2016 Victor Mariton
** Last update Sun Jun 05 18:51:01 2016 Victor
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

char    *epur_str(char *str)
{
  int           i;
  int           j;
  bool          state;
  char          *buff;

  i = -1;
  j = 0;
  buff = my_malloc(sizeof(char) * (LEN(str) + 1));
  while (str[++i] == ' ' || str[i] == '\t');
  while (str[i])
    {
      buff[j] = str[i];
      state = true;
      while (str[i] == ' ' || str[i] == '\t')
        {
          i += 1;
          state = false;
        }
      state == true ? (i += 1) : (0);
      j += 1;
    }
  (j > 0 && (buff[j - 1] == ' ' || buff[j - 1] == '\t')) ? (buff[j - 1] = '\0')
      : (buff[j] = '\0');
  return (buff);
}
