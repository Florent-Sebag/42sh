/*
** my_strcat.c for my_strcat in /home/marito_v/rendu/Piscine_C_J07/ex_02
**
** Made by Victor Mariton
** Login   <marito_v@epitech.net>
**
** Started on  Tue Oct  6 13:35:50 2015 Victor Mariton
** Last update Sun Jun 05 18:51:37 2016 Victor
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	compt;

  compt = my_strlen(dest);
  i = 0;
  while (src[i] != '\0')
    {
      dest[compt] = src[i];
      i += 1;
      compt += 1;
    }
  dest[compt] = '\0';
  return (dest);
}
