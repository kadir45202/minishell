NAME= minishell

_SRC= get_cmd.c get_params_control.c tabs_but_spaces.c check_args.c exec.c custom_cmd.c env.c error.c main.c prompt.c signal.c parse_args.c ft_cmdtrim.c expand.c ft_cmdsubsplit.c w_export.c fill_node.c ft_strtrim_all.c get_params.c heredoc.c builtins.c

_OBJ= $(_SRC:.c=.o)
_EXLIB= libft.a
_IDIR= ../libft/bin

SDIR=
ODIR=
EXLIBD= ../libft/
IFLAG= -I

SRC= $(patsubst %,$(SDIR)%,$(_SRC))
OBJ= $(patsubst %,$(ODIR)%,$(_OBJ))
EXLIB= $(patsubst %,$(EXLIBD)%,$(_EXLIB))
INC= $(patsubst %,$(IFLAG)%,$(_IDIR))

CC= gcc

FLAGS= -Wall -Wextra -Werror 



all: $(EXLIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INC) $(OBJ) -L$(HOME)/lib/readline/lib -lreadline -I$(HOME)/lib/readline/include/ -o $(NAME) $(EXLIB) -lreadline

$(ODIR)%.o : $(SDIR)%.c
	$(CC) $(FLAGS) $(INC) -I$(HOME)/lib/readline/include/ -c  $< -o $@

$(EXLIB) :
	make -C ../libft

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
	make fclean -C ../libft
re: fclean all

.PHONY: all clean fclean re
