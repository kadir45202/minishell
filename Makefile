NAME	= minishell

SRCS	= main.c join.c

CC		= gcc -lreadline

all:	$(NAME)

$(NAME):	$(SRCS)
				$(CC) $(SRCS) -o $(NAME)


