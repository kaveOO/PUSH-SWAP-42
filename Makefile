# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albillie <albillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 00:18:47 by albillie          #+#    #+#              #
#    Updated: 2024/12/31 14:23:57 by albillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g $(INCLUDE)
INCLUDE	=	-I includes -I libft
CLONE	=	git clone
RM		=	rm -f

LIB		=	libft
LIBFT	=	$(LIB)/libft.a

SRC		=	src/instructions/push.c \
			src/instructions/rotate.c \
			src/instructions/r_rotate.c \
			src/instructions/swap.c \
			src/core/inits.c \
			src/core/main.c \
			src/algorithm/sort.c \
			src/algorithm/chunks_sort.c \
			src/parsing/is_valid_args.c \
			src/utils/chunk_array.c		\
			src/utils/handling.c		\
			src/utils/lists.c		\
			src/utils/parsing.c		\
			src/utils/chunks.c		\
			src/utils/find.c		\
			src/utils/sort.c		\


OBJ 		= $(SRC:.c=.o)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIB):
	$(CLONE) https://github.com/kaveOO/LIB-PROJECTS.git $(LIB)

$(LIBFT): $(LIB)
		$(MAKE) -C $(LIB)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(LIB)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(LIB)

re: fclean all

.PHONY:		all clean fclean re
