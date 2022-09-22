#include "libft.h"

#include "t_token.h"

t_token* init_token(char* data, t_token_type type);
void     append_token(t_token** head, t_token* append);
t_bool   is_whitespace(char c, int quote_mask);
t_bool   is_meta_char(char c, int quote_mask);
void     check_quote(int* quote_mask, char c);

static t_token_type get_token_type(char c, t_bool is_double) {
  static const t_token_type type_map[] = {
    WORD,
    IN,
    HEREDOC,
    OUT,
    APPEND,
    PIPE
  };
  static const char* const meta_char = "<>|";
  size_t  i;

  i = 0;
  while (meta_char[i] != c)
    i++;
  return (type_map[i + is_double]);
}

static void skip_whitespace(const char* line, size_t* i, size_t* j, int quote_mask) {
  if (!is_whitespace(line[*i], quote_mask))
    return ;
  while (is_whitespace(line[*i], quote_mask))
    (*i)++;
  *j = *i;
}

static t_token* tokenize_meta(const char* line, size_t* i) {
  t_token* ret;
  t_bool   is_double;

  is_double = line[*i] == line[*i + 1];
  ret = init_token(NULL, get_token_type(line[*i], is_double));
  *i += is_double;
  return (ret);
}

static t_token* tokenize_word(const char* line, size_t i, size_t* j) {
  t_token*  ret;

  ret = init_token(ft_substr(line, *j, i - *j), WORD);
  *j = i + 1;
  return (ret);
}

t_token*  tokenize(const char* line) {
  t_token*  head;
  int       quote_mask;
  size_t    i;
  size_t    j;

  head = NULL;
  quote_mask = 0;
  i = 0;
  j = 0;
  while (TRUE) {
    skip_whitespace(line, &i, &j, quote_mask);
    check_quote(&quote_mask, line[i]);
    if (is_meta_char(line[i], quote_mask))
      append_token(&head, tokenize_meta(line, &i));
    else if (is_whitespace(line[i], quote_mask) || (!line[i] && i != j))
      append_token(&head, tokenize_word(line, i, &j));
    if (!line[i])
      break ;
    i++;
  }
  return (head);
}
