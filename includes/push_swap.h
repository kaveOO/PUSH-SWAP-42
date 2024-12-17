/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:48:02 by albillie          #+#    #+#             */
/*   Updated: 2024/12/16 16:07:46 by albillie         ###   ########.fr       */
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

void	args_checker(t_stacks *stack, int argc, char **argv);
int		count_args(char *str);
bool	check_chars(char *str);
void	write_error();
void	free_array(char **array);
void	check_when_args(t_stacks *stack, char *str);
void	print_list(t_stacks *stack);
t_stacks	*ft_lstnew_scam(long content);
void	ft_lstadd_back_scam(t_stacks **lst, t_stacks *new);


#endif
