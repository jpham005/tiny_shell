#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "readline.h"

#include "defines.h"
#include "util.h"


void set_default_term_sig();
void set_heredoc_child_term_sig();
void set_execute_parent_term_sig();
void set_execute_child_term_sig();

void  set_signal(t_signal_level level) {
  static void (*signal_setter[MAX_SIGNAL_LEVEL])() = {
    set_default_term_sig,
    set_heredoc_child_term_sig,
    set_execute_parent_term_sig,
    set_execute_child_term_sig
  };

  signal_setter[level]();
}

void  set_term_echoctl(struct termios* term_stat, t_bool on) {
  if (on)
    term_stat->c_cflag |= ECHOCTL;
  else
    term_stat->c_cflag &= ~ECHOCTL;
  if (tcsetattr(STDERR_FILENO, TCSANOW, term_stat))
    exit_shell("setting terminal stat fail", EXIT_FAILURE);
}

void  init_term(struct termios* term_stat) {
  if (tcgetattr(STDERR_FILENO, term_stat))
    exit_shell("getting terminal stat fail", EXIT_FAILURE);
  set_term_echoctl(term_stat, FALSE);
  rl_catch_signals = FALSE;
  rl_outstream = stderr;
  set_signal(DEFAULT_TERM);
}
