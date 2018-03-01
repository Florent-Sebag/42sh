/*
** my_strcpy.c for PSU_2015_my_exec in /home/marito_v/rendu/Première année/Sys_Unix/PSU_2015_my_exec/lib/my
**
** Made by Victor Mariton
** Login   <marito_v@epitech.net>
**
** Started on  Tue Jan 05 10:46:43 2016 Victor Mariton
** Last update Sun Jun 05 18:51:36 2016 Victor
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;
  int	j;

  j = -1;
  i = -1;
  while (dest[++j]);
  while (src[++i])
    {
      dest[j] = src[i];
      j += 1;
    }
  dest[j] = '\0';
  return (dest);
}
