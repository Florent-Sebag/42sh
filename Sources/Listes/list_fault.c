/*
** list_fault.c for list in /home/victor/Rendu/Test/Liste/list
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Mon May 23 16:57:04 2016 Victor
** Last update Sun Jun 05 18:51:04 2016 Victor
*/

#include "list.h"

void    list_warning(t_list *this,
		     const char *func,
		     const char *file,
		     int line)
{
  (void)this;
  fprintf(stderr, "Warning: file: %s, line: %d, func: %s\n",
	  file,
	  line,
	  func);
}

void    list_error(t_list *this,
		   const char *func,
		   const char *file,
		   int line)
{
  fprintf(stderr, "Error: file: %s, line: %d, func: %s\n",
	  file,
	  line,
	  func);
  list_destroy(this);
  exit(EXIT_FAILURE);
}
