/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:20:16 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/28 02:24:50 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stacks *stack_a, bool both)
{
	t_stacks	*temp;

	if (get_list_size(stack_a) < 2)
		return ;
	temp = malloc(sizeof(t_stacks));
	temp->data = stack_a->data;
	stack_a->data = stack_a->next->data;
	stack_a->next->data = temp->data;
	free(temp);
	if (!both)
		ft_printf("sa\n");
}

void	ft_sb(t_stacks *stack_b, bool both)
{
	t_stacks	*temp;

	if (get_list_size(stack_b) < 2)
		return ;
	temp = malloc(sizeof(t_stacks));
	temp->data = stack_b->data;
	stack_b->data = stack_b->next->data;
	stack_b->next->data = temp->data;
	free(temp);
	if (!both)
		ft_printf("sb\n");
}

void	ft_ss(t_stacks *stack_a, t_stacks *stack_b)
{
	ft_sa(stack_a, true);
	ft_sb(stack_b, true);
	ft_printf("ss\n");
}
