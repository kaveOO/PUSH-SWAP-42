/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:48:53 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/22 16:20:42 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks **stack_a)
{
	t_stacks	*ptr;

	ptr = (*stack_a);
	stack_add_back(stack_a, stack_lst_new(ptr->data));
	(*stack_a) = ptr->next;
}

void	ft_rb(t_stacks *stack_a)
{


}

// void	ft_rr(t_stacks *stack_a)
// {



// }
