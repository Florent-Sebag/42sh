/*
** list_func.c for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Sources/Listes
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Mon May 23 18:45:59 2016 Victor
** Last update Sun Jun 05 18:51:04 2016 Victor
*/

#include "list.h"

int	list_empty(t_list *this)
{
  if (this)
    {
      if (this->_sz == 0)
	return (1);
    }
  else
    list_warning(this, "empty", __FILE__, __LINE__);
  return (0);
}

int	list_size(t_list *this)
{
  if (this)
    return (this->_sz);
  else
    list_warning(this, "size", __FILE__, __LINE__);
  return (0);
}

void		list_for_each(t_list *this, void *(*fun)(void *data))
{
  t_elem	*tmp;

  if (this && this->_sz != 0)
    {
      tmp = this->_head;
      while (tmp != this->_back)
	{
	  tmp->_data = (*fun)(tmp->_data);
	  tmp = tmp->_next;
	}
      tmp->_data = (*fun)(tmp->_data);
    }
  else
    list_warning(this, "for_each", __FILE__, __LINE__);
}

void	*list_front(t_list *this)
{
  if (this && this->_head)
    return (this->_head->_data);
  else
    list_warning(this, "front", __FILE__, __LINE__);
  return (NULL);
}

void	*list_back(t_list *this)
{
  if (this && this->_back)
    return (this->_back->_data);
  else
    list_warning(this, "back", __FILE__, __LINE__);
  return (NULL);
}
