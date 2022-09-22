#include <unistd.h>
#include <stdlib.h>
#include <termios.h>

extern char** environ;

void  exit_shell(const char* str, int stat);
void  init_term(struct termios* term_stat);
void  run_loop(struct termios* term_stat);

static void check_valid_start() {
  if (!(isatty(STDIN_FILENO) && isatty(STDERR_FILENO)))
      exit_shell("Tiny shell can't run in non-interactive mode", EXIT_FAILURE);
}

int main() {
  struct termios  term_stat;

  check_valid_start();
  init_term(&term_stat);
  run_loop(&term_stat);
}
