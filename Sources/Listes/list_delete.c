/*
** list_delete.c for list in /home/victor/Rendu/Test/Liste/list
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Mon May 23 16:59:52 2016 Victor
** Last update Sun Jun 05 18:51:05 2016 Victor
*/

#include "list.h"

void		list_destroy(t_list *this)
{
  t_elem	*tmp;
  t_elem	*to_del;

  if (this && this->_sz > 0)
    {
      tmp = this->_head;
      while (tmp != this->_back)
	{
	  to_del = tmp;
	  tmp = tmp->_next;
	  elem_destroy(to_del);
	}
      elem_destroy(tmp);
      free(this);
    }
  else
    list_warning(this, "list_destroy", __FILE__, __LINE__);
}

void		list_erase(t_list *this, int pos)
{
  t_elem	*tmp;

  if (this && this->_head)
    {
      tmp = this->_head;
      pos += 1;
      while (--pos && tmp != this->_back)
	tmp = tmp->_next;
      if (pos == 0)
	{
	  if (tmp == this->_back)
	    this->pop_back(this);
	  else if (tmp == this->_head)
	    this->pop_front(this);
	  else
	    {
	      tmp->_prev->_next = tmp->_next;
	      tmp->_next->_prev = tmp->_prev;
	      elem_destroy(tmp);
	      this->_sz--;
	    }
	}
      else
	list_warning(this, "erase", __FILE__, __LINE__);
    }
}

void		list_pop_back(t_list *this)
{
  t_elem	*to_del;

  if (this && this->_sz > 1)
    {
      to_del = this->_back;
      this->_back->_prev->_next = this->_head;
      this->_head->_prev = this->_back->_prev;
      this->_back = this->_back->_prev;
      elem_destroy(to_del);
      this->_sz--;
    }
  else if (this && this->_sz == 1)
    {
      to_del = this->_back;
      elem_destroy(to_del);
      list_init(this);
    }
  else
    list_warning(this, "pop_back", __FILE__, __LINE__);
}

void		list_pop_front(t_list *this)
{
  t_elem	*to_del;

  if (this && this->_sz > 1)
    {
      to_del = this->_head;
      this->_back->_next = this->_head->_next;
      this->_head->_next->_prev = this->_back;
      this->_head = this->_head->_next;
      elem_destroy(to_del);
      this->_sz--;
    }
  else if (this && this->_sz == 1)
    {
      to_del = this->_head;
      elem_destroy(to_del);
      list_init(this);
    }
  else
    list_warning(this, "pop_front", __FILE__, __LINE__);
}
