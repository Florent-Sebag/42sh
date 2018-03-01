/*
** get_time.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources/Misc
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Sun Jun 05 18:47:05 2016 Victor
** Last update Sun Jun 05 18:51:00 2016 Victor
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

char		*parse_time(char *time)
{
  int		j;
  int		i;
  int		space;
  char		*new_time;

  i = 0;
  space = 0;
  j = 0;
  if ((new_time = malloc(sizeof(char) * (strlen(time) + 1))) == NULL)
    return (NULL);
  while (time[i] && space != 4)
    {
      if (time[i] == ' ')
	space++;
      i++;
    }
  while (time[i] != ' ' && time[i])
    new_time[j++] = time[i++];
  new_time[j] = 0;
  return (new_time);
}

char		*get_time()
{
  time_t        timer;
  char		*tim;
  char		*new_time;

  timer = time(NULL);
  tim = asctime(localtime(&timer));
  new_time = parse_time(tim);
  return (new_time);
}
