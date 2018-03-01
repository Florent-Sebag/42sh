/*
** load_file_rc.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources/Alias
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Tue May 31 09:36:14 2016 Victor
** Last update Sun Jun 05 18:51:31 2016 Victor
*/

#include <stdlib.h>
#include "my.h"

t_alias		*fill_alias(char **tab)
{
  t_alias	*elem;

  elem = my_malloc(sizeof(t_alias));
  elem->old = strdup(tab[0]);
  elem->new = strdup(tab[1]);
  if (elem->new[0] == '\'' || elem->new[0] == '\"')
    elem->new += 1;
  else
    return (NULL);
  if (elem->new[LEN(elem->new) - 1] == '\'' ||
      elem->new[LEN(elem->new) - 1] == '\"' )
    elem->new[LEN(elem->new) - 1] = '\0';
  else
    return (NULL);
  return (elem);
}

static void	create_tab_alias(t_data *dt)
{
  t_elem	*tmp;
  t_alias	*elem;
  char		**tab;

  tmp = dt->list_alias->_head;
  while (tmp != dt->list_alias->_back)
    {
      tab = my_wordtab((char *)tmp->_data, '=', true);
      if ((elem = fill_alias(tab)))
	dt->alias->push_back(dt->alias, elem);
      else
	fprintf(stderr, "Syntaxe error on alias : %s\n", tab[1]);
      tmp = tmp->_next;
    }
  tab = my_wordtab((char *)tmp->_data, '=', true);
  if ((elem = fill_alias(tab)))
    dt->alias->push_back(dt->alias, elem);
  else
    fprintf(stderr, "Syntaxe error on alias : %s\n", tab[1]);
  dt->alias->push_back(dt->alias, elem);
}

static void	norme_requires(t_data *dt, char **to_cast)
{
  dt->list_alias->for_each(dt->list_alias, &delete_type_alias);
  create_tab_alias(dt);
  UNUSED(to_cast);
}

static void	reanalyze(t_data *dt, char *str, int line)
{
  int		ret;

  if ((ret = get_type(str)) == ALIAS)
    dt->list_alias->push_back(dt->list_alias, str);
  else if (ret == EXIT_ON_FAILURE)
    fprintf(stderr, "Error detected : %s at line %d\n", str, line);
}

int		load_our_file(t_data *dt, char **to_cast)
{
  int		fd;
  int		count;
  char		*str;

  count = 0;
  if ((fd = open(".marmiteshrc", O_RDONLY)) == EXIT_ON_FAILURE)
    {
      fprintf(stderr, "Error for load marmiteshrc\n");
      return (EXIT_FAILURE);
    }
  while ((str = get_next_line(fd)))
    {
      str = epur_str(str);
      if (str[0] != '#' && str[0])
	reanalyze(dt, str, count);
      count += 1;
    }
  norme_requires(dt, to_cast);
  call_gnl_to_end(fd);
  close(fd);
  return (EXIT_SUCCESS);
}
