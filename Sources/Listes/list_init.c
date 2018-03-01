/*
** list_init.c for list in /home/victor/Rendu/Test/Liste/list
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Mon May 23 16:57:37 2016 Victor
** Last update Sun Jun 05 18:51:03 2016 Victor
*/

#include "list.h"

void	list_set_methods(t_list *this)
{
  this->pop_back = &list_pop_back;
  this->pop_front = &list_pop_front;
  this->push_back = &list_push_back;
  this->push_front = &list_push_front;
  this->erase = &list_erase;
  this->empty = &list_empty;
  this->size = &list_size;
  this->for_each = &list_for_each;
  this->front = &list_front;
  this->back = &list_back;
}

void	list_init(t_list *this)
{
  this->_sz = 0;
  this->_head = NULL;
  this->_back = NULL;
}

t_list		*list_create()
{
  t_list	*new_list;

  new_list = malloc(sizeof(t_list));
  if (new_list == NULL)
    list_error(new_list, "malloc", __FILE__, __LINE__);
  list_init(new_list);
  list_set_methods(new_list);
  return (new_list);
}
