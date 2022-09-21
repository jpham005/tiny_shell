#include <stdlib.h>

#include "libft.h"

void  exit_shell(const char* str, int stat)
{
  ft_putstr_fd(str, STDERR_FILENO);
  ft_putstr_fd("\n", STDERR_FILENO);
  exit(stat);
}
