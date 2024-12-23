/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:21:36 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/23 22:46:37 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_head(t_stacks **stack_a)
{
	(*stack_a) = (*stack_a)->next;
}
void	sort_list(t_stacks *stack_a, t_stacks *stack_b)
{
	stack_b->data = 2;
	stack_b->next = NULL;
	stack_add_back(&stack_b, stack_lst_new(3));
	stack_add_back(&stack_b, stack_lst_new(1));
	stack_add_back(&stack_b, stack_lst_new(-5));
	stack_add_back(&stack_b, stack_lst_new(6));
	if (get_list_size(stack_a) == 2)
		ft_sa(stack_a);
	// if (get_list_size(stack_a) == 3)
		// sort_3_digits(&stack_a);
	ft_rb(&stack_b, false);
	// change_head(&stack_a);
	print_stack_list(stack_b);
}


void	sort_3_digits(t_stacks **stack_a)
{
	int temp;

	if ((*stack_a)->data > (*stack_a)->next->next->data)
	{
		ft_ra(stack_a, false);
		return ;
	}
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		ft_sa((*stack_a));
		ft_ra(stack_a, false);
	}
	if ((*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		temp = (*stack_a)->next->data;
		(*stack_a)->next->data = (*stack_a)->next->next->data;
		(*stack_a)->next->next->data = temp;
	}

}
