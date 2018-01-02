/*
** my_strlen.c for my_strlen in /home/lblanchard/CPool_Day04
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Thu Oct  6 19:01:09 2016 Leandre Blanchard
** Last update Mon Jan  1 12:10:05 2018 Léandre Blanchard
*/

#include <stdlib.h>

size_t		my_kstrlen(const char *str, char k)
{
  size_t	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != k && str[i])
    ++i;
  return (i);
}

size_t		my_knstrlen(const char *str, char k, size_t n)
{
  size_t	i;

  i = 0;
  if (str == NULL || n == 0)
    return (0);
  while (str[i] != k && i < n)
    ++i;
  return (i);
}

size_t		my_strlen(const char *str)
{
  return (my_kstrlen(str, '\0'));
}
