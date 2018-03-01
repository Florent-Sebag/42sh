/*
** my_strncmp.c for my_strncmp in /home/marito_v/rendu/Piscine_C_J06/ex_07
**
** Made by Victor Mariton
** Login   <marito_v@epitech.net>
**
** Started on  Mon Oct  5 18:44:54 2015 Victor Mariton
** Last update Sun Jun 05 18:51:33 2016 Victor
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  n = n - 1;
  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
    i = i + 1;
  if (s1[i] == s2[i] && s1[i] != '\0' && s2[i] == '\0')
    return (0);
  i = s1[i] - s2[i];
  return (i);
}
