#ifndef TINY_SHELL_H
# define TINY_SHELL_H

typedef struct s_token  t_token;
typedef struct s_redir  t_redir;
typedef enum e_token_type t_token_type;
typedef enum e_token_type t_redir_type;

enum e_token_type {
  WORD = 1 << 0,
  IN = 1 << 1,
  HEREDOC = 1 << 2,
  OUT = 1 << 3,
  APPEND = 1 << 4,
  PIPE = 1 << 5,
  REDIR = IN | HEREDOC | OUT | APPEND
};

struct s_redir {
  char* target;
  t_redir_type type;
};

struct s_token {
  char* data;
  t_redir redir;
  t_token_type type;
  t_token* next;
};

#endif
