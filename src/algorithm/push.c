/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:19:10 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/21 19:28:52 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stacks **stack_a, t_stacks *stack_b)
{
	if (get_list_size(stack_b) < 2)
		return ;
	stack_add_front(stack_a, stack_lst_new(stack_b->data));
	stack_b = stack_b->next;
	stack_add_front(stack_a, stack_lst_new(stack_b->data));
}
void	ft_pb(t_stacks **stack_b, t_stacks *stack_a)
{
	if (get_list_size(stack_a) < 2)
		return ;
	stack_add_front(stack_b, stack_lst_new(stack_a->data));
	stack_a = stack_a->next;
	stack_add_front(stack_b, stack_lst_new(stack_a->data));
}
