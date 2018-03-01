/*
** my_putchar.c for  in /home/victor/rendu/Première année/Sys_Unix/PSU_2015_my_printf/lib/my
**
** Made by Victor
** Login   <marito_v@epitech.net>
**
** Started on  Sat Nov  7 17:49:31 2015 Victor
** Last update Sun Jun 05 18:51:52 2016 Victor
*/

#include <unistd.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}
