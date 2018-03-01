/*
1;2802;0c** globbing.c for  in /home/dheilly/rendu/Sauvegarde/C-Prog-Elem/PSU_2015_42sh/Sources/Globbing
**
** Made by Dheilly Joss
** Login   <dheilly@epitech.net>
**
** Started on  Fri Jun  3 18:01:37 2016 Dheilly Joss
** Last update Sun Jun  5 18:41:15 2016 Victor
*/

#include <glob.h>
#include "my.h"

char		**copy_globbing_extend(glob_t globbuf, char **news, int *count)
{
  int		j;

  j = 0;
  while (globbuf.gl_pathv[j])
    {
      news[*count] = strdup(globbuf.gl_pathv[j]);
      (*count)++;
      j++;
    }
  return (news);
}

int 		looking_for_glob(char **my_tab)
{
  int		i;
  int		j;

  i = 0;
  while (my_tab[i])
    {
      j = 0;
      while (my_tab[i][j])
	{
	  if (my_tab[i][j] == '*' ||
	      my_tab[i][j] == '?' || my_tab[i][j] == '{')
	      return (i);
	  j++;
	}
      i++;
    }
  return (0);
}

char		**copy_globbing(char **my_tab, glob_t globbuf)
{
  char		**news;
  int		i;
  int		k;
  int		count;

  count = 0;
  i = 0;
  news = my_malloc(sizeof(char *) * (nb_line(my_tab) + globbuf.gl_pathc + 1));
  while (i != (k = looking_for_glob(my_tab)))
    {
      news[count] = strdup(my_tab[i]);
      i++;
      count++;
    }
  news = copy_globbing_extend(globbuf, news, &count);
  i++;
  while (my_tab[i])
    {
      news[count] = strdup(my_tab[i]);
      i++;
      count++;
    }
  news[count] = NULL;
  globfree(&globbuf);
  return (news);
}

char		**glob_extend(char *str, glob_t globbuf, char **my_tab)
{
  int		cmd;

  if ((cmd = glob(str, 0, NULL, &globbuf) == GLOB_NOMATCH))
    return (my_tab);
  else if (cmd == GLOB_ABORTED)
    printf("Read error.\n");
  else if (cmd == GLOB_NOSPACE)
    printf("Running out of memory.\n");
  else
    my_tab = copy_globbing(my_tab, globbuf);
  return (my_tab);
}

char		**globbing(char **my_tab)
{
  glob_t	globbuf;
  int		i;
  char		**tmp;

  i = 0;
  tmp = glob_extend(my_tab[0], globbuf, my_tab);
  while (my_tab[i] != NULL)
    {
      tmp = glob_extend(my_tab[i], globbuf, tmp);
      i++;
    }
  return (tmp);
}
