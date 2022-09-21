SRCS	:=	*.c
OBJS	:=	$(SRCS:.c=.o)

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror

.PHONY:	all
all	: $(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY:	clean
clean	:
	rm -f $(OBJS)

.PHONY:	fclean
fclean	:	clean
	rm -f $(NAME)

.PHONY:	re
re	:
	make fclean
	make all
