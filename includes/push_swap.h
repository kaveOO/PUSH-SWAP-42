/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:48:02 by albillie          #+#    #+#             */
/*   Updated: 2024/12/25 01:43:21 by kaveo            ###   ########.fr       */
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
	int					data;
	int					temp;
	struct s_stacks		*next;
}						t_stacks;

// ? INIT FUNCTIONS

t_stacks	*init_a_stack(int ac, char **av);
t_stacks	*init_b_stack(t_stacks *stack_a);

// ? PARSING FUNCTIONS

void		is_valid_args(t_stacks *stack_a, int ac, char **av);
void		check_chars(t_stacks *stack_a, int ac, char **av);
void		check_limits(t_stacks *stack_a, int ac, char **av);
void		check_len(t_stacks *stack_a, int ac, char **av);
void		check_for_doubles(t_stacks *list);
void		check_if_sorted(t_stacks *stack_a);

// ? LISTS FUNCTIONS

t_stacks	*stack_lst_new(int data);
void		stack_add_back(t_stacks **list, t_stacks *data);
void		print_stack_list(t_stacks *list);
void		free_stack_list(t_stacks *list);
int			get_list_size(t_stacks *stack);
void		stack_add_front(t_stacks **stack, t_stacks *data);

// ? UTILS FUNCTIONS

void	exit_handler(t_stacks *stack_a, t_stacks *stack_b, int i);

// ? SORTING FUNCTIONS

void	sort_list(t_stacks *stack_a);
void	sort_3_digits(t_stacks **stack_a);
void	sort_4_digits(t_stacks **stack_a);

// ? INSTRUCTIONS

void	ft_sa(t_stacks *stack_a);
void	ft_sb(t_stacks *stack_b);
void	ft_ss(t_stacks *stack_a, t_stacks *stack_b);
void	ft_pa(t_stacks **stack_a, t_stacks **stack_b);
void	ft_pb(t_stacks **stack_b, t_stacks **stack_a);
void	ft_ra(t_stacks **stack_a, bool both);
void	ft_rb(t_stacks **stack_b, bool both);
void	ft_rr(t_stacks **stack_a, t_stacks **stack_b);
void	ft_rra(t_stacks **stack_a, bool both);
void	ft_rrb(t_stacks **stack_b, bool both);
void	ft_rrr(t_stacks **stack_a, t_stacks **stack_b);

#endif
