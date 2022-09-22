#include <termios.h>
#include <stdio.h>
#include <stdlib.h>

#include "history.h"
#include "readline.h"
#include "libft.h"

#include "defines.h"
#include "t_token.h"

void     exit_shell(const char* str, int stat);
t_bool   is_whitespace(char c, int quote_mask);
t_token* tokenize(const char* line);

int exit_status;

static t_bool is_valid_line(const char* line) {
  size_t i;

  i = 0;
  while (line[i] && is_whitespace(line[i], 0))
    i++;
  return (line[i] != 0);
}

static void process_line(const char* line, struct termios* term_stat) {
  t_token*  tokenized;

  tokenized = tokenize(line);
  for (t_token* cp = tokenized; cp; cp = cp->next) {
    printf("Data: %s\n", cp->data);
    int i;
    t_token_type types[] = {
      WORD,
      IN,
      HEREDOC,
      OUT,
      APPEND,
      PIPE
    };
    static const char* msg[] = {
      "word",
      "in",
      "heredoc",
      "out",
      "append",
      "pipe"
    };
    for (i = 0; ; i++) {
      if (types[i] == cp->type)
        break ;
    }
    printf("TYPE: %s\n", msg[i]);
    printf("=========\n");
  }
  (void)term_stat;
}

void  run_loop(struct termios* term_stat) {
  char* line;

  while (TRUE) {
    line = readline("> ");
    if (!line)
      exit_shell("\001\033[1A\033[2C\002exit", exit_status);
    if (line[0])
      add_history(line);
    if (is_valid_line(line))
      process_line(line, term_stat);
    free(line);
  }
}
