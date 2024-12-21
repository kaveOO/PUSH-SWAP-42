/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:20:16 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/21 10:43:20 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stacks *stack_a)
{
	if (get_list_size(stack_a) < 2)
		return ;
	stack_a->temp = stack_a->data;
	stack_a->data = stack_a->next->data;
	stack_a->next->data = stack_a->temp;
	ft_printf("sa\n");
	ft_printf("%d %d\n", stack_a->data, stack_a->next->data);
}

void	ft_sb(t_stacks *stack_b)
{
	if (get_list_size(stack_b) < 2)
		return ;
	stack_b->temp = stack_b->data;
	stack_b->data = stack_b->next->data;
	stack_b->next->data = stack_b->temp;
	ft_printf("sb\n");
	ft_printf("%d %d\n", stack_b->data, stack_b->next->data);
}

void	ft_ss(t_stacks *stack_a, t_stacks *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
	ft_printf("ss\n");
}
