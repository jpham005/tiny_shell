#include <stdio.h>
#include <sys/signal.h>

#include "libft.h"
#include "readline.h"

#include "exit_status.h"

void  error_exit(const char* str);

static const char* const signal_error_message = "setting signal fail";

void default_term_signal_handler(int sig) {
  if (sig == SIGINT) {
    ft_putstr_fd("\n", STDERR_FILENO),
      rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
    exit_status = 1;
  }
}

void set_default_term_sig() {
  if (
    (signal(SIGINT, default_term_signal_handler) == SIG_ERR)
    || (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
  )
    error_exit(signal_error_message);
}

void set_heredoc_child_term_sig() {
  if (signal(SIGINT, SIG_DFL) == SIG_ERR)
    error_exit(signal_error_message);
}

void set_execute_parent_term_sig() {
  if (signal(SIGINT, SIG_IGN) == SIG_ERR)
    error_exit(signal_error_message);
}

void set_execute_child_term_sig() {
  if (
    (signal(SIGINT, SIG_DFL) == SIG_ERR)
    || (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
  )
    error_exit(signal_error_message);
}
