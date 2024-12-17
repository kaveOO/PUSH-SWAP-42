/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:48:02 by albillie          #+#    #+#             */
/*   Updated: 2024/12/17 19:24:30 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <libft.h>
#include <limits.h>

typedef struct s_stacks
{
	int					data;
	struct s_stacks		*next;
}						t_stacks;

void		args_checker(int argc, char **argv);
int			count_args(char *str);
bool		check_chars(char *str);
void		write_error();
void		free_array(char **array);
int			*fill_array(int ac, char **av);
void		args_handler(int ac, char **av);
int			args_counter(int ac);



#endif
