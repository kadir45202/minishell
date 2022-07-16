NAME	= minishell

SRCS	= main.c join.c

CC		= gcc -lreadline

all:	$(NAME)

$(NAME):	$(SRCS)
				$(CC) $(SRCS) -o $(NAME)
				make -C ./libft

clean:
			rm -rf $(NAME)

fclean:
			make fclean -C ./libft
			$(CLEAN)