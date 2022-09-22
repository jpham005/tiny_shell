#include <stdlib.h>

#include "libft.h"

#include "t_token.h"

t_token* init_token(char* data, t_token_type type) {
  t_token*  ret;

  ret = ft_malloc(sizeof(t_token), 1);
  ret->data = data;
  ret->type = type;
  return (ret);
}

void append_token(t_token** head, t_token* token) {
  while (*head)
    head = &((*head)->next);
  *head = token;
}

void destroy_token(t_token** head) {
  t_token* temp;

  while (*head) {
    temp = (*head)->next;
    free((*head)->data);
    free(*head);
    *head = temp;
  }
}
