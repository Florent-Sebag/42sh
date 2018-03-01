/*
** list.h for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Include
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Wed Jun 01 15:39:56 2016 Victor
** Last update Sun Jun 05 18:52:29 2016 Victor
*/


#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* ---------------------------------------------------------------------- *\
**                               STRUCTURES                               **
\* ---------------------------------------------------------------------- */

	/* ---------- | STRUCTURE ELEMENT | ----------*/

typedef struct	s_elem
{
  void		*_data;
  struct s_elem	*_next;
  struct s_elem	*_prev;
}		t_elem;

	/* ---------- | STRUCTURE LISTE | ----------*/

typedef struct	s_list
{
  t_elem	*_head;
  t_elem	*_back;
  int		_sz;
  int		(*empty)(struct s_list *);
  int		(*size)(struct s_list *);
  void		*(*back)(struct s_list *);
  void		*(*front)(struct s_list *);
  void		(*pop_back)(struct s_list *);
  void		(*pop_front)(struct s_list *);
  void		(*erase)(struct s_list *, int);
  void		(*push_back)(struct s_list *, void *);
  void		(*push_front)(struct s_list *, void *);
  void		(*for_each)(struct s_list *, void *(*fun)(void *));
}		t_list;

/* ---------------------------------------------------------------------- *\
**                               PROTOTYPES                               **
\* ---------------------------------------------------------------------- */

	/* ---------- | PROTOTYPES LISTES | ----------*/

t_list	*list_create();

void	list_init(t_list *);
void	*list_back(t_list *);
void	*list_front(t_list *);
void	list_destroy(t_list *);
void	list_pop_back(t_list *);
void	list_pop_front(t_list *);
void	list_erase(t_list *, int);
void	list_push_back(t_list *, void *);
void	list_push_front(t_list *, void *);
void	list_for_each(t_list *, void *(*fun)(void *));
void    list_error(t_list *, const char *, const char *, int);
void    list_warning(t_list *, const char *, const char *, int);

int	list_empty(t_list *);
int	list_size(t_list *);

	/* ---------- | PROTOTYPES ELEMENTS | ----------*/

t_elem	*elem_create(void *data);

void	elem_destroy(t_elem *);
void	elem_error(t_elem *, const char *, const char *, int);
void	elem_warning(t_elem *, const char *, const char *, int);

#endif /* !LIST_H_ */
