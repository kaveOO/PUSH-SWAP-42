/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:19:10 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/24 15:47:37 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*ptr;

	if (get_list_size((*stack_b)) < 1)
		return ;
	ptr = malloc(sizeof(t_stacks));
	ptr->data = (*stack_b)->data;
	ptr->next = (*stack_a);
	(*stack_a) = ptr;
	(*stack_b) = (*stack_b)->next;
}
void	ft_pb(t_stacks **stack_b, t_stacks **stack_a)
{
	t_stacks	*ptr;

	if (get_list_size((*stack_a)) < 1)
		return ;
	ptr = malloc(sizeof(t_stacks));
	ptr->data = (*stack_a)->data;
	ptr->next = (*stack_b);
	(*stack_b) = ptr;
	(*stack_a) = (*stack_a)->next;
}
