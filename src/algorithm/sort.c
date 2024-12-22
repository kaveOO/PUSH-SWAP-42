/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:21:36 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/22 18:13:55 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_stacks *stack_a, t_stacks *stack_b)
{
	stack_b = stack_lst_new(2);
	stack_add_back(&stack_b, stack_lst_new(3));
	stack_add_back(&stack_b, stack_lst_new(1));
	stack_add_back(&stack_b, stack_lst_new(-5));
	stack_add_back(&stack_b, stack_lst_new(6));
	if (get_list_size(stack_a) == 2)
		return (ft_sa(stack_a));
	ft_rr(&stack_a, &stack_b);
	print_stack_list(stack_b);
	ft_printf("\n");
	print_stack_list(stack_a);
}
