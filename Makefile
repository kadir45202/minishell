NAME 	= minishell
LIB 	= ./libft/libft.a
FLAGS 	= -Wall -Wextra -Werror
SRCS	= main.c join.c
OBJSRCS = $(SRCS: .c=.o)
CC		= gcc -lreadline

all:	$(LIB) $(NAME)

$(LIB):
				make -C ./libft

$(NAME) : $(OBJSRCS)
				$(CC) $(OBJSRCS) -o $(NAME) $(LIB)

clean:
			rm -rf $(NAME)

fclean:
			make fclean -C ./libft
			$(CLEAN)

re:
			make clean
			make

.PHONY : re fclean clean all