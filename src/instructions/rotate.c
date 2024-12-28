/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:48:53 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/28 10:14:55 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks **stack_a, bool both)
{
	t_stacks	*temp;

	if (get_list_size((*stack_a)) < 2)
		return ;
	stack_add_back(stack_a, stack_lst_new((*stack_a)->data));
	temp = (*stack_a);
	(*stack_a) = temp->next;
	free(temp);
	if (!both)
		ft_printf("ra\n");
}

void	ft_rb(t_stacks **stack_b, bool both)
{
	t_stacks	*temp;

	if (get_list_size((*stack_b)) < 2)
		return ;
	stack_add_back(stack_b, stack_lst_new((*stack_b)->data));
	temp = (*stack_b);
	(*stack_b) = temp->next;
	free(temp);
	if (!both)
		ft_printf("rb\n");
}

void	ft_rr(t_stacks **stack_a, t_stacks **stack_b)
{
	ft_ra(stack_a, true);
	ft_rb(stack_b, true);
	ft_printf("rr\n");
}

