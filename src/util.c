#include <stdlib.h>

#include "libft.h"

#include "defines.h"

void  exit_shell(const char* str, int stat) {
  ft_putstr_fd(str, STDERR_FILENO);
  ft_putstr_fd("\n", STDERR_FILENO);
  exit(stat);
}

void  error_exit(const char* str) {
  exit_shell(str, EXIT_FAILURE);
}

t_bool  is_whitespace(char c, int quote_mask) {
  return (!quote_mask && (c == ' ' || c == '\n' || c == '\t'));
}
