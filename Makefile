# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 00:18:47 by albillie          #+#    #+#              #
#    Updated: 2024/12/20 07:27:42 by kaveo            ###   ########.fr        #
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

SRC		=	src/parsing/check_args.c	\
			src/parsing/if_args.c		\
			src/parsing/utils.c			\
			src/parsing/list_utils.c	\
			src/main.c					\
			src/utils.c					\

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
