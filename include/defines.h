#ifndef DEFINES_H
# define DEFINES_H

typedef enum e_token_type t_token_type;
typedef t_token_type t_redir_type;
typedef enum e_bool t_bool;
typedef enum e_signal_level t_signal_level;
typedef enum e_qutoe_mask t_quote_mask;

enum e_qutoe_mask {
  S_QUOTE = 1 << 0,
  D_QUOTE = 1 << 1
};

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

enum e_signal_level {
  DEFAULT_TERM,
  HEREDOC_CHILD_TERM,
  EXECUTE_PARENT_TERM,
  EXECUTE_CHILD_TERM,
  MAX_SIGNAL_LEVEL
};

#endif
