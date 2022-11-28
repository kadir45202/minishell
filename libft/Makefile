# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eayyildi <ayyildiz_enes66@hotmail.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 10:28:33 by eayyildi          #+#    #+#              #
#    Updated: 2022/10/31 13:13:24 by eayyildi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Aliases

NAME		= libft.a
SRC_MAIN_DIR		= ./src
SRC_A_DIR		= ./srca
SRC_B_DIR		= ./srcb
OBJS_MAIN_DIR		= ./src_objs
OBJS_A_DIR		= ./srca_objs
OBJS_B_DIR		= ./srcb_objs
INC	= ./inc
# Make variables

SRC_MAIN =	ft_atoi.c ft_bzero.c	\
	ft_calloc.c ft_putendl_fd.c		\
	ft_itoa.c ft_putchar_fd.c		\
	ft_putstr_fd.c ft_memccpy.c		\
	ft_memchr.c ft_memcmp.c			\
	ft_memcpy.c ft_isalnum.c		\
	ft_isalpha.c ft_isascii.c		\
	ft_isdigit.c ft_isprint.c		\
	ft_memmove.c ft_memset.c		\
	ft_split.c ft_strchr.c			\
	ft_strdup.c ft_strjoin.c		\
	ft_strlcat.c ft_strlcpy.c		\
	ft_strlen.c ft_strmapi.c		\
	ft_strncmp.c ft_strnstr.c		\
	ft_strrchr.c ft_strtrim.c		\
	ft_substr.c ft_tolower.c		\
	ft_toupper.c ft_putnbr_fd.c		

SRCB = ft_lstadd_back.c	\
	ft_lstadd_front.c	\
	ft_lstclear.c		\
	ft_lstdelone.c		\
	ft_lstiter.c		\
	ft_lstlast.c		\
	ft_lstsize.c		\
	ft_lstnew.c			\
	ft_lstmap.c			\
	ft_lstget_at.c

SRCA =	\
	ft_isspace.c	\
	ft_countchar.c	\
	ft_atoi2.c			\
	ft_free_matrix.c ft_dup_matrix.c			\
	ft_strchr_i.c ft_putmatrix_fd.c				\
	ft_matrixlen.c ft_strchars_i.c				\
	ft_subsplit.c			\
	ft_nbrlen.c				\
	ft_extend_matrix.c 	\
	ft_matrix_replace_in.c		\
	get_next_line.c get_next_line_utils.c
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

OBJS		= $(SRC_MAIN:%.c=$(OBJS_MAIN_DIR)/%.o)
OBJS_A      =	$(SRCA:%.c=$(OBJS_A_DIR)/%.o)
OBJS_B      =	$(SRCB:%.c=$(OBJS_B_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_A) $(OBJS_B)
	@echo "Linking $@"
	@ar rc $(NAME) $(OBJS) $(OBJS_A) $(OBJS_B)
	@echo "Done!"

$(OBJS): $(OBJS_MAIN_DIR)/%.o: $(SRC_MAIN_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJS_A): $(OBJS_A_DIR)/%.o: $(SRC_A_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJS_B): $(OBJS_B_DIR)/%.o: $(SRC_B_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
	
clean:
	rm -rf $(OBJS_MAIN_DIR) $(OBJS_A_DIR) $(OBJS_B_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: all
	./$(NAME)

.PHONY: all clean fclean re test