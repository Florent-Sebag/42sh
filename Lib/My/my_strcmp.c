/*
** my_strcmp.c for my_strcmp in /home/marito_v/rendu/Piscine_C_J06/ex_06
**
** Made by Victor Mariton
** Login   <marito_v@epitech.net>
**
** Started on  Mon Oct  5 18:23:00 2015 Victor Mariton
** Last update Sun Jun 05 18:51:37 2016 Victor
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    i = i + 1;
  if (s1[i] == s2[i] && s1[i] != '\0' && s2[i] == '\0')
    return (0);
  i = s1[i] - s2[i];
  return (i);
}
