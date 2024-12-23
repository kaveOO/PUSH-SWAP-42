/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:48:53 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/23 22:32:27 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks **stack_a, bool both)
{
	t_stacks	*ptr;

	ptr = (*stack_a);
	if (!ptr)
		return ;
	stack_add_back(&ptr, stack_lst_new(ptr->data));
	(*stack_a) = (*stack_a)->next;
	if (!both)
		ft_printf("ra\n");
}

void	ft_rb(t_stacks **stack_b, bool both)
{
	t_stacks	*ptr;

	ptr = (*stack_b);
	if (!ptr)
		return ;
	stack_add_back(&ptr, stack_lst_new(ptr->data));
	(*stack_b) = (*stack_b)->next;
	if (!both)
		ft_printf("rb\n");
}

/* void	ft_rr(t_stacks *stack_a, t_stacks *stack_b)
{
	ft_ra(stack_a, true);
	ft_rb(stack_b, true);
	ft_printf("rr\n");
} */
