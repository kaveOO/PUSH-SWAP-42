/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:19:10 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/29 21:51:05 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*temp;

	if (get_list_size((*stack_b)) < 1)
	{
		ft_printf("test");
		return ;
	}
	stack_add_front(stack_a, stack_lst_new((*stack_b)->data));
	temp = (*stack_b);
	(*stack_b) = temp->next;
	free(temp);
	ft_printf("pa\n");
}
void	ft_pb(t_stacks **stack_b, t_stacks **stack_a)
{
	t_stacks	*temp;

	if (!stack_b)
		*stack_b = *stack_a;
	if (get_list_size((*stack_a)) < 1)
		return ;
	stack_add_front(stack_b, stack_lst_new((*stack_a)->data));
	temp = (*stack_a);
	(*stack_a) = temp->next;
	free(temp);
	ft_printf("pb\n");
}
