.PHONY:	all
all:
	gcc *.c -o tiny_shell -L $(shell brew --prefix readline)/lib -lreadline -lhistory -lncurses
