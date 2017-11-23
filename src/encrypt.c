/*
** EPITECH PROJECT, 2017
** tanks
** File description:
** encrypt
*/

void	encrypt(void *datas, int size)
{
  int	i;
  char	*raw;

  if (!datas || size < 0)
    return;
  i = 0;
  raw = (char *)datas;
  while (i < size)
  {
    raw[i] = -raw[i];
    ++i;
  }
}
