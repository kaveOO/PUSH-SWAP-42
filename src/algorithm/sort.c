/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:21:36 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/28 06:03:47 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_stacks *stack_a, t_stacks *stack_b)
{
	(void) stack_b;
	if (get_list_size(stack_a) == 2)
		ft_sa(stack_a, false), exit_handler(stack_a, stack_b, 0);
	else if (get_list_size(stack_a) == 3)
		sort_3_digits(&stack_a), exit_handler(stack_a, stack_b, 0);
	else if (get_list_size(stack_a) > 3)
	{
		fill_sort_array(&stack_a);
		// pre_sort_stack(&stack_a);
		// print_stack_list(stack_a);
	}
}

void	sort_3_digits(t_stacks **stack_a)
{
	if (((*stack_a)->data > (*stack_a)->next->data) &&
		((*stack_a)->data > (*stack_a)->next->next->data))
	{
		ft_ra(stack_a, false);
	}
	else if ((*stack_a)->next->data > (*stack_a)->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		ft_rra(stack_a, false);
	}
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		ft_sa(*stack_a, false);
	}
}

/* void	normal_sort(t_stacks **stack_a)
{




} */
