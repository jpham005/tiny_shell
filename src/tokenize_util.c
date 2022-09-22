#include "defines.h"

t_bool is_meta_char(char c, int quote_mask) {
  return ((quote_mask == 0) && (c == '|' || c == '<' || c == '>'));
}

void check_quote(int* quote_mask, char c) {
  if (c == '\'' && !(*quote_mask & D_QUOTE))
    *quote_mask ^= S_QUOTE;
  if (c == '\"' && !(*quote_mask & S_QUOTE))
    *quote_mask ^= D_QUOTE;
}
