#include <unistd.h>
#include <stdlib.h>

#include "defines.h"
#include "util.h"

extern char** environ;

static void check_valid_start() {
  if (!(isatty(STDIN_FILENO) && isatty(STDERR_FILENO)))
      exit_shell("Tiny shell can't run in non-interactive mode", EXIT_FAILURE);
}

int main(int argc, char** argv) {
  check_valid_start();
  init_term();
  exit(run_loop());
}
