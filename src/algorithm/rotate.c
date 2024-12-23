/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:48:53 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/23 15:59:28 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks *stack_a)
{
	t_stacks	*ptr;

	ptr = stack_a;
	if (!ptr)
		return ;
	stack_add_back(&stack_a, stack_lst_new(ptr->data));
	stack_a = ptr->next;
	ft_printf("ra\n");
}

void	ft_rb(t_stacks *stack_b)
{
	t_stacks	*ptr;

	ptr = stack_b;
	if (!ptr)
		return ;
	stack_add_back(&stack_b, stack_lst_new(ptr->data));
	stack_b = ptr->next;
	ft_printf("rb\n");
}

void	ft_rr(t_stacks *stack_a, t_stacks *stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
	ft_printf("rr\n");
}
