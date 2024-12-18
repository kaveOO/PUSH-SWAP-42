/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:48:02 by albillie          #+#    #+#             */
/*   Updated: 2024/12/19 20:05:11 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <libft.h>
# include <limits.h>

typedef struct s_stacks
{
	int					stack_a;
	struct s_stacks		*next;
}						t_stacks;

void		args_checker(int argc, char **argv);
int			count_args(char *str);
void		check_chars(char *str);
void		free_array(char **array);
void		args_handler(int ac, char **av);
void		check_limits(char *str);
void		check_len(char *str);
t_stacks	*stack_lst_new(int data);
void		stack_add_back(t_stacks **list, t_stacks *data);
void		print_stack_list(t_stacks *list);
void		free_stack_list(t_stacks *list);
void		check_for_doubles(t_stacks *list);
void		exit_error(t_stacks *list);


#endif
