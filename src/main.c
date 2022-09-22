#include <unistd.h>
#include <stdlib.h>
#include <termios.h>

#include "defines.h"
#include "util.h"

extern char** environ;
int exit_status;

void  init_term(struct termios* term_stat);

static void check_valid_start() {
  if (!(isatty(STDIN_FILENO) && isatty(STDERR_FILENO)))
      exit_shell("Tiny shell can't run in non-interactive mode", EXIT_FAILURE);
}

int main() {
  struct termios  term_stat;

  check_valid_start();
  init_term(&term_stat);
  readline("test> ");
//  exit(run_loop());
}
