/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:21:36 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/21 10:42:59 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(int ac, t_stacks *stack_a, t_stacks *stack_b)
{
	stack_b = stack_lst_new(2);
	stack_add_back(&stack_b, stack_lst_new(1));
	if (ac == 3)
		ft_sa(stack_a);
	ft_sb(stack_b);
}
