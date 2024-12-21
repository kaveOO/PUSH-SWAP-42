/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:21:36 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/21 19:20:29 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(int ac, t_stacks *stack_a, t_stacks *stack_b)
{
	stack_b = stack_lst_new(4);
	stack_add_back(&stack_b, stack_lst_new(3));
	(void) ac;
	if (ac == 3)
		ft_sa(stack_a);
	ft_pa(&stack_a, stack_b);
	print_stack_list(stack_a);
	ft_printf("\n");
	ft_pb(&stack_b, stack_a);
	print_stack_list(stack_b);
}
