# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albillie <albillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 10:45:16 by albillie          #+#    #+#              #
#    Updated: 2024/12/06 01:27:55 by albillie         ###   ########.fr        #
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

SRC		=	src/main.c		\
			src/parsing.c	\

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
