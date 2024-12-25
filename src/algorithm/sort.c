/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:21:36 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/25 18:54:29 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO Have to work on B stack init when having more than 3 digits because we have to use it

void	sort_list(t_stacks *stack_a)
{
	t_stacks	*stack_b;

	(void) stack_b;
	if (get_list_size(stack_a) == 2)
		ft_sa(stack_a);
	else if (get_list_size(stack_a) == 3)
		sort_3_digits(&stack_a);
	stack_b = init_b_stack(stack_a);
	ft_pa(&stack_a, &stack_b);
	ft_pa(&stack_a, &stack_b);
	ft_pb(&stack_b, &stack_a);
	// else if (get_list_size(stack_a) > 3)
	// {
	// 	stack_b = init_b_stack(stack_a);
	// }m
	// ft_pa(&stack_a, &stack_b);
	print_stack_list(stack_a);
	ft_printf("\n");
	print_stack_list(stack_b);
	// free_stack_list(stack_b);
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
		ft_sa(*stack_a);
	}
}

/* void	normal_sort(t_stacks **stack_a)
{




} */
