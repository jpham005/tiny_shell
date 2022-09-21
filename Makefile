NAME	:=	tinyshell

SRCS	:=	main.c util.c
OBJS	:=	$(SRCS:.c=.o)

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror

.PHONY:	all
all	: $(NAME)

$(NAME)	:	$(OBJS) libft
	$(CC) $(CFLAGS) $(OBJS) -o $@ -L$(shell brew --prefix readline)/lib -lreadline -lhistory -lncurses -Llibft -lft

.PHONY:	libft
libft:
	make -C libft all

%.o	:	%.c
	$(CC) -c $< -o $@ -Ilibft -I$(shell brew --prefix readline)/include

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
