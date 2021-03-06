/*
** elem.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources/Listes
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Tue May 31 15:36:26 2016 Victor
** Last update Sun Jun 05 18:51:05 2016 Victor
*/

#include "list.h"

t_elem		*elem_create(void *data)
{
  t_elem	*new_elem;

  new_elem = malloc(sizeof(t_elem));
  if (new_elem == NULL)
    elem_error(new_elem, "malloc", __FILE__, __LINE__);
  new_elem->_next = NULL;
  new_elem->_prev = NULL;
  new_elem->_data = data;
  return (new_elem);
}

void	elem_destroy(t_elem *this)
{
  if (this)
    {
      this->_next = NULL;
      this->_prev = NULL;
      this->_data = NULL;
      free(this);
    }
  else
    elem_warning(this, "elem_destroy", __FILE__, __LINE__);
}

void	elem_warning(__attribute__((unused))t_elem *this,
		     const char *func,
		     const char *file,
		     int line)
{
  fprintf(stderr, "Warning: file: %s, line: %d, func: %s\n",
	  file,
	  line,
	  func);
}

void	elem_error(t_elem *this,
		   const char *func,
		   const char *file,
		   int line)
{
    fprintf(stderr, "Error: file: %s, line: %d, func: %s\n",
	    file,
	    line,
	    func);
    elem_destroy(this);
    exit(EXIT_FAILURE);
}
