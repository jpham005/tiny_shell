#ifndef T_TOKEN_H
# define T_TOKEN_H

# include "defines.h"

typedef struct s_token t_token;
typedef struct s_redir t_redir;

struct s_token {
  char* data;
  t_redir* redir;
  t_token_type type;
  t_token* next;
};

#endif