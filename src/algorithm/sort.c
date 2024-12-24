/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:21:36 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/25 00:01:34 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_stacks *stack_a, t_stacks *stack_b)
{
	stack_b->data = 0;
	stack_b->next = NULL;
	// stack_add_back(&stack_b, stack_lst_new(1));
	// stack_add_back(&stack_b, stack_lst_new(-5));
	// stack_add_back(&stack_b, stack_lst_new(6));
	if (get_list_size(stack_a) == 2)
		ft_sa(stack_a);
	if (get_list_size(stack_a) == 3)
		sort_3_digits(&stack_a);
	// ft_pb(&stack_b, &stack_a);
	// ft_sa(stack_a);
	// ft_rra(&stack_a, false);

	print_stack_list(stack_a);
	// ft_printf("\n");
	// print_stack_list(stack_b);
}

void	sort_3_digits(t_stacks **stack_a)
{
	if (((*stack_a)->data > (*stack_a)->next->data) &&
		((*stack_a)->data > (*stack_a)->next->next->data))
	{
		ft_ra(stack_a, false);
	}
	else if ((*stack_a)->next->data > (*stack_a)->data && (*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		ft_rra(stack_a, false);
	}
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		ft_sa(*stack_a);
	}
}
