/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:57:06 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/01 17:36:23 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stacks **stack_a, bool both)
{
	t_stacks	*last;
	t_stacks	*prev_last;

	last = (*stack_a);
	if (get_list_size(*stack_a) < 2)
		return ;
	prev_last = NULL;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = (*stack_a);
	(*stack_a) = last;
	if (!both)
		ft_printf("rra\n");
}

void	ft_rrb(t_stacks **stack_b, bool both)
{
	t_stacks	*last;
	t_stacks	*prev_last;

	last = (*stack_b);
	if (get_list_size(*stack_b) < 2)
		return ;
	prev_last = NULL;
	if (!last->next)
		return ;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = (*stack_b);
	(*stack_b) = last;
	if (!both)
		ft_printf("rrb\n");
}

void	ft_rrr(t_stacks **stack_a, t_stacks **stack_b)
{
	ft_rra(stack_a, true);
	ft_rrb(stack_b, true);
	ft_printf("rrr\n");
}
