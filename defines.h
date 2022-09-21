#ifndef DEFINES_H
# define DEFINES_H

typedef enum e_token_type t_token_type;
typedef t_token_type t_redir_type;
typedef enum e_bool t_bool;

enum e_token_type {
  WORD = 1 << 0,
  IN = 1 << 1,
  HEREDOC = 1 << 2,
  OUT = 1 << 3,
  APPEND = 1 << 4,
  PIPE = 1 << 5,
  REDIR = IN | HEREDOC | OUT | APPEND
};

enum e_bool {
  FALSE,
  TRUE
};

#endif