/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:42:13 by jaham             #+#    #+#             */
/*   Updated: 2021/11/13 03:42:13 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_putstr_fd(const char *s, int fd)
{
  ssize_t last_write;
  size_t  target_write;
  ssize_t total;

  total = 0;
  target_write = ft_strlen(s);
  while (1)
  {
    last_write = write(fd, s + total, target_write - total);
    if (last_write < 0)
      exit(EXIT_FAILURE);
    total += last_write;
    if ((size_t) total == target_write)
      return ;
  }
}
