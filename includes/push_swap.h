/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:48:02 by albillie          #+#    #+#             */
/*   Updated: 2024/12/07 06:39:37 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <libft.h>

typedef struct s_parsed
{
	int	numbers;
	struct s_parsed	*next;
}	t_parsed;

typedef struct s_stacks
{
	int		stack_a;
	struct	s_stacks * next;
}	t_stacks;

void	args_checker(t_parsed *parsed, int argc, char **argv);
int		count_args(char *str);
bool	check_chars(char *str);
void	get_numbers(t_parsed *parsed, char *str);
void	free_array(char **array);
void	insert_integers(int nb);

#endif
