NAME	:=	tinyshell

SRCS	:=	main.c util.c terminal.c signal_setter.c
SRCS	:=	$(addprefix src/, $(SRCS))
OBJS	:=	$(SRCS:.c=.o)

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror -g -D READLINE_LIBRARY

RM		:=	rm -f

INCLUDE_DIR		:=	./include
READLINE_DIR	:=	readline
READLINE		:=	$(READLINE_DIR)/libreadline.a
LIBFT_DIR		:=	libft

.PHONY:	all
all	: $(NAME)

$(NAME)	:	$(OBJS) libft $(READLINE)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -L$(READLINE_DIR) -lreadline -lhistory -lncurses -Llibft -lft

.PHONY:	libft
libft:
	make -C $(LIBFT_DIR) all

$(READLINE):
	cd readline; ./configure
	make -C $(READLINE_DIR) all

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBFT_DIR) -I$(READLINE_DIR) -I$(INCLUDE_DIR)

.PHONY:	clean
clean	:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

.PHONY:	fclean
fclean	:	clean
	$(RM) $(NAME)
	$(MAKE) -j8 -C $(LIBFT_DIR) fclean
	$(MAKE) -j8 -C $(READLINE_DIR) clean


.PHONY:	re
re	:
	$(MAKE) -j8 fclean
	$(MAKE) -j8 all
